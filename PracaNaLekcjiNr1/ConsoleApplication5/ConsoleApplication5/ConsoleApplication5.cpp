#include<iostream>
#include<cstring>

using namespace std;

string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void szyfruj(char tab[])
{
	int i = 0;
	while (tab[i])
	{
		if (tab[i] == 'X') tab[i] = 'A';
			if (tab[i] == 'Y') tab[i] = 'B'; else
				if (tab[i] == 'Z') tab[i] = 'C'; else
					if (tab[i] < 'X') tab[i] += 3;
		++i;
	}
}

void deszyfruj(char tab[])
{
	int i = 0;
	while (tab[i])
	{
		if (tab[i] == 'A') tab[i] = 'X'; else
			if (tab[i] == 'B') tab[i] = 'Y'; else
				if (tab[i] == 'C') tab[i] = 'Z'; else
					if (tab[i] > 'C') tab[i] -= 3;
		++i;
	}
}
	void kodowanie(char* napis)
	{
		int dl = strlen(napis); //wyznaczenie liczby znaków

		for (int i = 0; i < dl - 1; i += 2) //przesuwamy się o dwa znaki
		//zamiana sąsiadujących znaków
		{
			char pom = napis[i];
			napis[i] = napis[i + 1]; 
			napis[i + 1] = pom;
		}
	}



int main()
{
	
	char tab[1001]; 

	cout << "Text: " << endl;
	cin.getline(tab, 1001);

	szyfruj(tab); 
	cout << "Po zaszyfrowaniu: " << tab << endl;

	deszyfruj(tab); 
	cout << "Po rozszyfrowaniu: " << tab << endl;







	
	return 0;
}




/*int wybor;
cout << "Wybierz Szyfrowanie " << endl;
cout << "[1] Szyfr Cezara" << endl;
cout << "[2] Szyfr przestawieniowy" << endl;
cout << "[3] Szyfr podstawieniowy " << endl;
cin >> wybor;*/



//char napis[100];

//cout << "Podaj napis do zaszyfrowania: ";
//cin.getline(napis, 100);

//cout << "Przed szyfrowaniem: ";
//cout << napis << endl;

//
//kodowanie(napis);

//cout << "Szyfrogram: ";
//cout << napis << endl;

//
//kodowanie(napis);

//cout << "Tekst jawny: ";
//cout << napis << endl;