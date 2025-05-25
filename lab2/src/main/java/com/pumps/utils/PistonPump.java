package com.pumps.utils;

public class PistonPump extends Pump {
    @Override
    public double calculateFlow(PumpConditions conditions) {
        return conditions.getFlowRate()
               * conditions.getEfficiency()
               * (1 - 0.1 * conditions.getPressure());
    }
}
