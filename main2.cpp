#include <fstream>
#include <string>
#include <iostream>

using namespace std;

long fib(int n) {
	if (n < 3)
		return 1;
	return fib(n - 2) + fib(n - 1);
}


int main(void)
{
	int i;
	cout << "Input index N Fibanachi: ";
	cin >> i;
	cout << "\nFib(i): " << fib(i);
	__int64 a[2][2] = { { 1, 1 }, { 1, 0 } };
	__int64 q[2][2] = { { 1, 0 }, { 0, 0 } };
	__int64 r00 = 1;
	__int64 r01 = 0;
	cout << "\nSTAAAAAAAAART! \n";
	cout << "\nMATRIX\n| " << a[0][0] << " " << a[0][1] << " |\n"
		<< "| " << a[1][0] << " " << a[1][1] << " |\n";
	cout << "\nMATRIX temp\n| " << q[0][0] << " " << q[0][1] << " |\n"
		<< "| " << q[1][0] << " " << q[1][1] << " |\n";
	cout << "\n ################\n\n";
	for (;i > 0;) {
		cout << "i&1 " << (i & 1) << endl;
		cout << "index:" << i << endl;
		if ((i&1) == 1) {
			q[0][0] = (r00 * q[0][0] + r01 * q[1][0]);
			q[0][1] = (r00 * q[0][1] + r01 * q[1][1]);
			r00 = q[0][0];
			r01 = q[0][1];
		}
		q[0][0] = (a[0][0] * a[0][0] + a[0][1] * a[1][0]);
		q[0][1] = (a[0][0] * a[0][1] + a[0][1] * a[1][1]);
		q[1][0] = (a[1][0] * a[0][0] + a[1][1] * a[1][0]);
		q[1][1] = (a[1][0] * a[0][1] + a[1][1] * a[1][1]);
		a[0][0] = q[0][0];
		a[0][1] = q[0][1];
		a[1][0] = q[1][0];
		a[1][1] = q[1][1];

		cout << "\nMATRIX\n| " << a[0][0] << " " << a[0][1] << " |\n"
			<< "| " << a[1][0] << " " << a[1][1] << " |\n";
		cout << "\nMATRIX temp\n| " << q[0][0] << " " << q[0][1] << " |\n"
			<< "| " << q[1][0] << " " << q[1][1] << " |\n";
		cout << "\n RESULT: " << r01 << endl;
		i >>= 1;
	}

	system("Pause");
	return 0;
}
