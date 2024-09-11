#include <stdio.h>

/**
 * 
* @param nums 2555. 两个线段获得的最多奖品
中等
相关标签
相关企业
提示
在 X轴 上有一些奖品。给你一个整数数组 prizePositions ，它按照 非递减 顺序排列，其中 prizePositions[i] 是第 i 件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数 k 。

你可以同时选择两个端点为整数的线段。每个线段的长度都必须是 k 。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。

比方说 k = 2 ，你可以选择线段 [1, 3] 和 [2, 4] ，你可以获得满足 1 <= prizePositions[i] <= 3 或者 2 <= prizePositions[i] <= 4 的所有奖品 i 。
请你返回在选择两个最优线段的前提下，可以获得的 最多 奖品数目。

 * @param numsSize 
 * @return 
 */
int singleNumber(int *nums, int numsSize) {
    int first_index = 0, second_index = 0;
    for (first_index = 0; first_index < numsSize; first_index++) {
      
        int temp = nums[first_index];
        for (second_index = 0; second_index < numsSize; second_index++) {
            if ( first_index == numsSize-1  && first_index == second_index ) {
                return nums[first_index];
            }
            if (temp == nums[second_index] && second_index != first_index) {
                break;
            }
         
            if (temp != nums[second_index] && second_index == numsSize - 1) {
                return temp;
            }
        }
    }
    // 没找到匹配的
    return  -1;
}

// int singleNumber(int *nums, int numsSize) {
//     int result = 0;
//     for (int i = 0; i < numsSize; i++) {
//         result ^= nums[i];  // 利用异或消除成对的元素
//     }
//     return result;  // 返回只出现一次的元素
// }


void main() {
    int nums[3] = {2,2,1};
    printf("%d\n", singleNumber(nums, 3));
}
