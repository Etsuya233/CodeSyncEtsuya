package com.etsuya.java1;

import java.util.Queue;

public class SynchronizedTest {
	public static void main(String[] args) {
		Windows a = new Windows();
		Thread w1 = new Thread(a, "窗口一");
		Thread w2 = new Thread(a, "窗口二");
		Thread w3 = new Thread(a, "窗口三");
		w1.start();
		w2.start();
		w3.start();
	}
}

class Windows implements Runnable{
	int ticket = 100;
	Object obj = new Object();
	@Override
	public void run() {
		while(true){
			if(ticket > 0){
				getThing();
			} else return;
		}
	}

	private synchronized void getThing(){
		if (ticket > 0) {
			System.out.println(Thread.currentThread().getName() + ": " + ticket);
			ticket--;
			try {
				Thread.sleep(20);
			} catch (InterruptedException e) {
				e.getStackTrace();
			}
		}
	}
}