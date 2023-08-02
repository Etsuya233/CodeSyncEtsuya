package com.etsuya.array;

import org.junit.Test;

/**
 * ClassName: P59
 * Package: com.etsuya.array
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/6 14:32
 * @Version: 1.0
 */
public class P59 {
	@Test
	public void test(){
		int[][] ints = generateMatrix(5);
		for (int i = 0; i < 5; i++) {
			for (int i1 = 0; i1 < 5; i1++) {
				System.out.print(ints[i][i1] + " ");
			}
			System.out.println();

		}

	}
	public int[][] generateMatrix(int n) {
		int[][] ret = new int[n][n];
		int now = 1, status = 0, i = 0, j = -1;
		int[] ii = {0, 1, 0, -1}, jj = {1, 0, -1, 0};
		while(now <= n * n){
			if(i + ii[status] >= 0 && i + ii[status] < n && j + jj[status] >= 0 && j + jj[status] < n && ret[i + ii[status]][j + jj[status]] == 0){
				ret[i = i + ii[status]][j = j + jj[status]] = now;
				now ++;
			} else {
				status = (status + 1) % 4;
			}
		}
		return ret;
	}
}
