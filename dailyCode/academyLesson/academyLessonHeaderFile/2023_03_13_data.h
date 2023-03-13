#pragma once

namespace lecture_2023_03_13
{
class C_DATA_2023_03_13
{
private:
	int m_nData;

public:
	C_DATA_2023_03_13() = default; // 명시적으로 기존 생성자 기능을 사용하겠다는 의미
	void setData(int nData);
};
