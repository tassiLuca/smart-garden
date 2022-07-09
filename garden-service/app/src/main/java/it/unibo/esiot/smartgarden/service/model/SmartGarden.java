package it.unibo.esiot.smartgarden.service.model;

import java.util.List;

/**
 * A simple interface representing the domain.
 */
public interface SmartGarden {

    enum GardenState {
        AUTO("Auto"),
        MANUAL("Manual"),
        ALARM("Alarm");

        private final String stateDescription;

        GardenState(final String stateDescription) {
            this.stateDescription = stateDescription;
        }

        public String getStateDescription() {
            return this.stateDescription;
        }
    }

    String getState();

    void changeState(final GardenState newState);

    void addNewDataPoint(final DataPoint data);

    List<DataPoint> getDataPoints();

}
