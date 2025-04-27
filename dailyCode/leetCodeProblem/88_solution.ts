//https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
// Problem: Merge Sorted Array

function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    
    let pointer1:number = m - 1; // nums1의 가장 큰 값 인덱스
    let pointer2:number = n - 1; // nums2의 가장 큰 값 인덱스

    for(let i:number = m+n - 1 ; i >= 0; i--) {
        if(pointer1 < 0 || pointer2 < 0) {
            break;
        }

        if(nums1[pointer1] > nums2[pointer2]) {
            nums1[i] = nums1[pointer1];
            pointer1--;
        }
        else{
            nums1[i] = nums2[pointer2];
            pointer2--;
        }
    }

    // nums2에 남으면 
    while(pointer2 >= 0) {
        nums1[pointer2] = nums2[pointer2];
        pointer2--;
    }

    console.log(nums1);
};

//const nums1:number[] = [1,2,3,0,0,0];
//const nums2:number[] = [2,5,6];
// const m:number = 3;
// const n:number = 3;

// const nums1:number[] = [0];
// const nums2:number[] = [1];
// const m:number = 0;
// const n:number = 1;

// const nums1:number[] = [1];
// const nums2:number[] = [];
// const m:number = 1;
// const n:number = 0;

const nums1:number[] = [];
const nums2:number[] = [1];
const m:number = 0;
const n:number = 1;

merge(nums1, m, nums2, n);


/**
 * Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 */