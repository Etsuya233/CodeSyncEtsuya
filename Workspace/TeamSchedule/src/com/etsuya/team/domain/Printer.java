package com.etsuya.team.domain;

public class Printer implements Equipment{
	private String name;
	private String type;

	public Printer(String name, String type) {
		this.name = name;
		this.type = type;
	}

	@Override
	public String getDescription() {
		return "Printer{" +
				"name='" + name + '\'' +
				", type='" + type + '\'' +
				'}';
	}
}
