package com.etsuya.java1;


import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class PoolTest  {
	public static void main(String[] args) {
		//使用Executors工具类创建一个线程池 （注意：用于接收返回值的ExecutorServices为接口）
		ExecutorService services = Executors.newFixedThreadPool(10);
		//（插曲）那么services的类是什么？ -> java.util.concurrent.ThreadPoolExecutor -> 是一个常见的接口子类
		System.out.println(services.getClass());
		//（可选）修改线程池属性
		ThreadPoolExecutor servicesRe = (ThreadPoolExecutor) services; //向下转型：ThreadPoolExecutor 间接继承于 ExecutorService
		//开启线程
		services.execute(new NumberCnt()); //execute()方法常用于开启Runnable线程
		services.execute(new NumberCnt2());
//		services.submit(Callable callable); //submit()方法常用于开启Callable线程
		//关闭线程池
		services.shutdown();
	}
}

class NumberCnt implements Runnable{
	@Override
	public void run() {
		for (int i = 1; i <= 100; i++) {
			System.out.println(i);
		}
	}
}

class NumberCnt2 implements Runnable{
	@Override
	public void run() {
		for (int i = 100; i <= 200; i++) {
			System.out.println(i);
		}
	}
}