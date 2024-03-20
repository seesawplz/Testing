#include <iostream>
#include <vector>
#include <clocale>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct infa {
    string name;
    int vozr;
    string job;
    int prem[6];
    int sredpremia;
    void schetsredpremii() {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += prem[i];
        }
        sredpremia = sum / 6;
    }
};

void zad1(vector<infa>& worker) {
    setlocale(LC_ALL,"RU");
    for (int i = 0; i < worker.size(); i++) {
        worker[i].schetsredpremii();
        cout << "Работник " << i + 1 << " :" << worker[i].name << ", " << worker[i].vozr << " лет," << worker[i].job << ", " << "Средняя премия равна= " << worker[i].sredpremia << endl;
    }
}



void zad2(vector<infa>& mass, string dols) {
    bool f = false;
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i].job.find(dols) != -1) {
            cout << "ФИО " << mass[i].name << endl;
        }
        f = true;
    }
    if (!f) {
        cout << "sotrudnikov ne naideno" << endl;
    }
}
void zad3(vector<infa>& worker) {
    infa workern;
    cout << "Введите ФИО 6 работника: " << endl;
    cin.ignore();
    getline(cin, workern.name);
    cout << "Введите возраст 6 работника: " << endl;
    cin >> workern.vozr;
    cin.ignore();
    cout << "Введите должность 6 работника: " << endl;
    getline(cin, workern.job);
    cout << "Введите премии за полгода 6 работника: " << endl;
    for (int i = 0; i < 6; i++) {
        cin >> workern.prem[i];
    }
    workern.schetsredpremii();
    worker.push_back(workern);
    cout << "Работник 6: " << workern.name << ", " << workern.vozr << " лет," << workern.job << ", " << "Средняя премия равна= " << workern.sredpremia << endl;
}
void zad4(vector<infa>& worker, int num) {
    vector<infa>::iterator iter = worker.begin();
    worker.erase(iter + num - 1);
    for (int i = 0; i < 5; i++) {
        cout << worker[i].name << ", " << endl;
    }
}

bool sortaz(const infa& a, const infa& b) {
    return a.name < b.name;
}
bool sortza(const infa& a, const infa& b) {
    return a.name > b.name;
}
bool sortvozr(const infa& a, const infa& b) {
    return a.vozr < b.vozr;
}
bool sortsrprem110(const infa& a, const infa& b) {
    return a.sredpremia < b.sredpremia;
}
bool sortsrprem101(const infa& a, const infa& b) {
    return a.sredpremia > b.sredpremia;
}

vector <infa> workerscin(const string& filework) {
  
    ifstream file;
    file.open(filework);
    vector<infa>worker;
    if (file.is_open()) {
        infa workern;
   
        while (!file.eof()) {
            getline(file, workern.name);

            file >> workern.vozr;

            file>> workern.job;

            for (int i = 0; i < 6; i++) {
                file >> workern.prem[i];
            }

            workern.schetsredpremii();

            worker.push_back(workern);
            file.get();
        }
        file.close();
    }
    else {cout << "FILE IS CLOSED" << endl; }
    return worker;
}
void workerscout(vector<infa>& worker, const string& filework) {
    ofstream file1;
    file1.open(filework);
    if (file1) {
        for (int i = 0; i < worker.size(); i++) {
            file1<< "Работник " << i + 1 << " :" << worker[i].name << ", " << worker[i].vozr << " лет," << worker[i].job << ", " << "Средняя премия равна= " << worker[i].sredpremia << endl;
        }
        file1.close();
    }
}