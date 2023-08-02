package com.etsuya.study;

public class OrderTest {
	public static void main(String[] args) {
		Order order = new Order();
		System.out.println(order.id);
	}
}
class Order{
	{
		id = 2;
	}
	int id = 1;
	public Order(){
		id = 3;
	}
}