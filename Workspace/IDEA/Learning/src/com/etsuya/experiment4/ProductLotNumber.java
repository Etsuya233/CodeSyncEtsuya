package com.etsuya.experiment4;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;

public class ProductLotNumber {
	private static DateTimeFormatter dateTimeFormatter;
	private static Random random;

	public static String nextLotNumber(){
		if(dateTimeFormatter == null){
			dateTimeFormatter = DateTimeFormatter.ofPattern("yyyyMMdd'T'kkmmss.SSS");
			random = new Random(System.currentTimeMillis());
		}
		LocalDateTime localDateTime = LocalDateTime.now();
		String df = dateTimeFormatter.format(localDateTime);
		int rn = random.nextInt(10000000,100000000);
		return "L/N:[" + df + "/" + rn + "]";
	}
}
