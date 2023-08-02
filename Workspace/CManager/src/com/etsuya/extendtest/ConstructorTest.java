package com.etsuya.extendtest;

public class ConstructorTest {
	public static void main(String[] args) {
		Phone iPhone = new Phone(1299, 12, 512);

	}
}

class Phone{
	int storage;
	int memory;
	int price;

	public Phone(){
		System.out.println("The phone!!!");
	}
	public Phone(int price){
		this();
		this.price = price;
		System.out.println("The price:" + price);
	}
	public Phone(int price, int storage, int memory){
		this(price);
		this.storage = storage;
		this.memory = memory;
		System.out.println("The storage is " + storage);
		System.out.println("The memory is " + memory);
	}
}