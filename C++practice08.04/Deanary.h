#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>

#include "Group.h"

class Deanary {
 private:
    std::vector<Group*> groups;
  
 public:
    
    ~Deanary();
    Deanary() {};
    Deanary(const std::vector<Group*>& groups);
    void createGroups();
    void hireStudents();
    void addMarksToAll(const Group& group);
    void addMarksToAll();
    void getStatistics();
    void moveStudents(const std::vector<Student*> students, Group& group);
    void saveStaff();
    void initHeads(Student& student);
    void fireStudents(const Student& student);

    bool ContainsGroup(const Group& group) const;
};

