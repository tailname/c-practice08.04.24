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
    Deanary();
    ~Deanary();
    Deanary(const std::vector<Group*>& groups);
    void createGroups(const std::string& gr_file);
    void hireStudents(const std::string& st_file);
    void addMarksToAll(const Group& group);
    void getStatistics();
    void moveStudents(const std::vector<Student*> students, Group& group);
    void saveStaff(const std::string& up_file);
    void initHeads(Student& student);
    void fireStudents(const Student& student);

    bool ContainsGroup(const Group& group) const;
};

