package it.unibo.esiot.smartgarden.service;

import io.vertx.core.Vertx;
import it.unibo.esiot.smartgarden.service.agents.HTTPAgent;
import it.unibo.esiot.smartgarden.service.agents.MQTTAgent;

public class App {

    public static void main(String[] args) {
        Vertx vertx = Vertx.vertx();
        MQTTAgent agent = new MQTTAgent();
        HTTPAgent service = new HTTPAgent(80);
        vertx.deployVerticle(agent);
        vertx.deployVerticle(service);
    }
}
