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

    void show();
private:
    string name;
    int score;
};

//高一学生
class gaoyi : public student{
    //子类没有定义构造函数则默认使用基类的default construction
    //问题：为啥基类设置了virtual destruction，main.cpp就不报错了？
public:
    gaoyi():tiyu(10){
        std::cout<<"gaoyi student is created"<<std::endl;
    }
    gaoyi(const int m_tiyu):tiyu(m_tiyu){}

    void gaoyikaoshi();
    const int getTiyu() const{
        return tiyu;
    }
private:
    const int tiyu; //体育加分
};
// const int gaoyi::tiyu = 10;

//高二学生
class gaoer : public student{
public:
    gaoer():jingsai(20){
        std::cout<<"gaoer student is created"<<std::endl;
    }
    gaoer(const int m_jingsai):jingsai(m_jingsai){}
    void gaoerkaoshi();
    const int getJingsai() const{
        return jingsai;
    }
private:
    const int jingsai;  //竞赛加分
};
// const int gaoer::jingsai = 20;

#endif

