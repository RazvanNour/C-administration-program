#pragma once
#include "repository.h"
#include <functional>
#include "ValidareTask.h"
using namespace std;
class Service {
private:
	Repository repo;
	ValideazaTask v;
public:
	Service();
	Service(const Service &s) :repo{ s.repo }, v{ s.v } {};
	Service(const Repository&repo, ValideazaTask& v) :repo{ repo }, v{ v }{};
	void adaugaEl(Task d);
	vector<Task>get();
	int lungime();
	void loadTask();
	void saveTask();
	void clear();
	vector<Task>cautaEl(string programator);
	~Service();
	Task cautaId(int id);
	vector<Task> sortare(function<bool(Task, Task)>f);
};