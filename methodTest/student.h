#ifndef __STUDENT__
#define __STUDENT__
#include<string>
#include<iostream>
using namespace std;
class student{
public:
    student(string _name, int _score): name(_name), score(_score){}
    //default construction
    student(){
        std::cout<<"student is created"<<std::endl;
    }
    virtual ~student(){}
    void update(int newScore);

    void kaoshi();

    void zuobi();
private:
    string name;
    int score;
};

class gaoyi : public student{
    //子类没有定义构造函数则默认使用基类的default construction
    //问题：为啥基类设置了virtual destruction，main.cpp就不报错了？
};


#endif

