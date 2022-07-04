package it.unibo.esiot.smartgarden.service.commchannel;

import jssc.*;

public class ShowSerialPorts {

	public static void main(String[] args) {
		/* detect serial ports */
		String[] portNames = SerialPortList.getPortNames();
		for (String portName : portNames) {
			System.out.println(portName);
		}
	}

}
