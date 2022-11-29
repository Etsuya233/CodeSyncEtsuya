#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(){
	int nums[] = {3,2,4};
	int *answer = twoSum(nums,3,6,nums);
	for(int cnt=1;cnt<=2;cnt++,answer++){
		printf("%d", *answer);
	}
	
	
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int cnt1=0, cnt2=1;
	int *ret = NULL;
	for(cnt1=0;cnt1<numsSize-1;cnt1++){
		for(cnt2=cnt1+1;cnt2<numsSize;cnt2++){
			if(nums[cnt1]+nums[cnt2]==target){
				ret =  (int*)malloc(sizeof(int)*2);
				ret[0] = cnt1;
				ret[1] = cnt2;
				break;
			}
		}
	}
	return ret;
}
