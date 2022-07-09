package unibo.btclient;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.SwitchCompat;
import android.util.Log;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;
import java.util.UUID;
import java.util.function.Function;

import unibo.btlib.BluetoothChannel;
import unibo.btlib.BluetoothUtils;
import unibo.btlib.ConnectToBluetoothServerTask;
import unibo.btlib.ConnectionTask;
import unibo.btlib.RealBluetoothChannel;
import unibo.btlib.exceptions.BluetoothDeviceNotFound;
import unibo.btclient.utils.C;

public class MainActivity extends AppCompatActivity {
    private BluetoothChannel btChannel;
    private final List<Integer> buttons = List.of(R.id.manualControlBtn, R.id.ledSwitch1,
            R.id.ledSwitch2, R.id.btnIncCounterLed3, R.id.btnIncCounterLed4, R.id.btnDecCounterLed3,
            R.id.btnDecCounterLed4, R.id.switchIrrigation, R.id.btnIncIrrigationSpeed,
            R.id.btnDecIrrigationSpeed);

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();
        if (btAdapter != null && !btAdapter.isEnabled()) {
            if (ActivityCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED) {
                // TODO: Consider calling
                //    ActivityCompat#requestPermissions
                // here to request the missing permissions, and then overriding
                //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
                //                                          int[] grantResults)
                // to handle the case where the user grants the permission. See the documentation
                // for ActivityCompat#requestPermissions for more details.
                return;
            }
            startActivityForResult(
                    new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE),
                    C.bluetooth.ENABLE_BT_REQUEST
            );
        }
        initUI();
    }

    private void initUI() {
        enableDisableComponents(false);
        resetCounters();
        findViewById(R.id.connectBtn).setOnClickListener(l -> {
            l.setEnabled(false);
            try {
                connectToBTServer();
            } catch (BluetoothDeviceNotFound bluetoothDeviceNotFound) {
                Toast.makeText(this, "Device not found!", Toast.LENGTH_LONG).show();
                bluetoothDeviceNotFound.printStackTrace();
            } finally {
                l.setEnabled(true);
            }
        });
        findViewById(R.id.manualControlBtn).setOnClickListener(l -> {
            if (((Button)findViewById(R.id.manualControlBtn)).getText().toString().equals("MANUAL CONTROL")) {
                ((Button)findViewById(R.id.manualControlBtn)).setText("AUTO CONTROL");
                btChannel.sendMessage("SET-STATE:AUTO");
            } else {
                ((Button)findViewById(R.id.manualControlBtn)).setText("MANUAL CONTROL");
                btChannel.sendMessage("SET-STATE:MANUAL");
            }
        });
        findViewById(R.id.ledSwitch1).setOnClickListener(l -> onSwitchPressed(R.id.ledSwitch1, "LED1"));
        findViewById(R.id.ledSwitch2).setOnClickListener(l -> onSwitchPressed(R.id.ledSwitch2, "LED2"));
        findViewById(R.id.btnIncCounterLed3).setOnClickListener(l -> onBtnPressed(R.id.counterLed3, "LED3", c -> c+5));
        findViewById(R.id.btnDecCounterLed3).setOnClickListener(l -> onBtnPressed(R.id.counterLed3, "LED3", c -> c-5));
        findViewById(R.id.btnIncCounterLed4).setOnClickListener(l -> onBtnPressed(R.id.counterLed4, "LED4", c -> c+5));
        findViewById(R.id.btnDecCounterLed4).setOnClickListener(l -> onBtnPressed(R.id.counterLed4, "LED4", c -> c-5));
        findViewById(R.id.btnIncIrrigationSpeed).setOnClickListener(l -> onBtnPressed(R.id.countIrrigation, "IRR-SPEED", c -> c+1));
        findViewById(R.id.btnDecIrrigationSpeed).setOnClickListener(l -> onBtnPressed(R.id.countIrrigation, "IRR-SPEED", c -> c-1));
        findViewById(R.id.switchIrrigation).setOnClickListener(l -> onSwitchPressed(R.id.switchIrrigation, "IRRIGATION"));
        findViewById(R.id.alertBtn).setOnClickListener(l -> sendData("SET-STATE", "AUTO"));
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
        return actualValue < minValue ? minValue : actualValue > maxValue ? maxValue : actualValue;
    }

    private void sendData(final String desc, final Object obj) {
        final String msg = desc + ":" + obj;
        btChannel.sendMessage(msg);
    }

    private void resetCounters() {
        List.of(R.id.counterLed3, R.id.counterLed4, R.id.countIrrigation).stream().forEach(t -> {
            TextView tv = findViewById(t);
            tv.setText("0");
        });
    }

    private void enableDisableComponents(final boolean enable) {
        for (int c : buttons) {
            findViewById(c).setEnabled(enable);
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
        btChannel.close();
    }

    @Override
    protected void onActivityResult(final int requestCode, final int resultCode,
                                    @Nullable final Intent data) {
        if (requestCode == C.bluetooth.ENABLE_BT_REQUEST && resultCode == RESULT_OK) {
            Log.d(C.APP_LOG_TAG, "Bluetooth enabled!");
        }

        if (requestCode == C.bluetooth.ENABLE_BT_REQUEST && resultCode == RESULT_CANCELED) {
            Log.d(C.APP_LOG_TAG, "Bluetooth not enabled!");
        }
    }

    private void connectToBTServer() throws BluetoothDeviceNotFound {
        final BluetoothDevice serverDevice = BluetoothUtils
                .getPairedDeviceByName(C.bluetooth.BT_DEVICE_ACTING_AS_SERVER_NAME);

        final UUID uuid = BluetoothUtils.getEmbeddedDeviceDefaultUuid();

        new ConnectToBluetoothServerTask(serverDevice, uuid, new ConnectionTask.EventListener() {
            @Override
            public void onConnectionActive(final BluetoothChannel channel) {
                Toast.makeText(getApplicationContext(),"Connected", Toast.LENGTH_LONG).show();
                enableDisableComponents(true);
                btChannel = channel;

                btChannel.registerListener(new RealBluetoothChannel.Listener() {
                    @Override
                    public void onMessageReceived(String receivedMessage) {

                    }

                    @Override
                    public void onMessageSent(String sentMessage) { }
                });
            }

            @Override
            public void onConnectionCanceled() {
                resetCounters();
                ((SwitchCompat) findViewById(R.id.ledSwitch1)).setChecked(false);
                ((SwitchCompat) findViewById(R.id.ledSwitch2)).setChecked(false);
                enableDisableComponents(false);
            }
        }).execute();
    }
}
