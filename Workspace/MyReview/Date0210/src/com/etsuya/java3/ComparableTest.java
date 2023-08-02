package com.etsuya.java3;

import jdk.jshell.execution.JdiInitiator;
import org.junit.Test;

import java.util.Arrays;
import java.util.Comparator;

/**
 * ClassName: ComparableTest
 * Package: com.etsuya.java3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/24 19:37
 * @Version: 1.0
 */
public class ComparableTest {
	@Test
	public void test() {
		//创建实例
		Product[] product = new Product[5];
		product[0] = new Product(2799, "OnePlus Ace2");
		product[1] = new Product(2799, "Realme GT Neo 5");
		product[2] = new Product(6799, "iPhone 14 Pro");
		product[3] = new Product(3799, "Xiaomi 13 Pro");
		product[4] = new Product(5799, "Huawei Mate 50 Pro");
		//原始输出
		for (int i = 0; i < 5; i++) {
			System.out.println(product[i]);
		}
		System.out.println("----------------");
		//按照Product类里的compareTo()方法输出
		Arrays.sort(product);
		for (int i = 0; i < 5; i++) {
			System.out.println(product[i]);
		}
		System.out.println("----------------");
		//按照Comparator对象的方式输出
		Comparator comparator_name_reverse = new Comparator() {
			@Override
			public int compare(Object o1, Object o2) {
				if(o1 instanceof Product && o2 instanceof Product){
					if(o1 == o2) return 0;
					return ((Product) o2).name.compareTo(((Product) o1).name);
				}
				throw new RuntimeException("类型不匹配");
			}
		};
		Arrays.sort(product, comparator_name_reverse);
		for (int i = 0; i < 5; i++) {
			System.out.println(product[i]);
		}
	}
}

class Product implements Comparable{
	int price;
	String name;

	public Product(int price, String name) {
		this.price = price;
		this.name = name;
	}

	@Override
	public String toString() {
		return "Product{" +
				"price=" + price +
				", name='" + name + '\'' +
				'}';
	}

	@Override
	public int compareTo(Object o) {
		if(o == this) return 0;

		if(o instanceof Product){
			int ret;
			ret = Integer.compare(this.price, ((Product) o).price);
			if(ret == 0){
				return this.name.compareTo(((Product) o).name);
			}
			return ret;
		}

		throw new RuntimeException("类型不匹配");
	}
}