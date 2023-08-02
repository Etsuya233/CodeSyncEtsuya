package com.etsuya.java1;

public class BankTest {
	public static void main(String[] args) {
		new Thread(new Runnable() {
			@Override
			public void run() {
				System.out.println("fuck u alban");

			}
		}).start();
	}
}

class Bank{
	private Bank(){}

	private static Bank instance = null;

	public static Bank getInstance() {
		if(instance == null) {
			synchronized (Bank.class) {
				if (instance == null) instance = new Bank();
			}
		}
		return instance;
	}


}