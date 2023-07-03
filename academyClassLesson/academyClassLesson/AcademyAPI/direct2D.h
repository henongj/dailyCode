#pragma once

#include<d2d1.h>

//singleton class 

class C_DIRECT2D
{
private:
	C_DIRECT2D() = default;
	
	ID2D1Factory* m_pFactory;
	ID2D1HwndRenderTarget* m_pRenderTarget;
	static C_DIRECT2D* m_pAPI;
private:
	static void createDirect2D();
	static void releaseDirect2D();
	static C_DIRECT2D* getDirect2D();
	
public:
	void init(void);
	
	
	
};

