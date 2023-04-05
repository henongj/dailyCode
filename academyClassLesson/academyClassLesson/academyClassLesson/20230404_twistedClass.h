class C_3Level
{
protected:
	virtual void state() { printf("3_state\n"); }
public:
	virtual void update() { 
		state(); 
		printf("3_update\n"); 
	}
};


class C_2Level : public C_3Level
{
protected:
	virtual void state() { C_3Level::state(); 
	printf("2_state\n"); }
public:
	virtual void update() { 
		C_3Level::update(); 
		printf("2_update\n"); 
	}
};


class C_1Level : public C_2Level
{
protected:
	virtual void state() { C_2Level::state(); 
	printf("1_state\n"); }
public:
	virtual void update() { 
		C_2Level::update(); 
		printf("1_update\n"); 
	}
};
