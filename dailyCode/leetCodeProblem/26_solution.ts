// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
// 26. Remove Duplicates from Sorted Array

// @ts-nocheck
function removeDuplicates(nums: number[]): number {
    let indexPointer = 0; // 인덱스 가리키는데 쓴다
    let valuePointer = -101; // 값, indexPointer가 나아가기 위한 척도

    for(let i:number = 0 ; i < nums.length ; i++){

        if(nums[i] !== valuePointer){ // 값이 다르면
            valuePointer = nums[i]; // 값 갱신
            nums[indexPointer] = nums[i]; // indexPointer에 넣어준다
            indexPointer++; // indexPointer를 증가시킨다
        }

    }
    return indexPointer; // indexPointer를 리턴한다
};


console.log(removeDuplicates([0,0,1,1,1,2,2,3,3,4])) // 5
console.log(removeDuplicates([1,1,2])) // 2
console.log(removeDuplicates([])) // 0
console.log(removeDuplicates([1])) // 1
console.log(removeDuplicates([1,2])) // 2
console.log(removeDuplicates([1,1,1,1,1])) // 1