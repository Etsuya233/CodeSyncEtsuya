package com.etsuya.exer2;

/**
 * ClassName: ThreadTest1
 * Package: com.etsuya.exer2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/21 19:28
 * @Version: 1.0
 */
public class ThreadTest1 {
	public static void main(String[] args) {
//		NumberCounter a = new NumberCounter();
//		NumberCounter b = new NumberCounter();
//		new Thread(a).start();
//		new Thread(b).start();
		NumberCounter2 nc2 = new NumberCounter2();
		new Thread(nc2).start();
		new Thread(nc2).start();
	}
}
