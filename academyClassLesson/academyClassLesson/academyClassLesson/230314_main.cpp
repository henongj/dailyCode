#include<iostream>

#include"print_20230314.h"
#include"230314_unit.h"

void main230414_0(void)
{
	C_PRINT cPrint{};

	cPrint.getData()->setData(10);

	cPrint.print();
}

void main230314_1(void)
{
	C_PRINT cPrint{};

	cPrint.getData();
	cPrint.print();

	C_UNIT cUnit(10.0f);
}
