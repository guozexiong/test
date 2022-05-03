#include "override.h"


myOverride::myOverride(){}
myOverride::~myOverride(){}

int myOverride::myFunc1(int x, int y){
	return 0;
}
int myOverride::myFunc2(int x, int y){
	return 0;
}
int myOverride::myFunc3(int x, int y){
	return 0;
}
int myOverride::myFunc4(int x, int y)const{
	return 0;
}


test::test(){}
test::~test(){}

// 错误	1	error C2723: “test::myFunc1”:“virtual”说明符在函数定义上非法
// 声明时可以加virtual ，单独实现时不能添加
/*
virtual int test::myFunc1(int x, int y){
	return x+y;
}
*/
int test::myFunc1(int x, int y){
	return x + y;
}



// 错误	2	error C2723: “test::myFunc2”:“override”说明符在函数定义上非法
// 该函数在声明没有 override ，单独实现时不能添加
/*
int test::myFunc2(int x, int y)override {
	return x-y;
}
*/
int test::myFunc2(int x, int y) {
	return x - y;
}


/*
// 错误	2	error C2723: “test::myFunc2”:“override”说明符在函数定义上非法
// 该函数在声明没有 override ，单独实现时不能添加
int test::myFunc3(int x, int y) override{
	return x*y;
}
*/
int test::myFunc3(int x, int y) {
	return x*y;
}


/*
// 错误	4	error C2723: “test::myFunc4”:“override”说明符在函数定义上非法	
int test::myFunc4(int x, int y) override{
	return x/y;
}
*/
int test::myFunc4(int x, int y)const {
	return x / y;
}



int test::myFun(int x, int y){
	return x*x + y*y;
}
