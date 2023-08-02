package com.etsuya.review2;

public class InterfaceTest {
	public static void main(String[] args) {
		Circle c = new Circle(1.22);
		System.out.println(c);
		Square s = new Square(1.22, 3.1);
		System.out.println(s);
		System.out.println(c.compareTo(new Exception()));
	}
}

interface Comparable{
	public int compareTo(Object o);
}

abstract class GeometricObject implements Comparable{
	public GeometricObject(){

	}
	double area;
	abstract public String toString();
}

class Circle extends GeometricObject {
	private double radius;

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
		renewArea();
	}

	public Circle(double radius){
		if(radius > 0){
			this.radius = radius;
			renewArea();
		}
		else throw new RuntimeException("数据非法");
	}

	@Override
	public int compareTo(Object o) {
		if(o instanceof GeometricObject){
			return Double.compare(this.area, ((GeometricObject) o).area);
		} else throw new RuntimeException("比较对象错误！应两个对象均为 GeometricObject 的子类。");
	}

	private void renewArea(){
		this.area = 3.14 * radius * radius;
	}

	@Override
	public String toString() {
		return "Circle{" +
				"radius=" + radius +
				", area=" + area +
				'}';
	}
}

class Square extends GeometricObject{
	private double a;

	public double getA() {
		return a;
	}

	public void setA(double a) {
		this.a = a;
		renewArea();
	}

	public double getB() {
		return b;
	}

	public void setB(double b) {
		this.b = b;
		renewArea();
	}

	private double b;
	public Square(double a, double b){
		this.a = a;
		this.b = b;
		renewArea();
	}

	@Override
	public int compareTo(Object o) {
		return 0;
	}
	private void renewArea(){
		this.area = a * b;
	}

	@Override
	public String toString() {
		return "Square{" +
				"a=" + a +
				", b=" + b +
				", area=" + area +
				'}';
	}
}