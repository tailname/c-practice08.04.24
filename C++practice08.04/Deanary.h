#pragma once

#include <iostream>
#include <string>
#include <vector>
#include<locale>
#include<codecvt>
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
    Group* GetGroup(const std::wstring& group) const;
    void moveStudents(const std::vector<Student*> students, Group& group);
    void saveStaff();
    void initHeads();
    void fireStudents(const std::vector<Student*>& students);

    bool ContainsGroup(const Group& group) const;
    bool ContainsGroup(const std::wstring& group) const;
};

