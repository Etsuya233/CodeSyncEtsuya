package com.etsuya.experiment03;


public class WirelessPrinter extends Printer implements Wireless{
	boolean status = false;

	@Override
	public void print() {
		int loc = 0;
		while(buffer != null && buffer[loc] != null){
			System.out.println(buffer[loc]);
			buffer[loc++] = null;
		}
	}

	@Override
	public void load(String[] contents) throws Exception {
		print();
		if(status){
			int loc = 0;
			for(String str: contents){
				buffer[loc++] = str;
			}
		} else {
			throw new Exception("E: The printer isn't connected to the Internet!");
		}
	}

	@Override
	public void wirelessConnect() {
		status = true;
	}
}
