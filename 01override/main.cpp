
#include <QtCore/QCoreApplication>

#include "override.h"

using namespace std;



int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	myOverride* t = new test;
	cout << t->myFunc1(15, 9) << endl; // 24
	cout << t->myFunc2(15, 9) << endl; // 6
	cout << t->myFunc3(15, 9) << endl; // 135
	cout << t->myFunc4(15, 9) << endl; // 1

	cout << (dynamic_cast<test*>(t))->myFun(15, 9) << endl; // 306

	return a.exec();
}
