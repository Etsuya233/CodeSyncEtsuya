package com.etsuya.exer2;

import org.junit.Test;

/**
 * ClassName: NumberCounter2
 * Package: com.etsuya.exer2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/21 19:41
 * @Version: 1.0
 */
public class NumberCounter2 implements Runnable{
	private static int cnt = 0;

	@Override
	public void run() {
		while(true){
			synchronized (this){
				notify();
				if(cnt <= 100){
					System.out.println(Thread.currentThread().getName() + ": " + cnt);
					cnt++;
					try {
						wait();
					} catch (InterruptedException e) {
						throw new RuntimeException(e);
					}
				} else break;
			}
		}
	}

	@Test
	public void test1(){
		new Thread(new NumberCounter2()).start();
		new Thread(new NumberCounter2()).start();
	}
}

