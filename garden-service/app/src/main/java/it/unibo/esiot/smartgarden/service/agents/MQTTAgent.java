package it.unibo.esiot.smartgarden.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.json.JsonObject;
import io.vertx.mqtt.MqttClient;
import io.vertx.mqtt.messages.MqttPublishMessage;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.model.DataPointImpl;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;

/*
 * MQTT Agent
 */
public class MQTTAgent extends AbstractVerticle {

	private static final String TOPIC = "esiot-smart-garden";
	private final CommChannel channel;

	private final SmartGarden garden;
	
	public MQTTAgent(CommChannel channel, SmartGarden garden) {
		this.channel = channel;
		this.garden = garden;
	}

	@Override
	public void start() {		
		MqttClient client = MqttClient.create(vertx);
		client.connect(1883, "broker.mqtt-dashboard.com", c -> {
			log("connected");
			log("subscribing...");
			client.publishHandler(this::responseHandler).subscribe(TOPIC, 2);
		});
	}

	private void responseHandler(final MqttPublishMessage msg) {
		final String receivedMsg = msg.payload().toString();
		log("New message in [" + msg.topicName() + " ]: " + receivedMsg);
		storeDataPoint(msg);
		log("Sending to Arduino the data");
		channel.sendMsg(receivedMsg);
		log("Waiting response from Arduino");
		try {
			final var res = channel.receiveMsg();
			this.garden.changeState(
					res.equals("AUTO") ? SmartGarden.GardenState.AUTO :
							res.equals("MANUAL") ? SmartGarden.GardenState.MANUAL : SmartGarden.GardenState.ALARM
			);
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
	}

	private void storeDataPoint(final MqttPublishMessage msg) {
		final JsonObject res = msg.payload().toJsonObject();
		final int temperature = res.getInteger("temperature");
		final int lightness = res.getInteger("lightness");
		this.garden.addNewDataPoint(new DataPointImpl(temperature, lightness));
	}

	private void log(final String msg) {
		System.out.println("[MQTT AGENT] "+msg);
	}

}