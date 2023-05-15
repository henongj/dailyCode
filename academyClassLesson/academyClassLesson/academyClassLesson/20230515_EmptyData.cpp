#include<cassert>
#include "20230515_EmptyData.h"


C20230515_emptyData::C20230515_emptyData()
{
	static bool bCreate = false;
	
	//assert
	if (!bCreate)
		bCreate = true;
	else
		assert(false);
}

void mainSpace01_20230515(void)
{
	C20230515_emptyData data1{};
	C20230515_emptyData data2{};

}
