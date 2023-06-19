#include<stdio.h>
#include<iostream>
#include<set>
#include<map>

enum class E_WEAPON
{
	E_SWORD = 0x00000001,
	E_DAGGER = 0x00000002,
	E_MACE = 0x00000004,
	E_HAMMER = 0x00000008,
	E_BOW = 0x00000010,
	E_SPEAR = 0x00000020,
	E_DART = 0x00000040,
	E_CLUB = 0x00000080,
	E_STAF = 0x00000100
};

void checdkUsableWeapon(int nWeaponMask);

int mainSpace02_20230619(void)
{
	int nWeaponMask{};

	nWeaponMask = (int)E_WEAPON::E_HAMMER | (int)E_WEAPON::E_MACE | (int)E_WEAPON::E_CLUB;

	checdkUsableWeapon(nWeaponMask);

	nWeaponMask |= (int)E_WEAPON::E_BOW;
	nWeaponMask |= (int)E_WEAPON::E_DART;
	if (nWeaponMask & (int)E_WEAPON::E_HAMMER)
		nWeaponMask ^= (int)E_WEAPON::E_HAMMER;
	if (nWeaponMask & (int)E_WEAPON::E_MACE)
		nWeaponMask ^= (int)E_WEAPON::E_MACE;
	if (nWeaponMask & (int)E_WEAPON::E_CLUB)
		nWeaponMask ^= (int)E_WEAPON::E_CLUB;

	checdkUsableWeapon(nWeaponMask);
	return 0;
}

void checdkUsableWeapon(int nWeaponMask)
{
	if (nWeaponMask & (int)E_WEAPON::E_SWORD)
		std::cout << "검을 쓸 수 있습니다" << std::endl;
	else
		std::cout << "검을 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_DAGGER)
		std::cout << "단검을 쓸 수 있습니다" << std::endl;
	else
		std::cout << "단검을 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_MACE)
		std::cout << "메이스를 쓸 수 있습니다" << std::endl;
	else
		std::cout << "메이스를 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_HAMMER)
		std::cout << "해머를 쓸 수 있습니다" << std::endl;
	else
		std::cout << "해머를 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_BOW)
		std::cout << "활을 쓸 수 있습니다" << std::endl;
	else
		std::cout << "활을 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_SPEAR)
		std::cout << "창을 쓸 수 있습니다" << std::endl;
	else
		std::cout << "창을 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_DART)
		std::cout << "다트를 쓸 수 있습니다" << std::endl;
	else
		std::cout << "다트를 쓸 수 없습니다" << std::endl;
	if (nWeaponMask & (int)E_WEAPON::E_CLUB)
		std::cout << "클럽을 쓸 수 있습니다" << std::endl;
	else
		std::cout << "클럽을 쓸 수 없습니다" << std::endl;

	return;

}

void codePsace_20230619(void)
{
	int nData = 0xFF00;
	int nData1 = 30;
	int nData2 = 40;
	int nResult{};

	nResult = nData1 ^ nData2;
	int nPosition = 6553900;
	int nYpos = nPosition >> 16 & 0xFFFF0000;//(nPosition & 0xFFFF0000) >> 16;
	int nXpos = (nPosition & 0x0000FFFF);

	printf("16진수 : %d\n", nData);
	printf("%d\n", nResult);
	printf("%d\n", nData2 << 2);
	printf("%d\n", nData2 >> 2);
	printf("%d\n", (12345678 & 0x0000FF00) >> 8);

	printf("position (X,Y) : (%d, %d)\n", nXpos, nYpos);

}