package it.unibo.esiot.smartgarden.service;

import io.vertx.core.Vertx;
import it.unibo.esiot.smartgarden.service.agents.HTTPAgent;
import it.unibo.esiot.smartgarden.service.agents.MQTTAgent;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.commchannel.SerialCommChannel;

public class App {

    public static void main(String[] args) throws Exception {
        CommChannel channel = new SerialCommChannel("/dev/tty.usbmodem1201", 9600);
        Vertx vertx = Vertx.vertx();
        MQTTAgent agent = new MQTTAgent(channel);
        //HTTPAgent service = new HTTPAgent(80);
        vertx.deployVerticle(agent);
        //vertx.deployVerticle(service);
    }
}
