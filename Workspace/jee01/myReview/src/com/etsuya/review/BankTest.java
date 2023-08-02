package com.etsuya.review;

import java.util.Scanner;

public class BankTest {
	public static void main(String[] args) {
//		Scanner scan = new Scanner(System.in);
//		System.out.println("Enter the bank name:");
//		Bank my = new Bank(scan.next());
//		System.out.println("How many customers do you want to add: ");
//		my.addCustomer(scan.nextInt());
//		my.displayAllTheCustomer();
//		
		Dog erGou = new Dog();
		erGou.setSpecies("Dog");
		erGou.sayInfo();
	}
}

class Customer{
	private String name;
	private int age;
	private int current;
	
	public Customer() {
		
	}
	public Customer(String name) {
		this.name = name;
	}
	public Customer(String name, int current) {
		this(name);
		this.current = current;
	}
	public Customer(String name, int current, int age) {
		this(name, current);
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getCurrent() {
		return current;
	}
	public void setCurrent(int current) {
		this.current = current;
	}
}

class Bank{
	private String bankName;
	private int amountOfCustomer = 0;
	private Customer[] list = new Customer[100];
	
	public Bank() {
		
	}
	public Bank(String name) {
		bankName = name;
	}
	public void addCustomer(int newCustomer) {
		for(int i = 0; i < newCustomer; i++) {
			System.out.println("New customer 1:");
			list[amountOfCustomer] = new Customer();
			System.out.println("    Name:");
			list[amountOfCustomer].setName(new Scanner(System.in).next());
			System.out.println("    Current:");
			list[amountOfCustomer].setCurrent(new Scanner(System.in).nextInt());
			amountOfCustomer++;
		}
	}
	
	public String getBankName() {
		return bankName;
	}
	public void setBankName(String bankName) {
		this.bankName = bankName;
	}
	public int getAmountOfCustomer() {
		return amountOfCustomer;
	}
	public void setAmountOfCustomer(int amountOfCustomer) {
		this.amountOfCustomer = amountOfCustomer;
	}
	public void displayAllTheCustomer() {
		for(int i = 0; i < amountOfCustomer; i++) {
			System.out.println("Name: " + list[i].getName() + ", Current: " + list[i].getAge());
		}
	}
	
}

class Animal2{
	private String species;
	private int age;
	private int leg;
	public Animal2(String a) {
		species = a;
	}
	public String getSpecies() {
		return species;
	}
	public void setSpecies(String species) {
		this.species = species;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getLeg() {
		return leg;
	}
	public void setLeg(int leg) {
		this.leg = leg;
	}
	
	public void sayInfo() {
		System.out.println("My name is " + getSpecies());
	}
}

class Dog extends Animal2{
	int vaccinated = 0;
	public Dog() {
		super("Dog");
	}
	public void bark() {
		System.out.println("Woof!");
	}
}