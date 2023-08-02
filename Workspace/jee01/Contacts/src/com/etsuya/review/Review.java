package com.etsuya.review;

import java.util.Scanner;

public class Review {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		PrivateTest test = new PrivateTest();
		test.set_unvisibleVar(scan.nextInt());
		System.out.println(test.get_unvisibleVar());
	}
}

class PrivateTest{
	int visibleVar = 1;
	private int unvisibleVar = 12;
	
	public void set_unvisibleVar(int i) {
		if(i < 1) {
			System.out.println("Wrong number detected");
		}else {
			unvisibleVar = i;
		}
	}
	
	public int get_unvisibleVar() {
		return unvisibleVar;
	}
	
	
}