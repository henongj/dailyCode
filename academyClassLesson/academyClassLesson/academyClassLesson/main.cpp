#include<iostream>

#include"20230529_store.h"
int main(void)
{
	C20230529_STORE store{};
	store.init();

	store.createDrink(C20230529_STORE::E_TYPE::E_JUICE)->printName();
	
	
	
	return 0;
}