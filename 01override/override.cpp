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

// ����	1	error C2723: ��test::myFunc1��:��virtual��˵�����ں��������ϷǷ�
// ����ʱ���Լ�virtual ������ʵ��ʱ�������
/*
virtual int test::myFunc1(int x, int y){
	return x+y;
}
*/
int test::myFunc1(int x, int y){
	return x + y;
}



// ����	2	error C2723: ��test::myFunc2��:��override��˵�����ں��������ϷǷ�
// �ú���������û�� override ������ʵ��ʱ�������
/*
int test::myFunc2(int x, int y)override {
	return x-y;
}
*/
int test::myFunc2(int x, int y) {
	return x - y;
}


/*
// ����	2	error C2723: ��test::myFunc2��:��override��˵�����ں��������ϷǷ�
// �ú���������û�� override ������ʵ��ʱ�������
int test::myFunc3(int x, int y) override{
	return x*y;
}
*/
int test::myFunc3(int x, int y) {
	return x*y;
}


/*
// ����	4	error C2723: ��test::myFunc4��:��override��˵�����ں��������ϷǷ�	
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
