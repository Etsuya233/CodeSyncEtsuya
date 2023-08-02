package com.etsuya.java1;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: GeneticsMethodTest
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/9 16:55
 * @Version: 1.0
 */
public class GeneticsMethodTest {
}

class Opera{
	public static <E> List<E> copyThings2List(E[] e){
		ArrayList<E> ret = new ArrayList<>();
		for(E obj: e){
			ret.add(obj);
		}
		return ret;
	}
}