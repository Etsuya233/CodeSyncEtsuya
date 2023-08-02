package com.project.riot;

public abstract class RunnableTest {
	public static void main(String[] args) {
		RTea a = new RTea();
		new Thread(a).start();
	} 	
}
class RTea implements Runnable{
	@Override
	public void run() {
		for (int i = 0; i < 100; i++) {
			if(i % 2 == 0) System.out.println(i);
			if(i % 20 == 0) {
				try {
					new Thread(new T2()).join();
				} catch (InterruptedException e) {
					throw new RuntimeException(e);
				}
			}
		}
	}
}

class T2 implements Runnable{
	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			System.out.println("hahahaa");
		}
	}
}