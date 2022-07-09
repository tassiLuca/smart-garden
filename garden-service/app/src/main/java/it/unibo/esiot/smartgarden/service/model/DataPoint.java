package it.unibo.esiot.smartgarden.service.model;

/**
 * A simple interface modeling an instant observation
 * of temperature and lightness values.
 */
public interface DataPoint {

    int getTemperature();

    int getLightness();

    String getTimeStamp();

}
