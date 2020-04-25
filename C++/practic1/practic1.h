#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_practic1.h"

class practic1 : public QMainWindow
{
	Q_OBJECT

public:
	practic1(QWidget *parent = Q_NULLPTR);

private:
	Ui::practic1Class ui;
};
