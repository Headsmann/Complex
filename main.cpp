#include <iostream>
#include "zespolona.h"
using namespace std;

//funkcja testująca
void test() {
	try {
		Zespolona<double> a(1.0, 2.1);
		Zespolona<double> b(0.8, 1.7);
		Zespolona<double> c;

		//TEST OPERATORA +, +=
		cout << "Test operatora + i +=:" << endl;
		cout << a << " + " << b << " = " << a + b << endl;
		cout << a << " += " << b << " = " << (a += b) << endl;

		//TEST OPERATORA -, -=
		cout << "Test operatora - i -=: " << endl;
		cout << a << " - " << b << " = " << a - b << endl;
		cout << a << " -= " << b << " = " << (a -= b) << endl;

		//TEST OPERATORA *, *=:
		cout << "Test operatora * i *=: " << endl;
		cout << a << " * " << b << " = " << a * b << endl;
		cout << a << " *= " << b << " = " << (a *= b) << endl;

		//TEST OPERATORA /,/=:
		cout << "Test operatora / i /=: " << endl;
		cout << a << " / " << b << " = " << a / b << endl;
		cout << a << " /= " << b << " = " << (a /= b) << endl;

		//TEST OPERATOR PORÓWNANIA:
		cout << "Test operatora porownania: " << endl;
		cout << a << " == " << b << " = " << (a == b) << endl;
		c = a;
		cout << a << " == " << c << " = " << (a == c) << endl;

		c = Zespolona<double>(1.0, 1.0);




	}
	catch (const char *e) {
		cout << "Exception: " << e << endl;
	}
	catch (const exception &e) {
		cout << "Exception: " << e.what() << endl;
	}
	catch (...) {
		cout << "Caught not expected exception" << endl;
	}

}
int main() {
	test();
	system("pause");
}