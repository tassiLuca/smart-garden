package it.unibo.esiot.smartgarden.service;

import io.vertx.core.Vertx;
import it.unibo.esiot.smartgarden.service.agents.HTTPAgent;
import it.unibo.esiot.smartgarden.service.agents.MQTTAgent;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.commchannel.SerialCommChannel;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;
import it.unibo.esiot.smartgarden.service.model.SmartGardenImpl;

public class App {

    public static void main(String[] args) throws Exception {
        CommChannel channel = new SerialCommChannel("/dev/tty.usbmodem1201", 9600);
        SmartGarden garden = new SmartGardenImpl();
        Vertx vertx = Vertx.vertx();
        MQTTAgent agent = new MQTTAgent(channel, garden);
        HTTPAgent service = new HTTPAgent(80, garden);
        vertx.deployVerticle(agent);
        vertx.deployVerticle(service);
    }
}
