package it.unibo.esiot.smartgarden.service.agents;

import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;

public final class SerialListener extends Thread {

    private final CommChannel channel;
    private final SmartGarden garden;

    public SerialListener(final CommChannel channel, final SmartGarden garden) {
        this.channel = channel;
        this.garden = garden;
    }

    public void run() {
        while(true) {
            String msg;
            try {
                msg = this.channel.receiveMsg();
                log("Actual State: " + msg);
                this.garden.changeState(
                        msg.equals("AUTO") ? SmartGarden.GardenState.AUTO :
                                msg.equals("MANUAL") ? SmartGarden.GardenState.MANUAL : SmartGarden.GardenState.ALARM
                );
            } catch (InterruptedException exception) {
                log("Error receive msg");
            }
        }
    }

    private void log(final String msg) {
        System.out.println("[SERIAL AGENT] " + msg);
    }

}
