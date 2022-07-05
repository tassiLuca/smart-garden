package it.unibo.esiot.smartgarden.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.mqtt.MqttClient;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;

/*
 * MQTT Agent
 */
public class MQTTAgent extends AbstractVerticle {

	private static final String TOPIC = "esiot-smart-garden";
	private CommChannel channel;
	
	public MQTTAgent(CommChannel channel) {
		this.channel = channel;
	}

	@Override
	public void start() {		
		MqttClient client = MqttClient.create(vertx);
		client.connect(1883, "broker.mqtt-dashboard.com", c -> {
			log("connected");
			log("subscribing...");
			client.publishHandler(s -> {
				final String receivedMsg = s.payload().toString();
				System.out.println("There are new message in topic: " + s.topicName());
				System.out.println("Content(as string) of the message: " + receivedMsg);
				// System.out.println("QoS: " + s.qosLevel());
				System.out.println("Sending to Arduino the received data");
				channel.sendMsg(receivedMsg);
			}).subscribe(TOPIC, 2);
		});
	}

	private void log(final String msg) {
		System.out.println("[MQTT AGENT] "+msg);
	}

}