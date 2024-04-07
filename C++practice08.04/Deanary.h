  // Copyright 2014 Google Inc. All Rights Reserved.
#pragma once
#define _CRT_RAND_S
#include <stdlib.h>
#include "Group.h"

#include <iostream>
#include <string>
#include <vector>
#include<locale>
#include<codecvt>
#include <sstream>
#include <fstream>



class Deanary {
 private:
    std::vector<Group*> groups;

 public:
    ~Deanary();
    Deanary() {}
    explicit Deanary(const std::vector<Group*>& groups);
    void createGroups();
    void hireStudents();
    void addMarksToAll(const Group& group);
    void addMarksToAll();
    void getStatistics();
    Group* GetGroup(const std::wstring& group) const;
    void moveStudents(const std::vector<Student*>& students, Group* group);
    void saveStaff();
    void initHeads();
    void fireStudents(const std::vector<Student*>& students);

    bool ContainsGroup(const Group& group) const;
    bool ContainsGroup(const std::wstring& group) const;
};

