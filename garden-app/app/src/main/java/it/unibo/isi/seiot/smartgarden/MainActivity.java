package it.unibo.isi.seiot.smartgarden;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.SwitchCompat;
import androidx.core.app.ActivityCompat;

import java.util.List;
import java.util.UUID;
import java.util.function.Function;

import it.unibo.isi.seiot.smartgarden.utils.C;
import unibo.btlib.BluetoothChannel;
import unibo.btlib.BluetoothUtils;
import unibo.btlib.ConnectToBluetoothServerTask;
import unibo.btlib.ConnectionTask;
import unibo.btlib.RealBluetoothChannel;
import unibo.btlib.exceptions.BluetoothDeviceNotFound;

public class MainActivity extends AppCompatActivity {

    private static final String DBG_TAG = "esiot";
    private static final String DEFAULT_COUNTERS_LABEL = "0";
    private static final String AUTO_BTN_STRING = "Auto Control";
    private static final String MANUAL_BTN_STRING = "Manual Control";
    private static final String BT_DEVICE_NOT_FOUND_ERROR = "Bluetooth device not found !";
    private BluetoothChannel btChannel;
    private final Function<Integer, Integer> incLightnessStrategy = (c -> c+5);
    private final Function<Integer, Integer> decLightnessStrategy = (c -> c-5);
    private final Function<Integer, Integer> incIrrigationStrategy = (c -> c+1);
    private final Function<Integer, Integer> decIrrigationStrategy = (c -> c-1);


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        final BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();
        if (btAdapter != null && !btAdapter.isEnabled()) {
            if (ActivityCompat.checkSelfPermission(
                    this,
                    Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED) {
                Log.d(DBG_TAG, "[ERROR] no bluetooth permissions!");
                return;
            }
            startActivityForResult(new Intent(
                    BluetoothAdapter.ACTION_REQUEST_ENABLE),
                    C.bluetooth.ENABLE_BT_REQUEST);
        }
        initUI();
    }

