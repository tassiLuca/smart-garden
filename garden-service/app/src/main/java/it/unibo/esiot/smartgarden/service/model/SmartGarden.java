package it.unibo.esiot.smartgarden.service.model;

import java.util.Collection;

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

    /**
     * Get the state of the garden.
     * @return the {@link GardenState}
     */
    public String getState();

    public void changeState(final GardenState newState);

}
