package com.etsuya.exer1;

public class Geometric {

}

interface CompareObject{
	public int compareTo(Object o);
	public default void show(){
		System.out.println("I'm a default method");
	}
}

class Circle{
	private Double radius;

	public Double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
}

class ComparableCircle extends Circle implements CompareObject{

	@Override
	public int compareTo(Object o) {
		if(o == this) return 0;
		if(o instanceof ComparableCircle){
			//Hoshiki 1:
//			if(this.getRadius() > ((ComparableCircle) o).getRadius()) return 1;
//			else if(this.getRadius() < ((ComparableCircle) o).getRadius()) return -1;
//			else return 0;
			// 2
			return this.getRadius().compareTo(((ComparableCircle) o).getRadius());
		} else {
			return 0;
		}
	}


}

