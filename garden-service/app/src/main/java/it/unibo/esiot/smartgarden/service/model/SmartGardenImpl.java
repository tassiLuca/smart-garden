package it.unibo.esiot.smartgarden.service.model;

public class SmartGardenImpl implements SmartGarden {

    private GardenState state = GardenState.AUTO;

    @Override
    public String getState() {
        return state.getStateDescription();
    }

    @Override
    public void changeState(GardenState newState) {
        this.state = newState;
    }

}
