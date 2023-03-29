#include "classCopyConstructor.h"

void ClassCopyConstructor::init(int nData1, int nData2)
{
	m_nData1 = nData1;
	m_nData2 = nData2;
}

int mainSpaceClass_in_CopyConstructor(void)
{
	ClassCopyConstructor C_CCC{};
	C_CCC.init(1, 2);

	// if you use Copy constructor, you will get a compile error
	//ClassCopyConstructor C_CCC2 = C_CCC;

	return 0;
}
