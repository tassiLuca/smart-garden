package unibo.btclient;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.SwitchCompat;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.UUID;
import unibo.btlib.BluetoothChannel;
import unibo.btlib.BluetoothUtils;
import unibo.btlib.ConnectToBluetoothServerTask;
import unibo.btlib.ConnectionTask;
import unibo.btlib.RealBluetoothChannel;
import unibo.btlib.exceptions.BluetoothDeviceNotFound;
import unibo.btclient.utils.C;

public class MainActivity extends AppCompatActivity {
    private BluetoothChannel btChannel;
    private final int[] buttons = {R.id.ledSwitch1, R.id.ledSwitch2, R.id.btnIncCounterLed3,
            R.id.btnIncCounterLed4, R.id.btnDecCounterLed3, R.id.btnDecCounterLed4,
            R.id.switchIrrigation, R.id.btnIncIrrigationSpeed, R.id.btnDecIrrigationSpeed};

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();
        if (btAdapter != null && !btAdapter.isEnabled()) {
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
        findViewById(R.id.manualControl).setOnClickListener(l -> {
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
        findViewById(R.id.ledSwitch1).setOnClickListener(l ->
                onSwitchPressed(R.id.ledSwitch1, "LED1"));
        findViewById(R.id.ledSwitch2).setOnClickListener(l ->
                onSwitchPressed(R.id.ledSwitch2, "LED2"));
        findViewById(R.id.btnIncCounterLed3).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed3, "LED3", true));
        findViewById(R.id.btnDecCounterLed3).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed3, "LED3", false));
        findViewById(R.id.btnIncCounterLed4).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed4, "LED4", true));
        findViewById(R.id.btnDecCounterLed4).setOnClickListener(l ->
                onBtnPressed(R.id.counterLed4, "LED4", false));
        findViewById(R.id.btnIncIrrigationSpeed).setOnClickListener(l ->
                onBtnPressed(R.id.countIrrigation, "IRRIGATION", true));
        findViewById(R.id.btnDecIrrigationSpeed).setOnClickListener(l ->
                onBtnPressed(R.id.countIrrigation, "IRRIGATION", false));
        findViewById(R.id.switchIrrigation).setOnClickListener(l ->
                onSwitchPressed(R.id.switchIrrigation, "IRRIGATION"));
    }

    private void onSwitchPressed(final int textViewId, final String desc) {
        final SwitchCompat sc = findViewById(textViewId);
        sendData(desc, sc.isChecked() ? 1 : 0);
    }

    private void onBtnPressed(final int textViewId, final String desc, final boolean increment) {
        final TextView textView = findViewById(textViewId);
        final int newValue = Integer.parseInt(textView.getText().toString()) + (increment ? 1 : -1);
        textView.setText(Integer.toString(newValue));
        sendData(desc, newValue);
    }

    private void sendData(final String desc, final Object obj) {
        JSONObject json = new JSONObject();
        try {
            json.put(desc, obj);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        btChannel.sendMessage(json.toString());
    }

    private void resetCounters() {
        final int[] text = {R.id.counterLed3, R.id.counterLed4, R.id.countIrrigation};
        for (int t : text) {
            TextView tv = findViewById(t);
            tv.setText("0");
        }
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