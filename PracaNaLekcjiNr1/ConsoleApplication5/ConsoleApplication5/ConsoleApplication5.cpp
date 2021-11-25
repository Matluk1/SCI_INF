#include<iostream>
#include <algorithm>
#include<string>

using namespace std;



class szyfrowanie {
public:



	void szyfruj(char tab[])
	{
		int i = 0;
		while (tab[i])
		{
			if (tab[i] == 'x') tab[i] = 'a';
			if (tab[i] == 'y') tab[i] = 'b'; else
				if (tab[i] == 'z') tab[i] = 'c'; else
					if (tab[i] < 'x') tab[i] += 3;
			++i;
		}
	}
	void kodowanie(char* napis)
	{
		int dl = strlen(napis);

		for (int i = 0; i < dl - 1; i += 2)
		{
			char pom = napis[i];
			napis[i] = napis[i + 1];
			napis[i + 1] = pom;
		}
	}

	void szyfruj2(string& napis2, int k)
	{
		if (k > 26)k = k % 26;

		for (int i = 0; i < napis2.length(); i++)
		{
			if (napis2[i] == ' ')continue;
			napis2[i] += k;
			if (napis2[i] > 'Z') napis2[i] -= 26;

		}

	}
};


	class deszyfrowanie {
	public:
		void deszyfruj(char tab[])
		{
			int i = 0;
			while (tab[i])
			{
				if (tab[i] == 'a') tab[i] = 'x'; else
					if (tab[i] == 'b') tab[i] = 'y'; else
						if (tab[i] == 'c') tab[i] = 'z'; else
							if (tab[i] > 'c') tab[i] -= 3;
				++i;
			}
		}




	};


	
	int main()
	{
		szyfrowanie szyfr;
		deszyfrowanie deszyfr;
		
		
		int wybor;
		
		cout << "1:Szyfr Cezara"<<endl<<"2:Szyfr przestawieniowy"<<endl<<"3:Szyfr podstawieniowy " << endl;
		cin >> wybor;
	

		switch (wybor) {
		case 1: {
			cout << "SZYFR CEZARA" << endl;
			char tab[1001];

			cout << "Tekst do zaszyforwania  " << endl;
			cin.ignore(1, '\n');
			cin.getline(tab, 1001);

			szyfr.szyfruj(tab);
			cout << "Po zaszyfrowaniu: " << tab << endl;

			deszyfr.deszyfruj(tab);
			cout << "Po rozszyfrowaniu: " << tab << endl;



			break;
		}
		case 2: 

			cout << "SZYFR PRZESTAWIENIOWY" << endl;

			char napis[1001];

			cout << "Tekst do zaszyforwania  ";
			cin.ignore(1, '\n');
			cin.getline(napis, 1001);




			szyfr.kodowanie(napis);

			cout << "Po zaszyfrowaniu: ";
			cout << napis << endl;


			szyfr.kodowanie(napis);

			cout << "Po rozszyfrowaniu:  ";
			cout << napis << endl;

			break;
		case 3: 
			int klucz;

			cout << "SZYFR PODSTAWIENIOWY" << endl;
			string napis2;
			cout << "Tekst do zaszyforwania ";
			cin.ignore(1, '\n');
			getline(cin, napis2);

			transform(napis2.begin(), napis2.end(), napis2.begin(), ::toupper);

			cout << "Podaj klucz do szyfrowania : ";
			cin >> klucz;

			szyfr.szyfruj2(napis2, klucz);

			cout << napis2 << endl;
			break;
		}	
		return 0;
		}
