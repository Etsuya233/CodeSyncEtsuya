package com.etsuya.prac2;

public class GeometricTest {
	public static void main(String[] args) {
		Circle cir = new Circle("red", 1.23, 2);
		Circle cir2 = new Circle("red", 1.24, 2);
		System.out.println(cir.equals(cir2));
	}
	
	
	public boolean equalsArea(GeometricObject a, GeometricObject b) {
		if(a.findArea() == b.findArea()) {
			return true;
		}
		return false;
	}
	
	public void displayGeometricObject(GeometricObject a) {
		System.out.println("The area of the geometric object is " + a.findArea());
	}
}
