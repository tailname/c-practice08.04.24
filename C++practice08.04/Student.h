#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "Group.h"





class Student {
 private:
    uint32_t id;
    std::string fio;
    std::vector<int8_t> marks;
    Group* group;

 public:
    Student();
    Student(const uint32_t& id, const std::string& fio, Group* group = nullptr);

    void addToGroup(Group& group);
    void addmark(const int8_t& mark);
    float getAveragemark() const;
    bool isHeadOfGroup() const;

    uint32_t GetID() const;
    std::string GetFIO() const;
    std::vector<int8_t> GetMarks() const;
    Group* GetGroup() const;

};



