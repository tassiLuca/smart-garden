package it.unibo.esiot.smartgarden.service;

import io.vertx.core.Vertx;
import it.unibo.esiot.smartgarden.service.agents.HTTPAgent;
import it.unibo.esiot.smartgarden.service.agents.MQTTAgent;
import it.unibo.esiot.smartgarden.service.agents.SerialListener;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.commchannel.SerialCommChannel;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;
import it.unibo.esiot.smartgarden.service.model.SmartGardenImpl;

public class App {
    private final static String DEFAULT_PORT = "/dev/tty.usbmodem1201";
    private final static int RATE = 9600;
    private final static int HTTP_PORT = 8080;
    private static String portName = DEFAULT_PORT;

    public static void main(String[] args) throws Exception {
        if (args.length != 0) {
            portName = args[0];
        }
        CommChannel channel = new SerialCommChannel(portName, RATE);
        SmartGarden garden = new SmartGardenImpl();
        Vertx vertx = Vertx.vertx();
        MQTTAgent agent = new MQTTAgent(channel, garden);
        HTTPAgent service = new HTTPAgent(HTTP_PORT, garden);
        vertx.deployVerticle(agent);
        vertx.deployVerticle(service);
        new SerialListener(channel, garden).start();
    }
}
