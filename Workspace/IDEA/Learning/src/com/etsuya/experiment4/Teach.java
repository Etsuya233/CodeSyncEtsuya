package com.etsuya.experiment4;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;

/**
 * ClassName: Teach
 * Package: com.etsuya.experiment4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/28 15:10
 * @Version: 1.0
 */
public class Teach {
	public static String nextLotNumber(){
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyyMMdd'T'kkmmss.SSS");
		Random random = new Random(System.currentTimeMillis());

		LocalDateTime ldt = LocalDateTime.now();
		String df = dtf.format(ldt);
		int rn = random.nextInt(10000000,100000000);
		return "L/N:[" + df + "/" + rn + "]";
	}
}
