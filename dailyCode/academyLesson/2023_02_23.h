#pragma once
#include<iostream>

namespace academyLecture_2023_02_23
{

	int add(int, int);
	float add(float, float);

	// const int& 는 상수로 통합됐다
	// printf("%d \n", add(10, 20)); 이거 사용할 때 에러가 뜬다
	// 왜냐면 링크를 확정할 수가 없어서 모호하니까 에러를 띄운다
	// 그런데 이렇게 선언만 하고 안 쓰면 에러가 안 난다고
	int add(const int& nData1, const int& nData2);
	// 이렇게 해도 에러가 난다고
	// 인수만 가지고 링크할 때 어느 것과 연결해야 하는지 모호해서 에러가 난다고
	int add(int nData1, int nData2, int nData3 = 10);
	// C언어 특성상 call by value인지 call by reference인지 모호하다
	// func(20)은 template 까지 고려하면 호출될 가능성 잇는 함수가 4개야

	void func(int nData);

	int mainTest(void)
	{
		//printf("%d \n", add(10, 20));
		printf("%f \n", add(10.5f, 20.0f));

		//주석 확인해봐
		func(0);
	}

	int add(int nData1, int nData2)
	{
		return nData1 + nData2;
	}

	float add(float nData1, float nData2)
	{
		return nData1 + nData2;
	}


	//함수 설명
	//어쩌고 저쩌고 data는 어쩌고
	void func(int nData)
	{

	}
}