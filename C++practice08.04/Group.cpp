  // Copyright 2014 Google Inc. All Rights Reserved.
#include"Group.h"


Group::Group(const std::wstring& group_title,
             const std::wstring& specialization,
             Student* head) {
    title = group_title;
    this->spec = specialization;
    this->head = head;
}
void Group::addStudent(Student* student) {
    students.push_back(student);
}
void Group::chooseHead(Student* student) {
    head = student;
}
void Group::chooseHead() {
    if (students.size() > 1) {
        head = students[1];
    } else {
        head = nullptr;
    }
}
float Group::getAveragemark() const {
    float anser = 0;
    if (students.size() == 0) return 0;
    for (int i = 0; i < students.size(); ++i)
        anser += students[i]->getAveragemark();
    return anser / students.size();
}
Student* Group::getStudent(const uint32_t id) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->GetID() == id) return students[i];
    }
    return nullptr;
}
Student* Group::getStudent(const std::wstring& full_title) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->GetFIO() == full_title) return students[i];
    }
    return nullptr;
}
bool Group::containsStudent(const Student& student) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->GetID() == student.GetID()) return true;
    }
    return false;
}
void Group::removeStudent(const uint32_t id) {
     for (int i = 0; i < students.size(); ++i) {
        if (students[i]->GetID() == id) {
            Group* tem_gr = nullptr;
            students[i]->addToGroup(tem_gr);
            students.erase(students.begin() + i);
        }
    }
}
bool Group::isEmpty() const {
    if (students.empty() == false)return false;
    return true;
}

std::wstring Group::GetGroupTitle() const {
    return title;
}
std::wstring Group::GetSpecialization() const {
    return spec;
}
int32_t Group::GetheadID() const {
    if (head == nullptr) return -1;
    return head->GetID();
}
std::vector<Student*> Group::getStudents() const {
    return students;
}
