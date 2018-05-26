#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>
#include <ctime>


using namespace std;

int power(int i)
{
	return pow(2, i);
}



int main()
{
	string bit;
	int bit_n;
	bool good();
	string only_ones[8] = {"1","1","1","1","1","1","1","1"};
	int mask_1;
	char z;
	int i;
	int licznik = 0;
	int licznik_caly=0;
	int changes;
	string binary;
	string binary_mask;
	bitset<8> parzystosc;
	double ile = 0;
	double blad = 0.1;
	double ilosc_bl=0;
	int znak_zmiana;

	//ifstream txt("SSS.txt", ios::binary);

	ifstream txt;
	txt.open("SSS.txt", ios::binary);

	ofstream txt_n;
	txt_n.open("SSS_n.txt", ios::binary);

	if (txt.good() == true)
	{
		cout << "Wszystko ok. Plik otwarty." << endl;
		//tu operacje na pliku
	}
	else cout << "Coœ z plikiem pierwotnym!" << endl;

	if (txt_n.good() == true)
	{
		cout << "Wszystko ok. Nowy plik otwarty." << endl;
		//tu operacje na pliku
	}
	else cout << "Coœ z plikiem docelowym!" << endl;
	cout << endl;

	//fstream txt;
	//txt.open("SSS.txt", ios::binary);


	//ofstream txt_n("SSSn.txt", ios::binary);//dla jednego yloby fstream bo jest z in of



	//---------------------------------------------------------------------------------------------------------------------//



	/*
	if (txt.good() == true)
	{
		while (!txt.eof())
		{
			getline(plik, linia);
			cout << linia << endl; //wyœwietlenie linii
		}
	}
	*/
	//bit_n = getchar();
	//txt >> bit_n;

/*
	char buffer[1];
	txt.read(buffer, 1);
	cout << buffer[0] << endl << endl;
	*/
	int ch;
	while ((ch = txt.get()) != EOF)
	{
		txt.seekg(-1, ios::cur);//indykator w lewo
		bit_n = txt.get();
		//istream & seekg(streamoff offset, ios_base::seekdir cur);// o ile i kierunek
		txt.seekg(-1, ios::cur);//indykator w lewo
		bit = txt.get();
		txt_n << bit; // T U   J E S T    B L A D
		txt_n.flush();
		cout << bit;




		binary = bitset<8>(bit_n).to_string();
		licznik = 0;
		ile += 1;

		for (i = 0; i < 8; i++)
		{
			mask_1 = power(i);

			binary_mask = bitset<8>(mask_1).to_string();
			parzystosc = bitset<8>(mask_1) & bitset<8>(bit_n);
			changes = (int)(parzystosc.to_ulong());

			if (changes > 0)
			{
				licznik += 1;
			}
			//cout << "Parzystosc" << endl;
			//cout << parzystosc << endl << endl;
		/*	if (i == 7) {
				cout << "Binarna maska" << endl;
				cout << binary_mask << endl << endl;
			}
			*/
		}
		//getline(txt, bit);
		//bit_n = stoi(bit);


		licznik = licznik % 2;
		//cout << licznik << " to liczba licznika" << endl << endl;




		if (licznik > 0)
		{
			//z = 1;
			//txt_n.write((char*)(&z), sizeof(z));
			//txt_n << "01";
			//txt_n.flush();
			licznik_caly += 1;
		}
		else if (licznik == 0)
		{
			//z = 0;
			//txt_n.write((char*)(&z), sizeof(z));
			//txt_n << "00";
			//txt_n.flush();
		}
		//txt_n.seekp(0, ios::cur);
		//txt_n.seekp(0, ios::end);
	}

	txt_n << "." << licznik_caly;


		cout << "Przed" << endl;
		cout << bit_n << endl << endl;
		cout << "Przed w stringu" << endl;
		cout << bit << endl << endl;
		cout << "Po" << endl;
		cout << binary << endl << endl;
		cout << "Suma jedynek" << endl;
		cout << licznik_caly << endl << endl;
	/*
	copy(
		istreambuf_iterator<char>(txt),
		istreambuf_iterator<char>(),
		ostreambuf_iterator<char>(txt_n));
		*/



	txt.seekg(0, ios::beg);
	ilosc_bl = ceil(ile*(blad / 100));
	cout << "Ilosc bledow to: " << ilosc_bl << endl;
	//0.1% to 0.1/100
	cout << ile << " ile" << endl << blad << " to blad" << endl;
	i = ile;
	
	srand(time(NULL));
	znak_zmiana = rand() % i;//dodac jeszcze liczba
	cout << znak_zmiana << endl;




	txt.close();
	txt_n.close();
/*
	ifstream bledne;
	bledne.open("SSS_n.txt", ios::binary);

	ofstream bledne_n;
	bledne_n.open("SSS.txt", ios::binary);




	bledne.close();
	bledne_n.close();
	*/
	system("PAUSE");
	return 0;
}