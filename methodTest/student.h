#ifndef __STUDENT__
#define __STUDENT__
#include<string>
#include<iostream>
using namespace std;
class student{
public:
    student(string _name, int _score): name(_name), score(_score){}
    void update(int newScore);

    void kaoshi();

    void zuobi();
private:
    string name;
    int score;
};


#endif

