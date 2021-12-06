#include "Szyfry.h"
#include <iostream>
#include <string>

int modulo(int a, int b)
{
	for (int z = 1; z < b; z++)
		if (((a % b) * (z % b)) % b == 1)
			return z;
}

string szyfry::RSA(string tekst)
{
	int a;
	int b;
	cout << "podaj liczbe pierwsza" << endl;
	cin >> a;
	cout << "podaj liczbe pierwsza" << endl;
	cin >> b;

	int f = a * b;
	int euler = (a - 1) * (b - 1);

	cout << "podaj liczbe od 1 do " << euler << endl;
	cout << "liczba ta i " << euler << " ma byc pierwsza" << endl;
	int e;
	cin >> e;
	int d = modulo(e, euler);

	pair<int, int> publiczny;
	publiczny.first = f;
	publiczny.second = e;
	cout << "klucz publiczny: " << publiczny.first << " " << publiczny.second << endl;

	pair<int, int> prywatny;
	prywatny.first = f;
	prywatny.second = d;
	cout << "klucz prywatny: " << prywatny.first << " " << prywatny.second << endl;
	return " ";
}