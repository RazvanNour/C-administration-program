#include "practic1.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	ValideazaTask v;
	Service serv(repo,v);
	GUI gui{ serv };
	gui.show();
	return a.exec();
}
