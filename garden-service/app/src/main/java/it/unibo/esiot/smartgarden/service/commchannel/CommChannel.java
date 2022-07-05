package it.unibo.esiot.smartgarden.service.commchannel;

/**
 * Simple interface for an async msg communication channel
 */
public interface CommChannel {
	
	/**
	 * Send a message represented by a string (without new line).
	 * Asynchronous model.
	 * @param msg the message to send
	 */
	void sendMsg(String msg);
	
	/**
	 * To receive a message.
	 * **NOTE**: Blocking behaviour.
	 */
	String receiveMsg() throws InterruptedException;

	/**
	 * To check if a message is available.
	 * @return true if a message is available, false otherwise
	 */
	boolean isMsgAvailable();

}
