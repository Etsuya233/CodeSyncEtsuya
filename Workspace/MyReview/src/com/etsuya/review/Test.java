package com.etsuya.review;

import java.util.Random;
import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		Random r = new Random();
		Scanner scan = new Scanner(System.in);
		System.out.println("Please enter your favourite number:");
		int a = scan.nextInt();
		int b = r.nextInt(44, 55);
		System.out.println("Your favourite number is " + b);
	}
}
