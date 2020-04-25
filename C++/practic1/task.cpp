#pragma once
#include "task.h"
Task::Task() {

}
Task::~Task() {

}

bool comparare(const Task&t1, const Task &t2) {
	return t1.get_stare() < t2.get_stare();
}