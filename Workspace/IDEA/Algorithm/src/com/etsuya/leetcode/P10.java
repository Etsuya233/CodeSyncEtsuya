package com.etsuya.leetcode;

import org.junit.Test;

@SuppressWarnings("SpellCheckingInspection")
public class P10 {
	@Test
	public void test(){
		String s = "ab";
		String p = ".*";
		System.out.println(isMatch(s, p));
	}

	public boolean isMatch1(String s, String p) {
		int lens = s.length(), lenp = p.length();
		int ps = 0, pp = 0;
		boolean match = false;

		char mae = '\0';
		while(ps < lens && pp < lenp){
			if(s.charAt(ps) == p.charAt(pp) || p.charAt(pp) == '.'){
				if(p.charAt(pp) != '.') mae = s.charAt(ps);
				else mae = '.';
				ps++;
				pp++;
			} else if(p.charAt(pp) == '*'){
				while(ps < lens && (s.charAt(ps) == mae || mae == '.')){
					ps++;
				}
				if(ps - 1 >= 0) mae = s.charAt(ps - 1);
				pp++;
			} else {
				ps = 0;
				pp++;
			}
		}
		if(ps == lens) match = true;
		return match;
	}

	public boolean isMatch(String s, String p) {
		int lens = s.length(), lenp = p.length();
		int ps = 0, pp = 0;
		boolean match = true;
		while(ps < lens && pp < lenp){

			int leastTake = 1;
			int c1 = p.charAt(pp), c2 = (pp + 1 < lenp)? p.charAt(pp + 1): '\0';
			if(c2 == '*'){
				if(c1 == '.'){
					char c3 = (pp + 2 < lenp)? p.charAt(pp + 2): '\0';
					if(c3 == '\0'){
						char c4 = s.charAt(ps);
						while(ps < lens && s.charAt(ps) == c4){
							ps++;
						}
						if(ps != lens) match = false;
						pp += 2;
						return match;
					}
					leastTake = 0;
					int fpp = pp;
					fpp += 2;
					while(fpp < lenp && c3 != '\0' && (p.charAt(fpp) == c3)){
						fpp++;
						leastTake++;
					}
					if(s.charAt(ps) == c3){
						int i = 0;
						while(pp < lenp && (p.charAt(pp) == c3)){
							pp++;
							i++;
						}
						if(i < leastTake){
							match = false;
							break;
						}
					} else {
						pp += 2;
					}
				} else {
					leastTake = 0;
					pp += 2;
					while(pp < lenp && (p.charAt(pp) == c1)){
						leastTake++;
						pp++;
					}
					int i = 0;
					while(ps < lens && s.charAt(ps) == c1){
						ps++;
						i++;
					}
					if(i < leastTake){
						match = false;
						break;
					}
				}
			} else {
				if(s.charAt(ps) != p.charAt(pp) && p.charAt(pp) != '.'){
					match = false;
					break;
				}
				ps++;
				pp++;
			}
		}
		if(ps < lens || pp < lens) match = false;
		return match;
	}
}
