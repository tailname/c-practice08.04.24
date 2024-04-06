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
void Deanary::createGroups() {
	std::wifstream ifs("groups.txt");
	if (ifs.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	std::wstring line;
	while (std::getline(ifs, line))
	{
		Group* group = new Group(line);
		groups.push_back(group);
	}
	ifs.close();
};
void Deanary::hireStudents() {
	std::wifstream ifs("students.txt");
	if (ifs.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	std::wstring line;
	while (std::getline(ifs, line)) {
		std::wstringstream ss(line);
		std::wstring first_name, second_name, third_name, name_group;
		uint32_t id;
		ss >> id >> first_name >> second_name >> third_name >> name_group;
		std::wstring fio = first_name + L" " + second_name[0] + L" " + third_name[0];
		Student* student = new Student(id, fio);
		std::wstring mark;
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
		std::wcout << L"Group name: " << group->GetGroupTitle() << std::endl;
		std::wcout << L"Number of students: " << group->getStudents().size() << std::endl;
		if (group->isEmpty()) return;
		if(group->GetheadID() !=-1) std::wcout << L"The head of group: " << group->GetheadID() << std::endl;
		std::wcout << L"The average mark in the group is: " << group->getAveragemark() << std::endl;
		std::wcout << L"Students of group \" " << group->GetGroupTitle() << L" \": " << std::endl;
		for (Student* st : group->getStudents()) {
			std::wcout << "ID: " << st->GetID() << " Name: " << st->GetFIO() << " Marks: ";
			for (int mark : st->GetMarks()) 
			{ std::wcout << mark << " "; };
			std::wcout << " Average mark of student: " << st->getAveragemark() << std::endl;
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
	std::ofstream fs;
	fs.open("students.txt", std::ios::ate |std::ios::out | std::ios::binary);

	unsigned char smarker[2];
	smarker[0] = 0x31;
	smarker[1] = 0x20;

	fs << smarker;
	fs.close();
	std::wofstream out;
	out.open("students.txt",std::ios::app);
	if (out.is_open() == false) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	for (int i = 0; i < groups.size(); ++i) {
		for (int j = 0; j < groups[i]->getStudents().size(); ++j) {
			out << groups[i]->getStudents()[j]->GetFIO() << L" " << groups[i]->GetGroupTitle();
			for (int k = 0; k < groups[i]->getStudents()[j]->GetMarks().size(); ++k) {
				out << L" " << groups[i]->getStudents()[j]->GetMarks()[k];
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