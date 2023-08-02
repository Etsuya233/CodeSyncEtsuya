package com.etsuya.java1;

import java.util.zip.CheckedOutputStream;

public class EcosystemTest {
	public static void main(String[] args) {
		Customer cus = new Customer();
		Clerk cle = new Clerk();
		Productor pro = new Productor();
		pro.setClerk(cle);
		cus.setClerk(cle);

		Thread t1 = new Thread(cus);
		Thread t2 = new Thread(cle);
		Thread t3 = new Thread(pro);

		t1.start();
		t2.start();
		t3.start();

	}
}

class Productor implements Runnable{
	private Clerk clerk;

	public Clerk getClerk() {
		return clerk;
	}

	public void setClerk(Clerk clerk) {
		this.clerk = clerk;
	}

	@Override
	public void run() {
		while(true){
			try {
				Thread.currentThread().sleep(60);
			} catch (InterruptedException e) {
				throw new RuntimeException(e);
			}
			clerk.addProduct();
			System.out.println("生产者成功生产产品！" + clerk.getAmountOfThings());
		}
	}
}

class Clerk implements Runnable{
	public int getAmountOfThings() {
		return amountOfThings;
	}

	private Customer customer;
	private int amountOfThings = 0;

	public Customer getCustomer() {
		return customer;
	}

	public void setCustomer(Customer customer) {
		this.customer = customer;
	}

	public synchronized void getProduct(){
		if(amountOfThings <= 0){
			try {
				System.out.println("没有库存啦！等待生产！");
				wait();
				System.out.println("恢复售货！");
			} catch (InterruptedException e) {
				e.getStackTrace();
			}
		} else {
			System.out.println("店员成功售货！" + (amountOfThings));
			amountOfThings --;
			notifyAll();
		}
	}

	public synchronized void addProduct(){
		if(amountOfThings >= 20){
			try {
				System.out.println("太多产品了！等待消费！");
				wait();
				System.out.println("恢复生产！");
			} catch (InterruptedException e) {
				e.getStackTrace();
			}
		} else {
			System.out.println("店员成功进货！" + (amountOfThings + 1));
			amountOfThings ++;
			notifyAll();
		}
	}
	@Override
	public void run() {


	}
}

class Customer implements Runnable{
	private Clerk clerk;

	public Clerk getClerk() {
		return clerk;
	}

	public void setClerk(Clerk clerk) {
		this.clerk = clerk;
	}

	@Override
	public void run() {
		while(true){

			try {
				Thread.currentThread().sleep(120);
			} catch (InterruptedException e) {
				throw new RuntimeException(e);
			}
			clerk.getProduct();
			System.out.println("消费者成功消费！" + (clerk.getAmountOfThings() + 1));
		}

	}
}