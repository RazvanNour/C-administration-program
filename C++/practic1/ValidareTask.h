#include <exception>
#include "task.h"

class ValideazaTask {
public:
	void valid(const Task& t)const;
	ValideazaTask();
	~ValideazaTask();
};

class ExceptionTask {
private:
	string mesaj;
public:
	ExceptionTask(string mesaj) :mesaj{ mesaj } {};
	string getMsg()const { return mesaj; }
	~ExceptionTask() {};
};