package com.etsuya.prac2;

public class Circle extends GeometricObject{
	private double radius;

	public Circle(String colour, double weight, double radius) {
		super(colour, weight);
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double findArea() {
		return Math.PI * radius * radius;
	}
	
	public boolean equals(Circle cir) {
		if(cir.radius == radius && cir.weight == weight && cir.colour == colour) {
			return true;
		}
		return false;
	}
}
