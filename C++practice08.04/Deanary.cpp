#include"Deanary.h"


Deanary::~Deanary() {
	for (int i = 0; i < groups.size(); ++i) {
		for (int j = 0; j < groups[i]->getStudents().size(); ++j) {
			delete groups[i]->getStudents()[j];
		}
		delete groups[i];
	}
}
Deanary::Deanary(const std::vector<Group*>& groups) {
	this->groups = groups;
}
void Deanary::createGroups(const std::string& gr_file) {
	std::ifstream ifs("groups.txt");
	if (ifs.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(ifs, line))
	{
		Group* group = new Group(line);
		groups.push_back(group);
	}
	ifs.close();
};
void Deanary::hireStudents(const std::string& st_file) {
	std::ifstream ifs("students.txt");
	if (ifs.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(ifs, line)) {
		std::stringstream ss(line);
		std::string first_name, second_name, third_name, name_group;
		uint32_t id;
		ss >> id >> first_name >> second_name >> third_name >> name_group;
		std::string fio = first_name + " " + second_name[0] + " " + third_name[0];
		Student* student = new Student(id, fio);
		std::string mark;
		while (ss>>mark) { student->addmark(stoi(mark)); };
		for (Group* group : groups) {
			if (group->GetGroupTitle() != name_group) continue;
			student->addToGroup(*group);
			group->addStudent(*student);
		}

	}
	ifs.close();
}
void Deanary::addMarksToAll(const Group& group) {
	for (int i = 0; i < group.getStudents().size(); ++i) {
		srand(time(0));
		group.getStudents()[i]->addmark(rand() % 10);
	}
}
void Deanary::addMarksToAll() {
	for (Group* group : groups) { addMarksToAll(*group); };
}
void Deanary::getStatistics() {
	setlocale(LC_ALL, "Rus");
	for (Group* group : groups) {
		std::cout << "Group name: " << group->GetGroupTitle() << std::endl;
		std::cout << "Number of students: " << group->getStudents().size() << std::endl;
		if (group->isEmpty()) return;
		if(group->GetheadID() !=-1) std::cout << "The head of group: " << group->GetheadID() << std::endl;
		std::cout << "The average mark in the group is: " << group->getAveragemark() << std::endl;
		std::cout << "Students of group \" " << group->GetGroupTitle() << " \": " << std::endl;
		for (Student* st : group->getStudents()) {
			std::cout << "ID: " << st->GetID() << " Name: " << st->GetFIO() << " Marks: ";
			for (int mark : st->GetMarks()) 
			{ std::cout << mark << " "; };
			std::cout << " Average mark of student: " << st->getAveragemark() << std::endl;
		}
	}
}
void Deanary::moveStudents(const std::vector<Student*> students, Group& group) {
	for (Student* student : students) {
		if (student->isHeadOfGroup()) student->GetGroup()->chooseHead();
		student->addToGroup(group);
	}
}
void Deanary::saveStaff() {
	std::ofstream out;
	out.open("students.txt");
	if (out.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	for (int i = 0; i < groups.size(); ++i) {
		for (int j = 0; j < groups[i]->getStudents().size(); ++j) {
			out << groups[i]->getStudents()[j]->GetFIO() << " " << groups[i]->GetGroupTitle();
			for (int k = 0; k < groups[i]->getStudents()[j]->GetMarks().size(); ++k) {
				out << " " << groups[i]->getStudents()[j]->GetMarks()[k];
			}
			out << std::endl;
		}
		
	}
	out.close();
	out.open("groups.txt");
	for (int i = 0; i < groups.size(); ++i) {
		out << groups[i]->GetGroupTitle() << std::endl;
	}
}
void Deanary::initHeads(Student& student) 
{ student.GetGroup()->chooseHead(student); }
void Deanary::fireStudents(const Student& student) {
	if (student.isHeadOfGroup()) student.GetGroup()->chooseHead();
	student.GetGroup()->removeStudent(student.GetID());
	delete &student;
};

bool Deanary::ContainsGroup(const Group& group) const {
	for (int i = 0; i < groups.size(); ++i) {
		if (groups[i]->GetGroupTitle() == group.GetGroupTitle()) return true;
	}
	return false;
}