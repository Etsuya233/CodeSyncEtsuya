package com.etsuya.experiment03;

public class Test {
	public static void main(String[] args) {
		LaserPrinter laserPrinter = new LaserPrinter();
		laserPrinter.load(new String[]{"Hey", "Miss Americana", "Wildest Dream"});
		laserPrinter.print();
		laserPrinter.load(new String[]{"1989", "Midnights"});

		WirelessPrinter wirelessPrinter = new WirelessPrinter();
		String[] temp = new String[]{"Fearless", "folklore"};
		try {
			wirelessPrinter.load(temp);
		}catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			wirelessPrinter.wirelessConnect();
			System.out.println("T: Connected to Internet automatically and loaded.");
			try {
				wirelessPrinter.load(temp);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		wirelessPrinter.print();
	}
}
