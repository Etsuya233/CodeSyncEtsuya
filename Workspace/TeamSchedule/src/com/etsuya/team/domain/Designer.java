package com.etsuya.team.domain;

import com.etsuya.team.service.Status;

public class Designer extends Programmer{
	private double bonus;

	public Designer(int id, int age, double salary, String name, Equipment equipment, double bonus) {
		super(id, age, salary, name, equipment);
		this.bonus = bonus;
	}

	public double getBonus() {
		return bonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}
}
