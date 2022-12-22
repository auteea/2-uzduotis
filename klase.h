#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      
#include <fstream>
#include <chrono>
#include<list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::list;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::left;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::remove;
using std::remove_if;
using std::remove_copy_if;

class Studentas
{
private:
	string Vard;
	string Pav;
	int  Egz;
	vector<int>Nd;
	float Gp;
	float Vid;
	float Med;
public:
	Studentas() {}

	Studentas(string vard, string pav, int egz, vector<int> nd) {
		Vard = vard;
		Pav = pav;
		Egz = egz;
		Nd = nd;
	};

	//copy konstruktirius
	Studentas(const Studentas& s) {
		Vard = s.Vard;
		Pav = s.Pav;
		Egz = s.Egz;
		Gp = s.Gp;
		Nd = s.Nd;
	}

	//copy priskyrimo operatorius
	Studentas& operator=(const Studentas& s) {
		if (&s == this) return *this;
		Vard = s.Vard;
		Pav = s.Pav;
		Egz = s.Egz;
		Gp = s.Gp;
		Nd = s.Nd;
		return *this;
	}

	/*Studentas(Studentas&& s) :
		vardas_{ s.vardas_ },
		pavard_{ s.pavard_ },
		egz_{ s.egz_ },
		galut_{s.galut_},
		nd_{ std::move(s.nd_) } {}
	Studentas(const Studentas&) = default;*/

	~Studentas() {}

	void Vidurkis() {
		float suma = accumulate(Nd.begin(), Nd.end(), 0);
		Vid = suma / size(Nd);
	}
	void Mediana() {
		std::sort(Nd.begin(), Nd.end());
		int size = Nd.size();
		if (size % 2 == 1)
			Med = float(Nd[size / 2]);
		else
			Med = (float(Nd[size / 2 - 1]) + float(Nd[size / 2])) / 2;
	}
	void Galutinis(string a) {
		if (a == "0")
			Gp = 0.4 * Med + 0.6 * Egz;
		else
			Gp = 0.4 * Vid + 0.6 * Egz;
	}
	float getVid() {
		return Vid;
	}
	vector<int> getNd() {
		return Nd;
	}
	float getGp() {
		return Gp;
	}
	string getVard() {
		return Vard;
	}
	string getPav() {
		return Pav;
	}
	float getMed() {
		return Med;
	}
	int getEgz() {
		return Egz;
	}
};

void KLASE(string ivestis, string duomenys, string isvedimas1, string isvedimas2);