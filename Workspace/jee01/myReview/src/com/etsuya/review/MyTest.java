package com.etsuya.review;

import java.util.Arrays;
import java.util.Scanner;

public class MyTest {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Zoo nomania = new Zoo();
		int n;
		System.out.println("How much animal do you want to add?");
		n = scan.nextInt();
		Animal[] arr2 = new Animal[n];
		for(int i = 0; i < n; i++) {
			arr2[i] = new Animal();
			System.out.println("Animal " + (i + 1));
			arr2[i].species = scan.next();
		}
		nomania.addAnimal(arr2);
		nomania.sayMyAnimal();
		
		
//		Circle a = new Circle();
//		System.out.println("Set the radious of the circle:");
//		a.setRadious(scan.nextDouble());
//		a.renewArea();
//		System.out.println(a.getArea());
	}
}

class Zoo{
	int animalAmount = 0;
	Animal[] arr = new Animal[100];
	
	public void addAnimal(Animal a) {
		arr[animalAmount++] = a;
	}
	public void addAnimal(Animal[] a) {
		for(int i = 0; i < a.length; i++) {
			this.addAnimal(a[i]);
		}
	}
	public void sayMyAnimal() {
		for(int i = 0; i < animalAmount; i++) {
			System.out.print(arr[i].species + "    ");
		}
	}
}

class Animal{
	String species;
	int age = 0;
	int sex;
	
	public Animal() {
		
	}
	public Animal(String a, int b) {
		species = a;
		age = b;
	}
	public Animal(String a, int b, int c) {
		this(a, b);
		sex = c;
	}
	public void eat() {
		System.out.println("I am eating!");
	}
	
}