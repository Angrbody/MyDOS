#include"student.h"
void student::update(int newScore){
    this->score = newScore;
    cout<<"new score = "<<newScore<<endl;
}

void student::kaoshi(){
    int mm = 60;
    cout<<"score before kaoshi"<<this->score<<endl;
    this->update(mm);
    cout<<"the normal score: "<<this->score<<endl;
    this->zuobi();
    cout<<"zuobihou score: "<<this->score<<endl;
}

void student::zuobi(){
    this->update(100);
    cout<<"zuobifenshu : "<<this->score<<endl;
}

void student::show(){
    std::cout<<"name: "<<student::name<<std::endl;
    std::cout<<"score: "<<student::score<<std::endl<<std::endl;
}