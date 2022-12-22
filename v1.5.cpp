#include"studentas.h"
#include"kurimas.h"
#include"struktura.h"

void bendra(string ivestis, int nd, int eilutes)
{
	cout << "\n ----------K L A S E---------- \n";
	string duom_pav = to_string(eilutes) + "duomenu.txt";
	failo_kurimas(nd, eilutes, duom_pav);

	string vargsiukai_klase = to_string(eilutes) + "blogaklase.txt";
	string kietekai_klase = to_string(eilutes) + "geraklase.txt";
	auto start1 = std::chrono::high_resolution_clock::now();
	KLASE(ivestis, duom_pav, vargsiukai_klase, kietekai_klase);
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start1;
	cout << "\n VISAS LAIKAS: " << diff.count() << "\n \n";

	cout << "\n ----------S T R U K T U R A---------- \n";
	string vargsiukai_strukt = to_string(eilutes) + "blogastrukt.txt";
	string kietekai_strukt = to_string(eilutes) + "gerastrukt.txt";
	auto start2 = std::chrono::high_resolution_clock::now();
	STRUKTURA(ivestis, duom_pav, vargsiukai_strukt, kietekai_strukt);
	std::chrono::duration<double> diffl = std::chrono::high_resolution_clock::now() - start2;
	cout << "\n VISAS LAIKAS: " << diffl.count() << "\n \n";
	system("PAUSE");
};

int main() {

	int b;
	cout << "kiek namu darbu turi studentai? \n";
	cin >> b;
	while (cin.fail() || b < 0)
	{
		cout << "klaida, iveskite skaiciu  \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> b;
	}
	string ATS;
	cout << "ar su mediana ar su vidurkiu (mediana=0)\n";
	cin >> ATS;
	bendra(ATS, b, 10);
	//bendra(ATS, b, 1000000);
}