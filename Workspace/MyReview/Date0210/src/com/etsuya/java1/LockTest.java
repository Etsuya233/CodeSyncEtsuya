package com.etsuya.java1;

import java.util.concurrent.locks.ReentrantLock;

public class LockTest {
}

class LockGod implements Runnable{
	private final ReentrantLock lock = new ReentrantLock();

	@Override
	public void run() {
		try {
			lock.lock();
			for (int i = 0; i < 100; i++) {
				System.out.println(i);
			}
		} finally {
			lock.unlock();
		}
	}
}