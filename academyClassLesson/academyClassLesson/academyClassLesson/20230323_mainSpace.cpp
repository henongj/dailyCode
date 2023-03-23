#include<iostream>

#include<iostream>

#include"2023_03_23_classOperator.h"
void mainSpace_20230323_01(void)
{
	C20230323ClassOperator cData1{};
	C20230323ClassOperator cData2{};

	//이거 왜 만들었어?
	cData1.setData(10);
	//이러면 되는데? operator = 을 정의하면 이런 원칙도 무너지지
	cData1 = 200;

	//심지어 왼쪽과 오른쪽 자료형도 다르단거야
	cData2 = cData1 + 12;

	cData2.printData();


}
