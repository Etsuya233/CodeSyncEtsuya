package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P69
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/1 13:45
 * @Version: 1.0
 */
public class P69 {
	@Test
	public void test(){
		System.out.println(mySqrt(2147395599));
	}

	public int mySqrt(int x) {
		double l = 0, r = x, mid = x, res = 0;
		final double accuracy = 0.000001;
		while(r - l > accuracy){
			mid = (l + r) / 2;
			res = mid * mid;
			if(res > x){
				r = mid;
			} else if (res < x){
				l = mid;
			} else {
				return (int)mid;
			}
		}
		if(mid - (int)mid < 0.000001){
			return (int)mid;
		} else if((int)(mid + 1) - mid < 0.000001){
			return (int)(mid + 1);
		} else {
			return (int)mid;
		}
	}
}
