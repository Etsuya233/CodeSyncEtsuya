package com.etsuya.prac;

public class Test {
	public static void main(String[] args) {
		int[] numberStorage = new int[5];
		for(int cnt = 0; cnt < numberStorage.length; cnt++) {
			int temp;
			while(true) {
				boolean noRepeat = true;
				temp = (int)(Math.random()*100);
				for(int cnt2 = 0; cnt2 < numberStorage.length; cnt2++) {
					if(temp == numberStorage[cnt2]) {
						noRepeat = false;
						continue;
					}
				}
				if(temp<=30 && noRepeat) break;
			}
			numberStorage[cnt] = temp;
		}
		for(int cnt = 0; cnt < numberStorage.length; cnt++) {
			System.out.println(numberStorage[cnt]);
		}
	}
}
