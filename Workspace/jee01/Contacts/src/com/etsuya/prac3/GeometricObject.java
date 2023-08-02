package com.etsuya.prac3;

public class GeometricObject {
	protected String colour;
	protected double weight;
	
	protected GeometricObject() {
		colour = "white";
		weight = 1.0;
	}

	public GeometricObject(String colour, double weight) {
		this();
		this.colour = colour;
		this.weight = weight;
	}

	public String getColour() {
		return colour;
	}

	public void setColour(String colour) {
		this.colour = colour;
	}

	public double getWeight() {
		return weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}
	
	
	
}
