// C++practice08.04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <io.h>                      // для функции _setmode
#include <fcntl.h>   
#include <iostream>
#include"Deanary.h"
using namespace std;
int main() {
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	Deanary deanary;
    deanary.createGroups();
    deanary.hireStudents();
    deanary.getStatistics();
    deanary.addMarksToAll();
    wcout << L"Checking students after adding marks to all" << endl << endl;

    deanary.getStatistics();
    deanary.saveStaff();
    Student st1(6, L"Чехов Антон Павлович");
    wcout << deanary.ContainsGroup(L"23КНТ6") << endl;
    deanary.GetGroup(L"23КНТ6")->addStudent(st1);
    st1.addToGroup(*deanary.GetGroup(L"23КНТ6"));
    deanary.GetGroup(L"23КНТ6")->chooseHead(st1);
    st1.addmark(6);
    st1.addmark(3);

    wcout << endl;
    wcout << endl;
    wcout << endl;

    deanary.getStatistics();
    deanary.saveStaff();
    wcout << deanary.GetGroup(L"23КНТ6")->isEmpty() << endl;
    wcout << deanary.GetGroup(L"23КНТ6")->containsStudent(st1) << endl;

    Student st2(7, L"Ростов Николай Ильич");
    deanary.GetGroup(L"23КНТ5")->addStudent(st2);
    st2.addToGroup(*deanary.GetGroup(L"23КНТ5"));
    deanary.initHeads();
    deanary.GetGroup(L"23КНТ5")->chooseHead(st2);
    deanary.GetGroup(L"23КНТ6")->chooseHead(st1);
    st2.addmark(3);
    st2.addmark(7);
    st2.addmark(10);
    wcout << st2.isHeadOfGroup() << endl;
    wcout << deanary.GetGroup(L"23КНТ6")->getStudent(deanary.GetGroup(L"23КНТ6")->GetheadID())->GetFIO() << endl;
    wcout << deanary.GetGroup(L"23КНТ5")->getStudent(deanary.GetGroup(L"23КНТ5")->GetheadID())->GetFIO() << endl;


    wcout << endl;
    wcout << endl;
    wcout << endl;


    deanary.getStatistics();
    deanary.saveStaff();

    Student st3(8, L"Ме́лехов Григо́рий Пантеле́евич");
    deanary.GetGroup(L"23КНТ6")->addStudent(st3);
    st3.addToGroup(*deanary.GetGroup(L"23КНТ6"));
    deanary.addMarksToAll();
    deanary.getStatistics();
    vector<Student*>movsts;
    movsts.push_back(&st3);
    movsts.push_back(&st2);
    deanary.moveStudents(movsts , *deanary.GetGroup(L"23КНТ5"));//destroyed
    deanary.getStatistics();
    wcout << deanary.GetGroup(L"23КНТ6")->getStudent(st1.GetFIO())->GetFIO() << endl;
    deanary.GetGroup(L"23КНТ6")->removeStudent(st1.GetID());
    deanary.fireStudents(movsts);
    deanary.getStatistics();
    deanary.saveStaff();
    //deanary.Delete_St_Low_Mark();dont checking

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
