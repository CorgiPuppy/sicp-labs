package com.pumps;

import com.pumps.utils.Pump;
import com.pumps.utils.RotaryPump;
import com.pumps.utils.PistonPump;
import com.pumps.utils.PumpConditions;
import com.pumps.utils.PumpSimulator;

public class Main {
    public static void main( String[] args ) {
		Pump rotaryPump = new RotaryPump();
		PumpConditions conditions = new PumpConditions(10.0, 0.85, 1.0);

		PumpSimulator simulator = new PumpSimulator(rotaryPump, conditions);
		double total = simulator.simulate(10);

        System.out.printf("Total pumped: %.2f units%n", total);
    }
}
