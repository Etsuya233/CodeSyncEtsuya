package com.etsuya.team.domain;

public class PC implements Equipment{
	private String model;
	private String display;

	public PC(String model, String display) {
		this.model = model;
		this.display = display;
	}

	@Override
	public String getDescription() {
		return "PC{" +
				"model='" + model + '\'' +
				", display='" + display + '\'' +
				'}';
	}
}
