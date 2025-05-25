package com.pumps.utils;

public class RotaryPump extends Pump {
	@Override
    public double calculateFlow(PumpConditions conditions) {
        return conditions.getFlowRate() * conditions.getEfficiency();
    }
}
