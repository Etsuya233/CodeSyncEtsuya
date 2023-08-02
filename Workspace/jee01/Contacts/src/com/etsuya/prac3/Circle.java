package com.etsuya.prac3;



public class Circle extends GeometricObject{
	private double radius;
	
	public Circle() {
		super();
		radius = 1.0;
	}
	public Circle(double radius) {
		super();
		this.radius = radius;
	}
	public Circle(double radius, String colour, double weight) {
		this.radius = radius;
		this.colour = colour;
		this.weight = weight;
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public boolean equals(Circle cir) {
		return this.radius == cir.radius;
	}
	
	public String toString() {
		return "The radius of this circle is " + radius + ".";
	}
}


