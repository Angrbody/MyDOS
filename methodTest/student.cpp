#include"student.h"
void student::update(int newScore){
    this->score = newScore;
    cout<<"new score = "<<newScore<<endl;
}

void student::kaoshi(){
    int mm = 100;
    cout<<"score before kaoshi"<<this->score<<endl;
    this->update(mm);
    cout<<"score after kaoshi"<<this->score<<endl;
}