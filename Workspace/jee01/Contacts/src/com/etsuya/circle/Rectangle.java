package com.etsuya.circle;

public class Rectangle extends Shape{
	private double length;
	private double width;
	
	public Rectangle() {
		length = 1;
		width = 1;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		if(length > 0) {
			this.length = length;
		} else {
			System.out.println("Invalid.");
		}
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		if(width > 0) {
			this.width = width;
		} else {
			System.out.println("Invalid.");
		}
	}
	
	public double getArea() {
		return width * length;
	}
}


