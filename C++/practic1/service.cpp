#pragma once
#include "service.h"
#include <algorithm>
#include <functional>
Service::Service() {

}

Service::~Service() {

}

void Service::adaugaEl(Task d) {
	v.valid(d);
	repo.adauga(d);
}

void Service::clear() {
	repo.clear();
}
vector<Task> Service::get() {
	return repo.getAll();
}

void Service::loadTask() {
	repo.citeste("task.txt");
}

void Service::saveTask() {
	std::ofstream fout("task.txt");
	vector<Task>lista = repo.getAll();
	for (auto& el : lista)
	{
		fout << to_string(el.get_id()) + ' ' + el.get_descriere() + ' '<<el.get_stare()+' '+to_string(el.get_programatori().size());
		vector<string>progr = el.get_programatori();
		for (auto& elem : progr)
			fout << ' '+elem;
		fout <<"\n";
	}
}
Task Service::cautaId(int id) {
	auto list = repo.getAll();
	Task t;
	for (auto &el : list)
	{
		if (el.get_id() == id)
		{
			t = el;
			break;
		}
	}

	return t;
}
int Service::lungime() {
	return repo.size();
}

vector<Task> Service::sortare(function<bool(Task,Task)>f ){
	vector<Task>lista;
	lista = repo.getAll();
	std::sort(lista.begin(), lista.end(), f);
	return lista;
}

vector<Task>Service::cautaEl(string producator) {
	return repo.cauta(producator);
}
