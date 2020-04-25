#pragma once
#include "repository.h"
#include <functional>
Repository::Repository() {

}
Repository::~Repository() {

}

void Repository::adauga(Task c) {
	lista.push_back(c);
}

vector<Task> Repository::cauta(string programator) {
	vector<Task>rezultat;
	for (auto &el : lista) {
		vector<string>lista_noua = el.get_programatori();
		for (auto &s : lista_noua) {
			if (s.find(programator)!=string::npos)
				rezultat.push_back(el);
		}
	}
	return rezultat;
}

vector<Task>Repository::getAll() {
	return lista;
}

void Repository::clear() {
	lista.clear();
}

int Repository::size() {
	return lista.size();
}

void Repository::citeste(string nume_fisier) {
	clear();
	std::ifstream fin(nume_fisier);
	int id, nr;
	string descriere, stare,nume;
	while (fin >> id >> descriere >> stare >> nr) {
		vector<string>programatori(nr);
		int k = 0;
		while (k < nr) {
			fin >> nume;
			programatori[k] = nume;
			k++;
		}
		Task t{ id,descriere,stare,programatori };
		adauga(t);
	}
}

