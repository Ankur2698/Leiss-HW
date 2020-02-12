#include <iostream>
#include <string>
using namespace std;

int main()
{
	int s = 0;
	int t = 0;

	cout << "Compute the multiplicative inverse of: ";
	cin >> s;
	cout << "with respect to: ";
	cin >> t;
	
	cout << "a\t|x\ty\tq\t" << endl;
	cout << "--------------------------------------" << endl;

	int a1, a2, x1, x2, y1, y2, q;

	if (s > t)
	{
		a1 = s;
		a2 = t;
	}
	else
	{
		a1 = t;
		a2 = s;
	}
	x1 = 1;
	x2 = 0;
	y1 = 0;
	y2 = 1;

	cout << a1 << "\t|" << x1 << "\t " << y1 << "\t " << "-" << "\t " << endl;
	cout << a2 << "\t|" << x2 << "\t " << y2 << "\t " << "-" << "\t " << endl;
	cout << "--------------------------------------" << endl;

	while (a2 > 1)
	{
		q = a1 / a2;
		int temp = a2;
		a2 = a1 - (q * a2);
		a1 = temp;
		cout << a2 << "\t|";

		temp = x2;
		x2 = x1 - (x2 * q);
		x1 = temp;
		cout << x2 << "\t ";

		temp = y2;
		y2 = y1 - (y2 * q);
		y1 = temp;
		cout << y2 << "\t ";

		cout << q << "\t " << endl;
	}

	int answer;
	if (s > t)
		answer = x2;
	else
		answer = y2;
	if (answer < 0)
		answer = answer + t;
	cout << "The multiplicative inverse is: " << answer << endl;
}