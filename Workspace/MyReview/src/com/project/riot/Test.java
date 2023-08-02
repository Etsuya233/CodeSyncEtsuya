package com.project.riot;


public class Test {
	public static void main(String[] args) {
		Windows a1 = new Windows();
		Windows a2 = new Windows();
		Windows a3 = new Windows();

		a1.setName("Windows 1");
		a2.setName("Windows 2");
		a3.setName("Windows 3");
		
		a1.start();
		a2.start();
		a3.start();
	}
}

class NumberOpera extends Thread{
	public void run(){
		for (int i = 0; i < 20; i++) {
			if(i % 2 == 0) System.out.println(i);
		}
	}
}

class Thread1 extends Thread{
	public void run(){
		for (int i = 0; i < 100; i++) {
			setName("qwa");
			if(i % 2 == 1) System.out.println(getName() + ": " + i);
			if(i % 20 == 0){
				try {
					sleep(1000);
				} catch (InterruptedException e) {
					throw new RuntimeException(e);
				}
			}
		}
	}
}

class Thread2 extends Thread{
	public void run(){
		for (int i = 0; i < 100; i++) {
			if(i % 2 == 0) System.out.println(i);
		}
	}
}

class Windows extends Thread{
	private static int id = 0;

	@Override
	public void run() {
		while(id <= 100){
			System.out.println(getName() + ": " + id);
			id ++;
		}
	}
}