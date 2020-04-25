#pragma once
#include "GUI.h"
void GUI::componente() {
	QHBoxLayout *mainL = new QHBoxLayout;
	setLayout(mainL);

	QVBoxLayout *rightL = new QVBoxLayout;
	rightL->addWidget(tabel);

	QFormLayout* dataL = new QFormLayout;
	dataL->addRow("Id", idText);
	dataL->addRow("Descriere", descriereText);
	dataL->addRow("Programatori", programatoriText);
	dataL->addRow("Stare", stareText);
	
	QVBoxLayout *leftL = new QVBoxLayout;
	leftL->addLayout(dataL);

	QHBoxLayout *btnL = new QHBoxLayout;
	btnL->addWidget(cautaBtn);
	btnL->addWidget(adaugaBtn);
	btnL->addWidget(saveBtn);
	btnL->addWidget(loadBtn);

	leftL->addStretch();
	leftL->addLayout(btnL);
	mainL->addLayout(leftL);
	mainL->addLayout(rightL);
	QStringList tabelTitlu;
	tabelTitlu << "Id" << "Descriere" << "Programatori" << "Stare";
	tabel->setHorizontalHeaderLabels(tabelTitlu);

}

void GUI::semnale() {
	QObject::connect(adaugaBtn, &QPushButton::clicked, this, &GUI::adaugaGUI);
	QObject::connect(cautaBtn, &QPushButton::clicked, this, &GUI::cautaGUI);
	QObject::connect(saveBtn, &QPushButton::clicked, this, &GUI::saveGUI);
	QObject::connect(loadBtn, &QPushButton::clicked, this, &GUI::loadGUI);
	QObject::connect(tabel, &QTableWidget::itemSelectionChanged, this, &GUI::selection);
	
}

void GUI::updateTabel(QTableWidget* t, vector<Task>lista)
{
	int i = 0;
	t->setRowCount(lista.size());
	for (auto &el : lista) {
		QTableWidgetItem *id = new QTableWidgetItem(QString::number(el.get_id()));
		QTableWidgetItem *descriere = new QTableWidgetItem(QString::fromStdString(el.get_descriere()));
		QTableWidgetItem *programatori = new QTableWidgetItem(QString::number(el.get_programatori().size()));
		QTableWidgetItem *stare = new QTableWidgetItem(QString::fromStdString(el.get_stare()));
		t->setItem(i, 0, id);
		t->setItem(i, 1, descriere);
		t->setItem(i, 2, programatori);
		t->setItem(i, 3, stare);
		i++;
	}
}
void GUI::saveGUI() {
	serv.saveTask();
	updateTabel(tabel, serv.get());
}
void GUI::loadGUI() {
	serv.loadTask();
	updateTabel(tabel,serv.sortare(comparare));
}
void GUI::selection() {
	vector<Task>lista;
	lista = serv.get();
	for (int i = 0; i < tabel->rowCount(); i++) {
		if (tabel->item(i, 0)->isSelected()) {
			Task d = serv.cautaId(tabel->item(i, 0)->text().toInt());
			idText->setText(QString::number(d.get_id()));
			descriereText->setText(QString::fromStdString(d.get_descriere()));
			stareText->setText(QString::fromStdString(d.get_stare()));
			programatoriText->setText(QString::fromStdString(d.get_programatori2()));

		}
	}
}
void GUI::adaugaGUI() {
	int id = idText->text().toInt();
	string descriere = descriereText->text().toStdString();
	string stare = stareText->text().toStdString();
	string nume = programatoriText->text().toStdString();
	size_t i = 0;
	string one;
	vector<string>programatori;

	while ((i = nume.find(' ')) != string::npos) {
		one = nume.substr(0, i);
		programatori.push_back(one);
		nume.erase(0, i + 1);
	}
	programatori.push_back(nume);
	try {

		Task c{ id,descriere,stare,programatori };
		serv.adaugaEl(c);
		serv.saveTask();
		updateTabel(tabel, serv.sortare(comparare));
	}
	catch (ExceptionTask &e)
	{
		QMessageBox::warning(this, "Eroare", QString::fromStdString(e.getMsg()));
	}
}
void GUI::cautaGUI() {
	string cautat = programatoriText->text().toStdString();
	if (cautat!=""){
	vector<Task>lista1;
	lista1 = serv.cautaEl(cautat);
	if (lista1.size() > 0) {
		updateTabel(tabel, lista1);
	}
	else {
		vector<Task>lista2;
		updateTabel(tabel, lista2);
	}
	}
	else {
		vector<Task>lista1;
		updateTabel(tabel, lista1);
	}
}

GUI::~GUI() {

}