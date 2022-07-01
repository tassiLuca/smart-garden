package it.unibo.esiot.smartgarden.service.agents;

import io.netty.handler.codec.mqtt.MqttQoS;
import io.vertx.core.AbstractVerticle;
import io.vertx.core.buffer.Buffer;
import io.vertx.mqtt.MqttClient;

/*
 * MQTT Agent
 */
public class MQTTAgent extends AbstractVerticle {

	private static final String TOPIC = "esiot-2122";
	
	public MQTTAgent() { }

	@Override
	public void start() {		
		MqttClient client = MqttClient.create(vertx);
		client.connect(1883, "broker.mqtt-dashboard.com", c -> {
			log("connected");
			log("subscribing...");
			client.publishHandler(s -> {
				System.out.println("There are new message in topic: " + s.topicName());
				System.out.println("Content(as string) of the message: " + s.payload().toString());
				System.out.println("QoS: " + s.qosLevel());
			}).subscribe(TOPIC, 2);

			log("publishing a msg");
			client.publish(TOPIC, Buffer.buffer("hello"), MqttQoS.AT_LEAST_ONCE, false, false);
		});
	}

	private void log(final String msg) {
		System.out.println("[MQTT AGENT] "+msg);
	}

}