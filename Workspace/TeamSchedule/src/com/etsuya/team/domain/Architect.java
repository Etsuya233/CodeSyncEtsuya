package com.etsuya.team.domain;

public class Architect extends Designer{
	public double getBonus() {
		return bonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}

	public int getStock() {
		return stock;
	}

	public void setStock(int stock) {
		this.stock = stock;
	}

	private double bonus;
	private int stock;

	public Architect(int id, int age, double salary, String name, Equipment equipment, double bonus, int stock) {
		super(id, age, salary, name, equipment, bonus);
		this.bonus = bonus;
		this.stock = stock;
	}
}
