#pragma once
#include "service.h"
#include <QtWidgets>
class GUI :public QWidget {
private:
	Service serv;
	QTableWidget *tabel = new QTableWidget{ 1,4 };
	QLabel *idTabel = new QLabel("Id task");
	QLabel *descriereTabel = new QLabel("Descriere task");
	QLabel *programatoriTabel = new QLabel("Programatori task");
	QLabel *stareTabel = new QLabel("Stare task");
	QLineEdit *idText = new QLineEdit;
	QLineEdit *descriereText = new QLineEdit;
	QLineEdit *programatoriText = new QLineEdit;
	QLineEdit *stareText = new QLineEdit;
	QPushButton *saveBtn = new QPushButton{ "Salvare fisier" };
	QPushButton *loadBtn = new QPushButton{ "Load din fisier" };
	QPushButton *cautaBtn = new QPushButton{ "Cauta task" };
	QPushButton *adaugaBtn = new QPushButton{ "Adauga task" };
	void componente();
	void semnale();
	void saveGUI();
	void loadGUI();
	void adaugaGUI();
	void cautaGUI();
	void selection();
	void updateTabel(QTableWidget *t, vector<Task>lista);
public:
	GUI(Service &serv) :serv{ serv } {
		setWindowIconText("Task-uri agentie");
		componente();
		semnale();
	};
	~GUI();
};