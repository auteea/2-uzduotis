#include "studentas.h"

void Isvedimas(vector<Studentas> a, string ivestis, string isvedimas) {

	ofstream f1(isvedimas);

	f1 << left << setw(20) << "Vardas " << setw(20) << "Pavarde";
	if (ivestis == "0")
		f1 << setw(20) << "Galutinis (med)" << endl;
	else
		f1 << setw(20) << "Galutinis (vid)" << endl;

	for (auto& d : a)
		f1 << left << setw(20) << d.getVard() << setw(20) << d.getPav() << setw(6) << d.getGp() << endl;

	a.clear();
	f1.close();
};
void KLASE(string ivestis, string duomenys, string isvedimas1, string isvedimas2) {
	vector<Studentas> Grupe;
	string vardai, pavardes, temp, egzaminas;
	vector<string> Nd;
	int m;
	ifstream file(duomenys);
	try {
		if (!file.good()) {
			throw duomenys;
		}

		auto START = std::chrono::high_resolution_clock::now();
		file >> vardai >> pavardes >> temp;
		while (temp != "Egz.") {
			Nd.push_back(temp);
			file >> temp;
		}
		egzaminas = temp;
		m = Nd.size();
		while (!file.eof()) {
			string Vardas, Pavarde;
			file >> Vardas >> Pavarde;
			double studpaz;
			vector<int>ND;
			ND.reserve(m);
			for (int i = 0; i < m; i++) {
				file >> studpaz;
				ND.push_back(studpaz);
			}
			int Egz;
			file >> Egz;
			Studentas Stud(Vardas, Pavarde, Egz, ND);
			Stud.Vidurkis();
			Stud.Mediana();
			Stud.Galutinis(ivestis);
			Grupe.push_back(Stud);
		}
		file.close();

		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - START;
		cout << Grupe.size() - 1 << " (namu darbu: " << m << ") failo nuskaitymo laikas: "
			<< diff.count() << endl;
		vector<Studentas> Varg;
		Varg.reserve(Grupe.capacity());

		START = std::chrono::high_resolution_clock::now();

		int Grupes_dydis = Grupe.size() - 1;

		for (int i = 0; i < Grupe.size(); i++) {
			if (Grupe[i].getGp() < 5.0) {
				Varg.push_back(Grupe[i]);
			}
		}
		Grupe.erase(remove_if(Grupe.begin(), Grupe.end(), [](Studentas x) {
			return x.getGp() < 5.0;	}), Grupe.end());

		diff = std::chrono::high_resolution_clock::now() - START;
		cout << Grupes_dydis << " (namu darbu: " << m << ") failo duomenu surusiavimas i kietekus ir vargselius : "
			<< diff.count() << endl;

		START = std::chrono::high_resolution_clock::now();

		Isvedimas(Varg, ivestis, isvedimas1);
		Isvedimas(Grupe, ivestis, isvedimas2);

		diff = std::chrono::high_resolution_clock::now() - START;
		cout << Grupes_dydis << " (namu darbu: " << m << ") failo duomenu surasymas i rezultatu failus : "
			<< diff.count() << endl;
	}

	catch (string pav) {
		cout << pav << " failas nerastas arba negalima atidaryti \n";
	}
}