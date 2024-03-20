#pragma once
#ifndef COUNTING_H
#define COUNTING_H
#include <vector>
#include <string>
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
void zad1(vector<infa>& worker);
void zad2(vector<infa>& mass, string dols);
void zad3(vector<infa>& worker);
void zad4(vector<infa>& worker, int num);
bool sortaz(const infa& a, const infa& b);
bool sortza(const infa& a, const infa& b);
bool sortvozr(const infa& a, const infa& b);
bool sortsrprem110(const infa& a, const infa& b);
bool sortsrprem101(const infa& a, const infa& b);
vector <infa> workerscin(const string& filework);
void workerscout(vector<infa>& worker, const string& filework);
#endif