package com.etsuya.prac3;

public class CircleTest {
	public static void main(String[] args) {
		Circle circle1 = new Circle(1.22);
		Circle circle2 = new Circle(1.21);
		
		System.out.println(circle1.toString());
		
		GeometricObject geo = new GeometricObject();
		System.out.println(geo instanceof Circle);
	}
	
	
}
