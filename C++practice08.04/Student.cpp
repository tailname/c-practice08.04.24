#include"Student.h"


Student::Student(const uint32_t& id, const std::string& fio, Group* group) {
	this->id = id;
	this->fio = fio;
	this->group = group;
}
Student::Student() {
	group = nullptr;
}

void Student::addToGroup(Group& group) {
	this->group = &group;
}
void Student::addmark(const int8_t& mark) {
	marks.push_back(mark);
}
float Student::getAveragemark() const {
	float anser = 0;
	for (int i = 0; i < marks.size(); ++i) anser += marks[i];
	return anser / marks.size();
};
bool Student::isHeadOfGroup() const {
	if (group == nullptr)return false;
	if (group->GetheadID() == id) return true;
	return false;
}

uint32_t Student::GetID() const {
	return id;
}
std::string Student::GetFIO() const {
	return fio;
}
std::vector<int8_t> Student::GetMarks() const {
	return marks;
}
Group* Student::GetGroup() const {
	return group;
}