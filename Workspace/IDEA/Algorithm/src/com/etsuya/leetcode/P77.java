package com.etsuya.leetcode;

import org.junit.Test;

import java.util.*;

public class P77 {
	ArrayDeque<Integer> my = new ArrayDeque<>();

	int cnt = 0;

	public List<List<Integer>> combine(int n, int k) {
		List<List<Integer>> ret = new ArrayList<>();
		dfs2(1, n, k, 0, ret);
		return ret;
	}

	public void dfs(int a, int n, int k, int layer, List<List<Integer>> ret){
		cnt ++;
		//剪枝！！！
		if(layer == k){
			ret.add(new ArrayList<>(my));
			return;
		}
		for(int i = a + 1; i <= n; i++){
			my.push(i);
			dfs(i, n, k, layer + 1, ret);
			my.removeFirst();
		}
	}

	public void dfs2(int a, int n, int k, int layer, List<List<Integer>> ret){
		cnt++;
		if(layer == k){
			ret.add(new ArrayList<>(my));
			return;
		}
		for(int i = a; i <= n - (k - layer) + 1; i++){
			my.add(i);
			dfs2(i + 1, n, k, layer + 1, ret);
			my.removeLast();
		}
	}

	@Test
	public void test(){
		List<List<Integer>> ret = combine(4, 2);
		for(List<Integer> a: ret){
			for(Integer i: a){
				System.out.print(i + " ");
			}
			System.out.println();
		}
		System.out.println(cnt);
	}
}
