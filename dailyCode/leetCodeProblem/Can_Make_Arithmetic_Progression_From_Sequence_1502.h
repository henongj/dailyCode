
//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
//1502. Can Make Arithmetic Progression From Sequence
#ifndef ___Can_Make_Arithmetic_Progression_From_Sequence_1502_h___
#define ___Can_Make_Arithmetic_Progression_From_Sequence_1502_h___

class Solution {
public:
	int get_abs(int num)
	{
		return num > 0 ? num : -num;
	}
	bool canMakeArithmeticProgression(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int gap = get_abs(arr[0] - arr[1]);

		for (int idx = 0; idx < arr.size() - 1; idx++)
		{
			if (gap != get_abs(arr[idx] - arr[idx + 1]))
				return false;
		}

		return true;
	}
};
/* testcase
[1,10,10,10,19]
[3,5,1]
[1,2,4]
[0,0,0,0,0,0,0]
[-509,-19,-439,-264,-404,-369,-299,-89,-229,-54,-194,16,-544,-159,-124,-474,-334]
*/
#endif // !___Can_Make_Arithmetic_Progression_From_Sequence_1502_h___
