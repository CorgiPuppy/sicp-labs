package com.pumps.utils;

public class PumpConditions {
	private final double flowRate;
	private final double efficiency;
	private final double pressure;

	public PumpConditions(double flowRate, double efficiency, double pressure) {
		this.flowRate = flowRate;
		this.efficiency = efficiency;
		this.pressure = pressure;
	}

	public double getFlowRate() { return flowRate; }
	public double getEfficiency() { return efficiency; }
	public double getPressure() { return pressure; }
}
