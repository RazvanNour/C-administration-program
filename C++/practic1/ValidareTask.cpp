#include"ValidareTask.h"
ValideazaTask::ValideazaTask() {

}

ValideazaTask::~ValideazaTask() {

}

void ValideazaTask::valid(const Task &t)const {
	string erori = "";
	if (t.get_id() <= 0)
		erori += "id invalid\n";
	if (t.get_descriere() == "")
		erori += "descriere invalida\n";
	if (t.get_stare() != "open"&&t.get_stare() != "inprogress"&&t.get_stare() != "close")
		erori += "stare invalida\n";
	if (t.get_programatori().size() < 1 || t.get_programatori().size() > 4)
		erori += "numar de programatori invalid\n";
	if (erori != "")
		throw ExceptionTask{ erori };
}