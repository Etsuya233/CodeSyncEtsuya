package com.etsuya.study2;

public class AbstractTest2 {
	public static void main(String[] args) {
		new Template(){
			public void code(){
				String result = "";
				for(int i = 0; i < 1000; i++){
					result += i;
				}
				System.out.println(result);
			}
		}.spendTime();
	}
}

abstract class Template{
	public void spendTime(){
		long start = System.currentTimeMillis();
		code();
		long end = System.currentTimeMillis();
		System.out.println("Delta time: " + (end - start));
	}

	abstract public void code();
}