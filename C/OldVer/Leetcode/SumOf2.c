/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int cnt1=0, cnt2=1;
	int *ret = (int*)malloc(sizeof(int)*2);
	for(cnt1=0;cnt1<numsSize-1;cnt1++){
		for(cnt2=1;cnt2<numsSize;cnt2++){
			if(nums[cnt1]+nums[cnt2]==target){
				ret[0] = cnt1;
				ret[1] = cnt2;
				break;
			}
		}
	}
	return ret;
}
