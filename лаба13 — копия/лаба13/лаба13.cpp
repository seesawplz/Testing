#include <iostream>
#include <vector>
#include <clocale>
#include "Header.h"
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
   
    vector <infa> worker = workerscin("readworkers.txt"); 
    bool n = 1;
    while (n) {
        int num;
        cout << "Выберите номер задания: \n1. вывод всех работников\n2. поиск по части должности\n3. добавление сотрудникка\n4. удаление сотрудника\n5.сортировки\n";
        cin >> num;

        switch (num) {
        case 1: {
            //  задание1
            zad1(worker); break; }
        case 2: {
            //задание 2
            string dolzh;
            cout << "Введите часть должности " << endl;
            cin.ignore();
            getline(cin, dolzh);
            zad2(worker, dolzh); break; }
        case 3: {
            //задание 3  
            zad3(worker); break; }
        case 4: {
            //задание 4
            int num;
            cout << "Введите номер сотрудника, которого нужно удалить:" << endl;
            cin >> num;
            zad4(worker, num);
            break;
        }
        case 5: {
            cout << endl;
            //задание 5 сортировка по
            //az
            sort(worker.begin(), worker.end(), sortaz);
            for (int i = 0; i < 5; i++) {
                cout << worker[i].name << ", " << endl;
            }
            cout << endl;
            //za
            sort(worker.begin(), worker.end(), sortza);
            for (int i = 0; i < 5; i++) {
                cout << worker[i].name << ", " << endl;
            }
            cout << endl;
            //vozr
            sort(worker.begin(), worker.end(), sortvozr);
            for (int i = 0; i < 5; i++) {
                cout << worker[i].vozr << ", " << worker[i].name << ", " << endl;
            }
            cout << endl;
            //sred premia 1 10
            sort(worker.begin(), worker.end(), sortsrprem110);
            for (int i = 0; i < 5; i++) {
                cout << worker[i].sredpremia << ", " << worker[i].name << ", " << endl;
            }
            cout << endl;
            //sred premia 10 1
            sort(worker.begin(), worker.end(), sortsrprem101);
            for (int i = 0; i < 5; i++) {
                cout << worker[i].sredpremia << ", " << worker[i].name << ", " << endl;
            }
           break; }

        default: {n = 0; workerscout(worker, "C:\\Users\\HONOR\\Documents\\пары\\оаип\\лаба13 — копия\\readworkers.txt"); break; }

        }
    }
    return 0;
}
