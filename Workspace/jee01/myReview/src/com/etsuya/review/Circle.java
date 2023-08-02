package com.etsuya.review;

public class Circle {
	private double radious = 0;
	private double area = 0;
	
	public Circle() {
		this.setRadious(1);
	}
	public double getRadious() {
		return radious;
	}
	public void setRadious(double radious) {
		this.radious = radious;
	}
	public void renewArea() {
		area = 3.1415926 * radious * radious;
	}
	public double getArea() {
		return area;
	}
	public void say() {
		System.out.println("I'm a Circle!");
	}
}

class Cylinder extends Circle{
	private double height;
	private double volume;

	public Cylinder() {
		this.setHeight(1);
	}
	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}
	public void say() {
		System.out.println("I'ma Cylinder!");
	}
	
}