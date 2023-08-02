import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

/**
 * ClassName: P1
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/6 16:32
 * @Version: 1.0
 */
public class P1 {
	@Test
	public void test(){
		int[] ints = {3, 2, 4};
		int[] res = twoSum(ints, 6);
		for(Integer i : res){
			System.out.println(i);
		}
	}

	public int[] twoSum(int[] nums, int target) {
//		HashMap<Integer, Integer> hashMap = new HashMap<>();
//		for(int i = 0; i < nums.length; i++){
//			hashMap.put(nums[i], i);
//		}
//		for(int i = 0; i < nums.length; i++){
//			int find = target - nums[i];
//			Integer get = hashMap.get((Integer) find);
//			if(get != null && get != i){
//				return new int[]{i, get};
//			}
//		}
//		return null;
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i = 0; i< nums.length; i++) {
			if(map.containsKey(target - nums[i])) {
				return new int[] {map.get(target-nums[i]),i};
			}
			map.put(nums[i], i);
		}
		throw new IllegalArgumentException("No two sum solution");

	}
}
