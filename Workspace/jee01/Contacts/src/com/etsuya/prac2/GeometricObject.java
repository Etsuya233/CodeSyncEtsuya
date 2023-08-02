package com.etsuya.prac2;

public class GeometricObject {
	protected String colour;
	protected double weight;
	protected GeometricObject(String colour, double weight) {
		super();
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
	public double findArea() {
		return 1.0;
	}
	
	
	
}


