package com.etsuya.java1;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: GeneticsTest2
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/9 21:53
 * @Version: 1.0
 */
public class GeneticsTest2 {
	@Test
	public void test(){
		List<? super Animal> list = new ArrayList<Animal>();
		list.get(0);
		
		list.add(new Animal());
		list.add(new Bird());
	}
}

class Animal{}

class Bird extends Animal{}