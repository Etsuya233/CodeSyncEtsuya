package com.etsuya.circle;

public class Cylinder extends Circle {
	double height;
	
	public Cylinder() {
		super();
		height = 1;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		if(height > 0) {
			this.height = height;
		} else {
			System.out.println("The value you entered is invalid.");
		}
	}
	
	@Override
	public double getArea() {
		return super.getArea() * 2 + getRadius() * 2 * Math.PI * height;
	}
	
	public double getVolume() {
		return getArea() * height;
	}
	
}
