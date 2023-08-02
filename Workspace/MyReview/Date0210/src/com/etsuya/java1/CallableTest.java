package com.etsuya.java1;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

//编写一个Callable实现类
class NumCnt implements Callable {
	//重写call()方法，一定有返回值（Object类型）
	@Override
	public Object call() throws Exception {
		int sum = 0;
		for (int i = 1; i <= 100; i++) {
			if(i % 2 == 0){
				System.out.println(i);
				sum += i;
			}
		}
		return sum;
	}
}

public class CallableTest {
	public static void main(String[] args) {
		//创建一个Callable实现类对象
		NumCnt numcnt = new NumCnt();
		//创建一个FutureTask对象，并把实现类对象传入构造器
		FutureTask futureTask = new FutureTask(numcnt);
		//创建Thread类对象，并传入FutureTask对象（因为FutureTask它implements了Runnable）
		Thread numcntRun = new Thread(futureTask);
		//开始线程的运行
		numcntRun.start();

		//（可选）获取放返回值：
		try {
			//futureTask.get()返回Object类型的放回值，为前面call()方法的返回值
			System.out.println(futureTask.get());
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		} catch (ExecutionException e) {
			throw new RuntimeException(e);
		}
	}
}

