#include"student.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    student A("xiaoming", 0);
    A.show();
    // A.kaoshi();
    std::vector<student*> Aclass;
    //测试基类指针控制子类
    student* stu = new gaoyi;
    student* stu2 = new gaoer;
    Aclass.push_back(stu);
    Aclass.push_back(stu2);
    
    gaoyi* newStu = dynamic_cast<gaoyi*>(stu);
    gaoer* newStu2 = dynamic_cast<gaoer*>(stu2);
    A.update(newStu->getTiyu() + newStu2->getJingsai());
    A.show();

    //测试基类容器存放不同子类：可以存，但是会被隐式转换为base class
    std::vector<student*> Bclass;
    Bclass.push_back(newStu);
    Bclass.push_back(newStu2);
    
    system("pause");
    return 0;
}