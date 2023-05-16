#include<iostream>

#include"20230516_calculation.h"
#include"20230516_data.h"
void printA(void);
void printB(void);
void printC(void);
void printD(void);
void printE(void);
void printF(void);

void mainSpace03_20230516(void)
{

	C20230516_calculation cCalculation{};

	cCalculation.init();
	cCalculation.setData(100, 3);

	cCalculation.update(C20230516_calculation::E_OPERATOR::E_ADD);
	std::cout << cCalculation.getResult() << std::endl;

	cCalculation.update(C20230516_calculation::E_OPERATOR::E_SUB);
	std::cout << cCalculation.getResult() << std::endl;

	cCalculation.update(C20230516_calculation::E_OPERATOR::E_MUL);
	std::cout << cCalculation.getResult() << std::endl;

	cCalculation.update(C20230516_calculation::E_OPERATOR::E_DIV);
	std::cout << cCalculation.getResult() << std::endl;

	cCalculation.update(C20230516_calculation::E_OPERATOR::E_MOD);
	std::cout << cCalculation.getResult() << std::endl;



}

int mainSpace02_20230516(void)
{
	void(C20230516_DATA:: * pFunc)() {};
	C20230516_DATA cData1{};
	C20230516_DATA cData2{};

	cData1.setData(120);
	cData2.setData(51);

	pFunc = &C20230516_DATA::printData;
	(cData1.*pFunc)();
	(cData2.*pFunc)();

	pFunc = &C20230516_DATA::testFunc;

	(cData1.*pFunc)();
	(cData2.*pFunc)();

	return 0;
}

int mainSpace01_20230516(void)
{
	int nScore{};
	char strTable[13] = "FFFFFEDCBAA";
	void (*funcTable[12])() {};

	funcTable[0] = printF;
	funcTable[1] = printF;
	funcTable[2] = printF;
	funcTable[3] = printF;
	funcTable[4] = printF;
	funcTable[5] = printE;
	funcTable[6] = printD;
	funcTable[7] = printC;
	funcTable[8] = printB;
	funcTable[9] = printA;
	funcTable[10] = printA;

	std::cout << "Input Score : ";
	std::cin >> nScore;

	printf("strTable : %c\n", strTable[nScore / 10]);
	funcTable[nScore / 10]();

	return 0;
}

void printA(void)
{
	printf("func table : A\n");
}

void printB(void)
{
	printf("func table : B\n");
}

void printC(void)
{
	printf("func table : C\n");
}

void printD(void)
{
	printf("func table : D\n");
}

void printE(void)
{
	printf("func table : E\n");
}

void printF(void)
{
	printf("func table : F\n");
}
