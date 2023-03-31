#pragma once

//추상클래스
class C202303301_virtual abstract
{
private:
public:
	virtual ~C202303301_virtual();
	C202303301_virtual() = default;
	
	//delete assignment oprerator and copy constructor
	C202303301_virtual(const C202303301_virtual&) = delete;
	C202303301_virtual& operator=(const C202303301_virtual&) = delete;
	
	virtual void printTest(void);
};

//일반 클래스
class C202303301_test : public C202303301_virtual
{
private:
public:
	C202303301_test() = default;
	~C202303301_test();
	
	//delete assignment oprerator and copy constructor
	C202303301_test(const C202303301_test&) = delete;
	C202303301_test& operator=(const C202303301_test&) = delete;
	
	void printTest(void) override;
};