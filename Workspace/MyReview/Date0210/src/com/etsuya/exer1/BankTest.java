package com.etsuya.exer1;

import java.util.concurrent.locks.ReentrantLock;

public class BankTest {
	public static void main(String[] args) {
		Account a = new Account();
		new Thread(){
			@Override
			public void run() {
				for (int i = 0; i < 3; i++) {
					try {
						sleep(151);
					} catch (InterruptedException e) {
						throw new RuntimeException(e);
					}
					a.deposit(1000);
				}
			}
		}.start();
		new Thread(){
			@Override
			public void run() {
				for (int i = 0; i < 3; i++) {
					try {
						sleep(151);
					} catch (InterruptedException e) {
						throw new RuntimeException(e);
					}
					a.deposit(1000);
				}
			}
		}.start();
	}
	
}

class Account{
	private final ReentrantLock lock = new ReentrantLock();
	private int balance = 0;

	public int getBalance() {
		return balance;
	}

	public void setBalance(int balance) {
		this.balance = balance;
	}

	public void deposit(int money){
		try {
			lock.lock();
			balance += money;
			System.out.println(Thread.currentThread().getName() + ": " + this.getBalance());
		} finally {
			lock.unlock();
		}
	}
}