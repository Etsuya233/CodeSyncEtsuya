package com.etsuya.java1;

public class NumberTest {
	public static void main(String[] args) {
		Number a = new Number();
		Thread w1 = new Thread(a);
		Thread w2 = new Thread(a);
		w1.start();
		w2.start();
	}
}

class Number implements Runnable{
	static int num = 0;

	@Override
	public void run() {
		while(true){
			synchronized (this){
				notify();
				if(num <= 100) System.out.println(Thread.currentThread().getName() + ": " + num);
				else break;
				num ++;
				try {
					wait();
				} catch (InterruptedException e) {
					throw new RuntimeException(e);
				}
			}
		}
	}
}

