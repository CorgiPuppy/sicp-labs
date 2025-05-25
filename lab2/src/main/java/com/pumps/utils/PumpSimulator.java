package com.pumps.utils;

public class PumpSimulator {
	private final Pump pump;
	private PumpConditions currentConditions;

	public PumpSimulator(Pump pump, PumpConditions initialConditions) {
		this.pump = pump;
		this.currentConditions = initialConditions;
	}

	public double simulate(int steps) {
		double totalFlow = 0;
		for (int i = 0; i < steps; i++) {
			totalFlow += pump.calculateFlow(currentConditions);
			currentConditions = new PumpConditions(
				currentConditions.getFlowRate(),
				currentConditions.getEfficiency(),
				currentConditions.getPressure() * 0.9
			);
		}
		
		return totalFlow;
	}
}
