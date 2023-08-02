package com.etsuya1.java1;

public class ThreadTest {
	public static void main(String[] args) {
		T2 a = new T2();
		Thread ta = new Thread(a);
		ta.start();
	}
}

class T1 implements Runnable{
	@Override
	public void run() {
		for (int i = 51; i < 100; i++) {
			System.out.println(Thread.currentThread().getName() + ": " + i);
		}
	}
}

class T2 implements Runnable{
	@Override
	public void run() {
		for (int i = 0; i < 50; i++) {
			System.out.println(Thread.currentThread().getName() + ": " + i);
			if(i == 25){
				Thread aa = new Thread(new T1());
				aa.setPriority(Thread.MAX_PRIORITY);
				
				aa.start();
			}
		}
	}
}