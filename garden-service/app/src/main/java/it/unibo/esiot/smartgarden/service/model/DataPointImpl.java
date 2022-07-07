package it.unibo.esiot.smartgarden.service.model;

public class DataPointImpl implements DataPoint {

    private final int temperature;
    private final int lightness;

    public DataPointImpl(final int temperature, final int lightness) {
        this.temperature = temperature;
        this.lightness = lightness;
    }

    @Override
    public int getTemperature() {
        return this.temperature;
    }

    @Override
    public int getLightness() {
        return this.lightness;
    }

}
