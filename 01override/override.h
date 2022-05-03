#pragma once
#include <iostream>

//  C++11 �е� override �ؼ��֣�������ʽ��������������������Щ��Ա������Ҫ����д�����û����д����������ᱨ��

// ����ʵ�ּ̳е��麯��ʱ������Ϊ�������ơ��������͡�����������д�������²���ʵ�ֶ�̬���ԡ���������ڱ���ʱ������������׷��֡�
// �� ����override ���ԣ����������Ա��������������ʱ�Զ����ú����Ƿ��ɼ̳ж����������ǣ�����뱨��



class myOverride{
public: 
	myOverride();
	~myOverride();

	// ������û�����virtual�ؼ��֣����޷��γɶ�̬����
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
	// ������û�����virtual �ؼ��֣�Ҳ���γɶ�̬����(���еı���������֧�֣�struct��ĳЩ���������Ӹùؼ���Ҳ���ܶ�̬)��
	// override�ؼ���ֻ����ӵ��麯������ֻ��������ʱʹ�ã�ʵ��ʱ������� 
	int myFunc1(int x, int y);					// ok
	virtual int myFunc2(int x, int y);			// ok
	int myFunc3(int x, int y) override;			// ok
	virtual int myFunc4(int x, int y)const override;	// ok

	// �׻�����
	/*virtual int myFun(int x, int y)override ;*/  // error ,����ʱ����
	virtual int myFun(int x, int y);			   // ok,����Ϊ�ǿ��Ա���һ����������д���麯��

private:

};

// override �ܽ᣺�ѿ��ܴ��ĵ��µĴ��󣬽������������ 
// 1. ��Ҫ�γɶ�̬���ԣ������ڻ���ĸó�Ա��������ʱ�ھ������(ʵ��ʱ�������)virtual �ؼ��֣���������Զ���ʽ��ӣ�
//    �������ʾ�����ⲿ�ֱ�������stuct ����֧�ָ����ԣ�
// 2. ���������麯������ʱ�ں���ĩβ���(ʵ��ʱ�������)override �ؼ���,ͨ������׶μ���Ƿ�Ϊ��д���ͣ�
//    ������ʵ���麯������(���������������͡�������const����)��һ�£����¶�̬����ʹ�ã��ô����׷��֡�
