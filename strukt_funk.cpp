#include"strukt.h"

void isvedimas(vector<studentas> a, string ivestis, string isvedimas) {

	ofstream f1(isvedimas);

	f1 << left << setw(20) << "Vardas " << setw(20) << "Pavarde";
	if (ivestis == "0")
		f1 << setw(20) << "Galutinis (med)" << endl;
	else
		f1 << setw(20) << "Galutinis (vid)" << endl;

	for (auto& d : a)
		f1 << left << setw(20) << d.Vard << setw(20) << d.Pav << setw(6) << d.GP << endl;

	a.clear();
	f1.close();
};

void STRUKTURA(string ivestis, string duomenys, string isvedimas1, string isvedimas2) {
	vector<studentas> grupe;
	studentas stud;
	string pav = "";
	string vardai, pavardes, temp, egzaminas;
	vector<string> nd;
	int m;
	ifstream file(duomenys);
	try {
		if (!file.good()) {
			throw duomenys;
		}

		auto start = std::chrono::high_resolution_clock::now();
		file >> vardai >> pavardes >> temp;
		while (temp != "Egz.") {
			nd.push_back(temp);
			file >> temp;
		}
		egzaminas = temp;
		m = nd.size();
		stud.nd.reserve(m);
		while (!file.eof()) {
			studentas stud;
			file >> stud.Vard >> stud.Pav;
			double studpaz;
			for (int i = 0; i < m; i++) {
				file >> studpaz;
				stud.nd.push_back(studpaz);
			}
			file >> stud.egz;
			if (ivestis == "0") {
				if (m != 0) {
					std::sort(stud.nd.begin(), stud.nd.end());
					if (m % 2 == 1) {
						stud.med = float(stud.nd[m / 2]);
						stud.GP = 0.4 * stud.med + 0.6 * stud.egz;
					}

					else {
						stud.med = (float(stud.nd[m / 2 - 1]) + float(stud.nd[m / 2])) / 2;
						stud.GP = stud.med * 0.4 + 0.6 * stud.egz;
					}

				}
			}
			else {
				if (m == 0) {
					stud.GP = stud.egz * 0.6;
				}
				else {
					float vid = float(accumulate(stud.nd.begin(), stud.nd.end(), 0)) / float(m);
					stud.GP = vid * 0.4 + 0.6 * stud.egz;
				}
			}
			grupe.push_back(stud);
			stud.nd.clear();

		}
		file.close();
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
		cout << grupe.size() - 1 << " (namu darbu: " << m << ") failo nuskaitymo laikas: "
			<< diff.count() << endl;

		vector<studentas> vargseliai;
		vargseliai.reserve(grupe.capacity());

		start = std::chrono::high_resolution_clock::now();

		int grupes_dydis = grupe.size() - 1;

		for (int i = 0; i < grupe.size(); i++) {
			if (grupe[i].GP < 5.0) {
				vargseliai.push_back(grupe[i]);
			}
		}
		grupe.erase(remove_if(grupe.begin(), grupe.end(), [](studentas x) {
			return x.GP < 5.0;	}), grupe.end());

		diff = std::chrono::high_resolution_clock::now() - start;
		cout << grupes_dydis << " (namu darbu: " << m << ") failo duomenu surusiavimas i kietekus ir vargselius : "
			<< diff.count() << endl;

		start = std::chrono::high_resolution_clock::now();

		isvedimas(vargseliai, ivestis, isvedimas1);
		isvedimas(grupe, ivestis, isvedimas2);

		diff = std::chrono::high_resolution_clock::now() - start;
		cout << grupes_dydis << " (namu darbu: " << m << ") failo duomenu surasymas i rezultatu failus : "
			<< diff.count() << endl;
	}

	catch (string pav) {
		cout << pav << " failas nerastas arba negalima atidaryti \n";
	}
}