/// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
// 80. Remove Duplicates from Sorted Array II

function removeDuplicates(nums: number[]): number {

    let indexPointer = 0;
    let valuePointer = -10001; // -10*4 <= nums[i] <= 10*4
    let duplicateCount = 0; // 중복된 숫자 개수

    for(let i:number = 0 ; i < nums.length ; i++){
        // 1. 값이 다르면 
        // - valuePointer 갱신, duplicateCount = 0, indexPointer++
        // 2. 값이 같고, duplicateCount < 1 이면
        // - valuePointer 갱신, duplicateCount++, indexPointer++
        // 3. 값이 같고, duplicateCount >= 1 이면
        // - 아무것도 안함

        if(nums[i] !== valuePointer){ // 값이 다르면
            valuePointer = nums[i]; // 값 갱신
            duplicateCount = 0; // 중복된 숫자 개수 초기화
            nums[indexPointer] = nums[i]; // indexPointer에 넣어준다
            indexPointer++; // indexPointer를 증가시킨다
        } else if(duplicateCount < 1){ // 값이 같고, duplicateCount < 1 이면
            valuePointer = nums[i]; // 값 갱신
            duplicateCount++; // 중복된 숫자 개수 증가
            nums[indexPointer] = nums[i]; // indexPointer에 넣어준다
            indexPointer++; // indexPointer를 증가시킨다
        }
        // else 암것도 안함
    }
    
    return indexPointer; // indexPointer를 리턴한다
};

console.log(removeDuplicates([1,1,1,2,2,3])) // 5
console.log(removeDuplicates([0,0,1,1,1,2,2,3,3,4])) // 9 (0,0,1,1,2,2,3,3,4)
console.log(removeDuplicates([1,1,2])) // 3