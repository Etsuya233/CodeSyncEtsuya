package com.etsuya.prac;

public class YangHui {
	public static void main(String[] args) {
		int[][] yanghui = new int[10][];
		for(int cnt = 0; cnt < 10; cnt++) {
			yanghui[cnt] = new int[cnt+1];
			yanghui[cnt][0] = yanghui[cnt][cnt] = 1;
			for(int cnt1 = 1; cnt1 <= cnt - 1; cnt1++) {
					yanghui[cnt][cnt1] = yanghui[cnt-1][cnt1-1] + yanghui[cnt-1][cnt1];
			}
		}
		
		for(int cnt = 0; cnt < 10; cnt++) {
			for(int cnt1 = 0; cnt1 < yanghui[cnt].length; cnt1++) {
				System.out.print(yanghui[cnt][cnt1] + " ");
			}
			System.out.println();
		}
	}
}