    private void initUI() {
        findViewById(R.id.manualControlBtn).setEnabled(false);
        disableAllButtons();
        findViewById(R.id.manualControlBtn).setOnClickListener(this::onManualBtnClicked);
        findViewById(R.id.connectBtn).setOnClickListener(this::onConnectBtnClicked);
        findViewById(R.id.ledSwitch1).setOnClickListener(l ->
                onSwitchPressed(R.id.ledSwitch1, "LED1"));
        findViewById(R.id.ledSwitch2).setOnClickListener(l ->
                onSwitchPressed(R.id.ledSwitch2, "LED2"));
        findViewById(R.id.incLed3Btn).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed3, "LED3", incLightnessStrategy));
        findViewById(R.id.decLed3Btn).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed3, "LED3", decLightnessStrategy));
        findViewById(R.id.incLed4Btn).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed4, "LED4", incLightnessStrategy));
        findViewById(R.id.decLed4Btn).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed4, "LED4", decLightnessStrategy));
        findViewById(R.id.incIrrigationBtn).setOnClickListener(l ->
                onBtnPressed(R.id.counterIrrigation, "IRR-SPEED", incIrrigationStrategy));
        findViewById(R.id.decIrrigationBtn).setOnClickListener(l ->
                onBtnPressed(R.id.counterIrrigation, "IRR-SPEED", decIrrigationStrategy));
        findViewById(R.id.irrigationSwitch).setOnClickListener(l ->
                onSwitchPressed(R.id.irrigationSwitch, "IRRIGATION"));
        findViewById(R.id.alarmBtn).setOnClickListener(l ->
                sendData("SET-STATE", "AUTO"));
    }

    private void onSwitchPressed(final int textViewId, final String desc) {
        final SwitchCompat sc = findViewById(textViewId);
        sendData(desc, sc.isChecked() ? 1 : 0);
    }

    private void onBtnPressed(final int textViewId, final String desc, final Function<Integer, Integer> fun) {
        final TextView textView = findViewById(textViewId);
        final int newValue = clip(fun.apply(Integer.parseInt(textView.getText().toString())), 0, 255);
        textView.setText(Integer.toString(newValue));
        sendData(desc, newValue);
    }

    private int clip(final int actualValue, final int minValue, final int maxValue) {
        return actualValue < minValue ? minValue : Math.min(actualValue, maxValue);
    }

    private void onConnectBtnClicked(final View view) {
        view.setEnabled(false);
        try {
            connectToBTServer();
        } catch (BluetoothDeviceNotFound bluetoothDeviceNotFound) {
            Toast.makeText(this, BT_DEVICE_NOT_FOUND_ERROR, Toast.LENGTH_LONG).show();
            bluetoothDeviceNotFound.printStackTrace();
        } finally {
            view.setEnabled(true);
        }
    }

    private void onManualBtnClicked(final View view) {
        resetCounterLabels();
        resetSwitchState();
        if (((Button) view).getText().toString().equals(MANUAL_BTN_STRING)) {
            ((Button) view).setText(AUTO_BTN_STRING);
            enableAllButtons();
            btChannel.sendMessage("SET-STATE:MANUAL");
        } else {
            ((Button) view).setText(MANUAL_BTN_STRING);
            disableAllButtons();
            btChannel.sendMessage("SET-STATE:AUTO");
        }
    }

    private void resetCounterLabels() {
        final var counters = List.of(R.id.counterIrrigation,
                R.id.counterLed3, R.id.counterLed4);
        counters.forEach(c -> ((TextView) findViewById(c)).setText(DEFAULT_COUNTERS_LABEL));
    }

    private void resetSwitchState() {
        final var switches = List.of(R.id.irrigationSwitch,
                R.id.ledSwitch2, R.id.ledSwitch1);
        switches.forEach(s -> ((SwitchCompat) findViewById(s)).setChecked(false));
    }

    private void controlButtons(final boolean active) {
        final var buttons = List.of(R.id.ledSwitch1,
                R.id.ledSwitch2, R.id.incLed3Btn, R.id.incLed4Btn,
                R.id.decLed3Btn, R.id.decLed4Btn, R.id.irrigationSwitch,
                R.id.incIrrigationBtn, R.id.decIrrigationBtn);
        buttons.forEach(id -> findViewById(id).setEnabled(active));
    }

    private void enableAllButtons() { controlButtons(true); }

    private void disableAllButtons() { controlButtons(false); }

    private void sendData(final String desc, final Object obj) {
        final String msg = desc + ":" + obj;
        btChannel.sendMessage(msg);
    }

    private void connectToBTServer() throws BluetoothDeviceNotFound {
        final BluetoothDevice serverDevice = BluetoothUtils
                .getPairedDeviceByName(C.bluetooth.BT_DEVICE_ACTING_AS_SERVER_NAME);

        final UUID uuid = BluetoothUtils.getEmbeddedDeviceDefaultUuid();

        new ConnectToBluetoothServerTask(serverDevice, uuid, new ConnectionTask.EventListener() {
            @Override
            public void onConnectionActive(final BluetoothChannel channel) {
                Toast.makeText(getApplicationContext(),"Connected", Toast.LENGTH_LONG).show();
                findViewById(R.id.manualControlBtn).setEnabled(true);

                btChannel = channel;
                btChannel.registerListener(new RealBluetoothChannel.Listener() {
                    @Override
                    public void onMessageReceived(String receivedMessage) {
                        Log.d(DBG_TAG, "RECEIVED: " + receivedMessage);
                        ((TextView)findViewById(R.id.gardenState)).setText(receivedMessage);
                    }

                    @Override
                    public void onMessageSent(String sentMessage) {
                        Log.d(DBG_TAG, sentMessage);
                    }
                });
            }

            @Override
            public void onConnectionCanceled() {
                findViewById(R.id.manualControlBtn).setEnabled(false);
                resetCounterLabels();
            }
        }).execute();
    }

}
