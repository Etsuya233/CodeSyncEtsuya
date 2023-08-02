import org.junit.Test;

import java.util.Arrays;

/**
 * ClassName: P3
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/5 21:21
 * @Version: 1.0
 */
public class P3 {
	public static void main(String[] args) {

	}

	@Test
	public void test1(){
		String s = " ";
		int[] hash = new int[129];
		int bound = 0, max = 0;
		for(int i = 0; i < s.length(); i++){
			int index = (int)s.charAt(i);
			if(hash[index] + 1 > bound) {
				bound = hash[index] + 1;
			}
			if(i - bound + 1 > max) max = i - bound + 1;
			hash[index] = i;
		}
		System.out.println(max);
	}
}
