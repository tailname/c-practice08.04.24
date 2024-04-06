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
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;

 public:
    Group(const std::string& group_title = "", const std::string& specialization = "", Student* head = nullptr);
    void addStudent( Student& student);
    void chooseHead(Student& student);
    void chooseHead();
    float getAveragemark() const;
    Student* getStudent(const uint32_t id) const;
    Student* getStudent(const std::string& full_title) const;
    bool containsStudent(const Student& student) const;
    void removeStudent(const uint32_t id);
    bool isEmpty() const;

    std::string GetGroupTitle() const;
    std::string GetSpecialization() const;
    int32_t GetheadID() const;
    std::vector<Student*> getStudents() const;
};
#endif // !_GROUP_H_

