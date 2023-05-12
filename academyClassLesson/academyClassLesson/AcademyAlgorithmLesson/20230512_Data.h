#pragma once

class C20230512_DATA
{
private:
	static C20230512_DATA* m_pInstance;
	int m_nData;

private:
	C20230512_DATA() = default;
	~C20230512_DATA() = default;
	
public:
	C20230512_DATA& operator=(const C20230512_DATA& rhs) = delete;
	C20230512_DATA(const C20230512_DATA& rhs) = delete;
	
	void setData(int nData);
	int getData();
	
public:
	void init(int nData);

	static void createInstance();
	static C20230512_DATA* getInstance();
	static void releaseInstance();
};