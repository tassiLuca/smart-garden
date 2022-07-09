package it.unibo.esiot.smartgarden.service.model;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SmartGardenImpl implements SmartGarden {

    private static final int MAX_SIZE = 15;
    private GardenState state = GardenState.AUTO;
    private final List<DataPoint> dataPoints = new ArrayList<>();

    @Override
    public String getState() {
        return state.getStateDescription();
    }

    @Override
    public void changeState(GardenState newState) {
        this.state = newState;
    }

    @Override
    public void addNewDataPoint(final DataPoint data) {
        if (dataPoints.size() == MAX_SIZE) {
            dataPoints.remove(0);
        }
        dataPoints.add(data);
    }

    public List<DataPoint> getDataPoints() {
        return Collections.unmodifiableList(this.dataPoints);
    }

}
