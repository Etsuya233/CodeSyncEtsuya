package com.etsuya.contacts;

import java.util.Scanner;

public class HelloWorld {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int[][] yanghui = new int[10][];
		yanghui[0] = new int[] {1}; //To solve the first row
		for(int cnt = 1; cnt < 10; cnt++) {
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
