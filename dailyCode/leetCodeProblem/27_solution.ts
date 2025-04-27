//https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-
// 27. Remove Element

function removeElement(nums: number[], val: number): number {
    let target = 0; 

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == val) { // 같으면
            continue; // 건너뛰기
        }
        nums[target] = nums[i]; // 같지 않으면 대입
        target++; // 타겟 증가
    }
    
    //console.log(nums);

    return target;
    
};

console.log(removeElement([3,2,2,3], 3)); // Output: 2, nums = [2,2,_] 
console.log(removeElement([1,2,3,4,5], 6)); // Output: 5, nums = [1,2,3,4,5] 
console.log(removeElement([1,2,3,4,5], 4)); // Output: 4, nums = [1,2,3,5] 