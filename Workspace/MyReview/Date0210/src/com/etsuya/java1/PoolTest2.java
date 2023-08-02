package com.etsuya.java1;

import java.util.concurrent.*;

public class PoolTest2 {
	public static void main(String[] args) {
		ExecutorService services = Executors.newFixedThreadPool(10);
		Future<Object> futureTask;
//		Thread thread = new Thread(futureTask);
		futureTask = services.submit(new NumberCnt22());
//		services.execute(thread);
		try {
			System.out.println(futureTask.get());
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		} catch (ExecutionException e) {
			throw new RuntimeException(e);
		}

		services.shutdown();
	}
}

class NumberCnt22 implements Callable {
	@Override
	public Object call() throws Exception {
		int sum = 0;
		for (int i = 0; i < 100; i++) {
			if(i % 2 == 0){
				System.out.println(i);
				sum += i;
			}
		}
		return sum;
	}
}