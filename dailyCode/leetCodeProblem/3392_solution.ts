//https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27
// 3392. Count Subarrays of Length Three With a Condition
/**
nums = [1,2,1,4,1] 
Output: 1
answer = [1,4,1]

nums = [1,1,1]
Output: 0

 */

//첫 번째 숫자와 세 번째 숫자의 합이, 가운데 숫자의 정확히 절반과 같을 때만 세야 한다
function countSubarrays(nums: number[]): number {
    let count = 0;

    for (let i = 1; i < nums.length - 1; i++) {
        if (nums[i-1] + nums[i+1] === nums[i] / 2) {
            count++;
        }
    }

    return count;
}

console.log(countSubarrays([1, 2, 1, 4, 1])); // Output: 1
console.log(countSubarrays([1,3,2,3,4,1])); // Output: 2
console.log(countSubarrays([-2,4,-2])); // Output: 0