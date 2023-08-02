package com.etsuya.exer2;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;

/**
 * ClassName: CallableTest
 * Package: com.etsuya.exer2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/21 19:55
 * @Version: 1.0
 */
public class CallableTest {
	public static void main(String[] args) {
		NumberCounter3 nc3 = new NumberCounter3();
		FutureTask ft = new FutureTask(nc3);
		Thread th = new Thread(ft);
		th.start();
		try {
			System.out.println(ft.get());
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		} catch (ExecutionException e) {
			throw new RuntimeException(e);
		}
	}
}

class NumberCounter3 implements Callable{

	@Override
	public Object call() throws Exception {
		int cnt = 0;
		for (int i = 0; i < 100; i++) {
			System.out.println(i);
			cnt += i;
		}
		return cnt;
	}
}