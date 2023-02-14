
//https://leetcode.com/problems/add-binary/description/
//67. Add Binary
class Solution {
public:
	string addBinary(string a, string b) {
		string strResult{};
		int i = a.size() - 1;
		int j = b.size() - 1;
		int carry = 0;
		while (i >= 0 || j >= 0)
		{
			int sum = carry;
			if (i >= 0)
			{
				sum += a[i--] - '0';
			}
			if (j >= 0)
			{
				sum += b[j--] - '0';
			}
			strResult += to_string(sum % 2);
			carry = sum / 2;
		}
		if (carry != 0)
		{
			strResult += to_string(carry);
		}
		reverse(strResult.begin(), strResult.end());
		return strResult;
	}
};