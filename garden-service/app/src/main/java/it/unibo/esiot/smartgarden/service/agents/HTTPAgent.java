package it.unibo.esiot.smartgarden.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.http.HttpServerResponse;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.RoutingContext;
import io.vertx.ext.web.handler.BodyHandler;

/*
 * Data Service as a vertx event-loop 
 */
public class HTTPAgent extends AbstractVerticle {

	private static final String PATH = "/api/data";
	private final int port;

	public HTTPAgent(final int port) {
		this.port = port;
	}

	@Override
	public void start() {		
		Router router = Router.router(vertx);
		router.route().handler(BodyHandler.create());
		router.get(PATH).handler(this::handleGetData);
		vertx.createHttpServer().requestHandler(router).listen(port);
		log("Service ready.");
	}
	
	private void handleGetData(final RoutingContext routingContext) {
		log("get request");
	}

	private void log(final String msg) {
		System.out.println("[DATA SERVICE] " + msg);
	}

}