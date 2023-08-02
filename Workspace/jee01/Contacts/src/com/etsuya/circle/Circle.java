package com.etsuya.circle;

public class Circle extends Shape{
	private double radius;
	
	public Circle() {
		radius = 1;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		if(radius > 0) {
			this.radius = radius;
		} else {
			System.out.println("The value you entered is invalid.");
		}
	}
	
	public double getArea() {
		return Math.PI * radius * radius;
	}
}
