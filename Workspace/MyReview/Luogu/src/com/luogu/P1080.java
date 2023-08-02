package com.luogu;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: P1080
 * Package: com.luogu
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/26 16:12
 * @Version: 1.0
 */
public class P1080 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n;
		n = scan.nextInt();
		int kingl = scan.nextInt(), kingr = scan.nextInt();
		People[] arr = new People[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new People();
			arr[i].l = scan.nextInt();
			arr[i].r = scan.nextInt();
		}
		Arrays.sort(arr);
		BigInteger sum = new BigInteger(String.valueOf(kingl));
		for (int i = 0; i < n - 1; i++) {
			sum = sum.multiply(new BigInteger(String.valueOf(arr[i].l)));
		}
		sum = sum.divide(new BigInteger(String.valueOf(arr[n - 1].r)));
		if(sum.toString().equals("0")){
			System.out.println("1");
		} else System.out.println(sum);
	}
}

class People implements Comparable{
	public People() {
	}

	public People(int l, int r) {
		this.l = l;
		this.r = r;
	}

	int l, r;

	@Override
	public int compareTo(Object o) {
		if(o == this) return 0;
		if(o instanceof People){
			People p = (People)o;
			if(this.l * this.r > p.l * p.r){
				return 1;
			} else if(this.l * this.r == p.l * p.r){
				if(this.r > p.r) return 1;
				return -1;
			} else return -1;
		}
		throw new RuntimeException("类型不匹配");
	}
}