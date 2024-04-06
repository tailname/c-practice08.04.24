#pragma once

#ifndef _GROUP_H_
#define _GROUP_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "Student.h"
class Student;

class Group {
 private:
    std::wstring title;
    std::wstring spec;
    std::vector<Student*> students;
    Student* head;

 public:
    Group(const std::wstring& group_title = L"", const std::wstring& specialization = L"", Student* head = nullptr);
    void addStudent( Student& student);
    void chooseHead(Student& student);
    void chooseHead();
    float getAveragemark() const;
    Student* getStudent(const uint32_t id) const;
    Student* getStudent(const std::wstring& full_title) const;
    bool containsStudent(const Student& student) const;
    void removeStudent(const uint32_t id);
    bool isEmpty() const;

    std::wstring GetGroupTitle() const;
    std::wstring GetSpecialization() const;
    int32_t GetheadID() const;
    std::vector<Student*> getStudents() const;
};
#endif // !_GROUP_H_

