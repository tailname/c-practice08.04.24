// Copyright 2014 Google Inc. All Rights Reserved.

#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "Group.h"
class Group;

class Student {
 private:
    uint32_t id;
    std::wstring fio;
    std::vector<int8_t> marks;
    Group* group;

 public:
    Student();
    Student(const uint32_t& id,
            const std::wstring& fio,
            Group* group = nullptr);

    void addToGroup(Group* group);
    void addmark(const int8_t& mark);
    float getAveragemark() const;
    bool isHeadOfGroup() const;

    uint32_t GetID() const;
    std::wstring GetFIO() const;
    std::vector<int8_t> GetMarks() const;
    Group* GetGroup() const;
};


#endif
