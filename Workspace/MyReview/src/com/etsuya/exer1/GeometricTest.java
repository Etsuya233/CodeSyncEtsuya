package com.etsuya.exer1;

public class GeometricTest {
	public static void main(String[] args) {
		ComparableCircle a = new ComparableCircle(), b = new ComparableCircle();
		a.setRadius(2.2);
		b.setRadius(3.1);
		System.out.println(a.compareTo(b));
	}
}
