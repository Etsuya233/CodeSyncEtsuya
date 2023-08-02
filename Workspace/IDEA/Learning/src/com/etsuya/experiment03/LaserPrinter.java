package com.etsuya.experiment03;

public class LaserPrinter extends Printer {
	@Override
	public void print() {
		int loc = 0;
		while(buffer != null && buffer[loc] != null){
			System.out.println(buffer[loc]);
			buffer[loc++] = null;
		}
	}

	@Override
	public void load(String[] contents) {
		print();
		int loc = 0;
		for(String str: contents){
			buffer[loc++] = str;
		}
	}
}
