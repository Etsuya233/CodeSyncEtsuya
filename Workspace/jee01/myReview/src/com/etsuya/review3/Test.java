package com.etsuya.review3;

import java.util.Arrays;

public class Test {
	public static void main(String[] args) {
		Circle a1 = new Circle("Red", 1, 1.2);
		Circle a2 = new Circle("Yellow", 22, 1.23);
	}
}

class GeometricObject{
	protected String colour;
	protected double weight;
	
	protected GeometricObject(String colour, double weight) {
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
		return 0.0;
	}
	
	public boolean equalsArea(GeometricObject a, GeometricObject b) {
		return a.findArea() == b.findArea();
	}
	
}

class Circle extends GeometricObject{
	private double radius;
	
	public static String name = "I'ma circle";
	
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
}

class Rectangle extends GeometricObject{
	private double width;
	private double height;
	
	public Rectangle(String colour, double weight, double width, double height) {
		super(colour, weight);
		this.width = width;
		this.height = height;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}
	
	public double findArea() {
		return width * height;
	}
}

class myEntry{
	private int id;
	private String name;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public boolean equals(myEntry a) {
		if(this.id == a.getId() && this.name.equals(a.getName())) return true;
		return false;
	}
	
}