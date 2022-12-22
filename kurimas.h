#pragma once
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

void failo_kurimas(int nd_kiekis, int eilutes, string pav) {
	ofstream naujas_failas(pav);

	naujas_failas << left << setw(16) << "Vardas" << setw(16) << "Pavarde";
	for (int i = 1; i < nd_kiekis + 1; i++)	naujas_failas << setw(6) << "nd" + to_string(i);
	naujas_failas << setw(6) << "Egz." << endl;

	for (int i = 1; i < eilutes + 1; i++) {
		naujas_failas << left << setw(16) << "Vardas" + to_string(i) << setw(16) << "Pavarde" + to_string(i);
		for (int j = 1; j < nd_kiekis + 1; j++)	naujas_failas << setw(6) << rand() % 10 + 1;
		naujas_failas << setw(6) << rand() % 10 + 1 << endl;
	}
	naujas_failas.close();
};