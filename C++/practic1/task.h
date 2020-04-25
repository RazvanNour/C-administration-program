#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
class Task {
private:
	int id;
	string descriere, stare;
	vector<string> programatori;
public:
	Task(int id, string descriere, string stare, vector<string>programatori) :id{ id }, descriere{ descriere }, stare{ stare }, programatori{ programatori }{};
	Task(const Task &ot) :id{ ot.id }, descriere{ ot.descriere }, stare{ ot.stare }, programatori{ ot.programatori }{};
	Task();
	int get_id()const { return id; }
	string get_descriere()const { return descriere; }
	string get_stare()const { return stare; }
	vector<string> get_programatori()const { return programatori; }
	string get_programatori2()const {
		string total;
		total = programatori[0];
		for (int i = 1; i < programatori.size(); i++)
			total += " " + programatori[i];
		return total;
	}
	void set_id(int id_nou) { id = id_nou; }
	void set_descriere(string descriere_noua) { descriere = descriere_noua; }
	void set_stare(string stare_noua) { stare = stare_noua; }
	void set_programatori(vector<string>programatori_noi) { programatori = programatori_noi; }

	~Task();
};
bool comparare(const Task &t1, const Task &t2);