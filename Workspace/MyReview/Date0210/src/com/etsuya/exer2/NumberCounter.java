package com.etsuya.exer2;

/**
 * ClassName: NumberCounter
 * Package: com.etsuya.exer2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/21 19:29
 * @Version: 1.0
 */
public class NumberCounter implements Runnable{
	private static int cnt = 0;
	@Override
	public void run() {
		while(true){
			synchronized (NumberCounter.class){
				if(cnt <= 100){
					System.out.println(Thread.currentThread().getName() + ": " + cnt);
					cnt++;
				} else break;
			}
		}
	}
}
