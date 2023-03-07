#include<iostream>
namespace academyLecture_2023_03_06
{

#pragma pack(1)
	struct S_Data1
	{
		int n1;
		char c1;
		int n2;
		char c2;
	};

#pragma pack(4)
	struct S_Data2
	{
		int n1;
		int n2;
		char c1;
		char c2;
	};

#pragma pack(1)
	struct S_Data3
	{
		int n1;
		int n2;
		char c1;
		char c2;
		double d1;
	};

	struct S_Data4
	{
		char c1;
		double d1;
		int n1;
		int n2;
		char c2;
	};


	struct S_Data5
	{
		int nData1;
		int nData2;
		float fData1;
		float fData2;
	};
	void mainSpace (void)
	{
		printf("%d\n", (int)sizeof(S_Data1));
		printf("%d\n", (int)sizeof(S_Data2));
		printf("%d\n", (int)sizeof(S_Data3));
		printf("%d\n", (int)sizeof(S_Data4));

		S_Data5 sData1{};

		//이렇게 집어넣는 방식은 지양해야한다. 왜? 고민좀해바라
		S_Data5 sData2{ 1,2,1.1f,2.2f };

		printf("%d\n", sData1.nData1);
		printf("%f\n\n", sData1.fData1);
		printf("%d\n", sData2.nData1);
		printf("%f\n", sData2.fData1);
		printf("%d\n", sData2.nData2);
		printf("%f\n", sData2.fData2);
		
	}
}