#pragma once
#include <vector>
#include "task.h"
#include <fstream>
class Repository {
private:
	vector <Task>lista;
public:
	Repository();
	Repository(const Repository &ot) :lista(ot.lista) {};
	void adauga(Task c);
	vector<Task> cauta(string programator);
	vector <Task>getAll();
	int size();
	void citeste(string nume_fisier);
	void clear();
	~Repository();
};