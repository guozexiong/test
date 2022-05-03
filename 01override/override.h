#pragma once
#include <iostream>

//  C++11 中的 override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错。

// 子类实现继承的虚函数时，会因为函数名称、参数类型、参数个数的写错，而导致不能实现多态特性。这种情况在编译时不会出错，不容易发现。
// 故 引入override 属性，放置与类成员函数声明，编译时自动检测该函数是否由继承而来，若不是，则编译报错。



class myOverride{
public: 
	myOverride();
	~myOverride();

	// 若父类没有添加virtual关键字，则无法形成多态特性
	virtual int myFunc1(int x, int y);
	virtual int myFunc2(int x, int y);
	virtual int myFunc3(int x, int y);
	virtual int myFunc4(int x, int y)const;
};


class test:public myOverride
{
public:
	test ();
	~test();
	// 若子类没有添加virtual 关键字，也可形成多态特性(但有的编译器不能支持，struct在某些编译器不加该关键字也不能多态)；
	// override关键字只能添加到虚函数后，且只能在声明时使用，实现时不能添加 
	int myFunc1(int x, int y);					// ok
	virtual int myFunc2(int x, int y);			// ok
	int myFunc3(int x, int y) override;			// ok
	virtual int myFunc4(int x, int y)const override;	// ok

	// 易混淆，
	/*virtual int myFun(int x, int y)override ;*/  // error ,编译时报错
	virtual int myFun(int x, int y);			   // ok,被认为是可以被下一个派生类重写的虚函数

private:

};

// override 总结：把可能粗心导致的错误，交给编译器检查 
// 1. 需要形成多态特性，必须在基类的该成员函数声明时在句首添加(实现时不能添加)virtual 关键字，派生类会自动隐式添加，
//    但最好显示，避免部分编译器或stuct 不能支持该特性；
// 2. 在派生类虚函数声明时在函数末尾添加(实现时不能添加)override 关键字,通过编译阶段检测是否为重写类型，
//    避免与实际虚函数声明(函数名、参数类型、个数、const特性)不一致，导致多态不能使用，该错误不易发现。
