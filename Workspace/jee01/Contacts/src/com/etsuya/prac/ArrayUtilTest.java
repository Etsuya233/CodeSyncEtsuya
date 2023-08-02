package com.etsuya.prac;

public class ArrayUtilTest {
	public static void main(String[] args) {
		
		int arr[] = new int[] {1,2,3,5,4};
		
		ArrayUtil test = new ArrayUtil();
		
		System.out.println(test.getSum(arr));
		
		new mOLUtil().mOL(12);
		new mOLUtil().mOL(1, 5);
		new mOLUtil().mOL("Fuck");
	}
}

class mOLUtil{
	public void mOL(int i) {
		System.out.println(i * i);
	}
	
	public void mOL(int i, int j) {
		System.out.println(i * j);
	}
	
	public void mOL(String str) {
		System.out.println(str);
	}
}