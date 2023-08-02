package com.etsuya.study;

public class TriAngle {
	private int height;
	private int base;

	public TriAngle(int heightOfTheTriAngle, int baseOfTheTriAngle){
		height = heightOfTheTriAngle;
		base = baseOfTheTriAngle;
	}

	public void setHeight(int h){
		if(h<=0){
			System.out.println("Wrong! The height has been automatically set to 1.");
			height = 1;
		} else {
			height = h;
		}
	}

	public int getHeight(){
		return height;
	}

	public void setBase(int b){
		if(b<=0){
			System.out.println("Wrong! The base has been automatically set to 1.");
			base = 1;
		} else {
			base = b;
		}
	}

	public int getBase(){
		return base;
	}

}
