package com.etsuya.java7;

/**
 * ClassName: FIterface
 * Package: com.etsuya.java7
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/26 14:04
 * @Version: 1.0
 */
@FunctionalInterface
public interface FInterface<T> {
	public T getValue(T t);
}
