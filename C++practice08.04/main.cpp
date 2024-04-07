  // Copyright 2014 Google Inc. All Rights Reserved.
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include"Deanary.h"

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    Deanary deanary;
    deanary.createGroups();
    deanary.hireStudents();
    deanary.getStatistics();
    deanary.addMarksToAll();
    std::wcout << L"Checking students after adding marks to all" << std::endl;

    deanary.getStatistics();
    deanary.saveStaff();
    Student st1(6, L"Чехов Антон Павлович");
    std::wcout << deanary.ContainsGroup(L"23КНТ6") << std::endl;
    deanary.GetGroup(L"23КНТ6")->addStudent(&st1);
    st1.addToGroup(deanary.GetGroup(L"23КНТ6"));
    deanary.GetGroup(L"23КНТ6")->chooseHead(&st1);
    st1.addmark(6);
    st1.addmark(3);

    std::wcout << std::endl;
    std::wcout << std::endl;
    std::wcout << std::endl;

    deanary.getStatistics();
    deanary.saveStaff();
    std::wcout << deanary.GetGroup(L"23КНТ6")->isEmpty() << std::endl;
    std::wcout << deanary.GetGroup(
                                   L"23КНТ6")->containsStudent(
                                   st1) << std::endl;

    Student st2(7, L"Ростов Николай Ильич");
    deanary.GetGroup(L"23КНТ5")->addStudent(&st2);
    st2.addToGroup(deanary.GetGroup(L"23КНТ5"));
    deanary.initHeads();

    st2.addmark(3);
    st2.addmark(7);
    st2.addmark(10);
    std::wcout << st2.isHeadOfGroup() << std::endl;
    std::wcout << deanary.GetGroup(
                              L"23КНТ6")->getStudent(
                              deanary.GetGroup(
                              L"23КНТ6")->GetheadID())->GetFIO() << std::endl;
    std::wcout <<
        deanary.GetGroup(
                         L"23КНТ5")->getStudent(
                         deanary.GetGroup(
                         L"23КНТ5")->GetheadID())->GetFIO() << std::endl;


    std::wcout << std::endl;
    std::wcout << std::endl;
    std::wcout << std::endl;


    deanary.getStatistics();
    deanary.saveStaff();

    Student st3(8, L"Ме́лехов Григо́рий Пантеле́евич");
    deanary.GetGroup(L"23КНТ6")->addStudent(&st3);
    st3.addToGroup(deanary.GetGroup(L"23КНТ6"));
    deanary.addMarksToAll();
    deanary.getStatistics();
    std::vector<Student*>movsts;
    movsts.push_back(&st3);
    movsts.push_back(&st2);
    deanary.moveStudents(movsts , deanary.GetGroup(L"23КНТ5"));
    deanary.getStatistics();
    std::wcout <<
        deanary.GetGroup(
                         L"23КНТ6")->getStudent(
                         st1.GetFIO())->GetFIO() << std::endl;
    deanary.GetGroup(L"23КНТ6")->removeStudent(st1.GetID());
    deanary.fireStudents(movsts);
    deanary.getStatistics();
    deanary.saveStaff();
}
