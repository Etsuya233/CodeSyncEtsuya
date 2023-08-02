package com.etsuya.java1;

public class SynTestThread {
	public static void main(String[] args) {
		Windows2 w1 = new Windows2();
		Windows2 w2 = new Windows2();
		Windows2 w3 = new Windows2();
		w1.start();
		w2.start();
		w3.start();
	}
}

class Windows2 extends Thread{
	private static int ticket = 100;

	@Override
	public void run() {
		while(ticket > 0) {
			getThings();
		}
	}

	private static synchronized void getThings(){
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