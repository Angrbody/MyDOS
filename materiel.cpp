#include<iostream>
#include<vector>
#include<string>
#include"materiel.h"
#include"charactor.h"
void materiel::show(){
    std::cout<< "this materiel belongs to id: " << this->user_id << std::endl;
    std::cout<<"this is a ";
    if(this->type == 1){std::cout<<"weapon"<<std::endl;}
    else if(this->type == 2){std::cout<<"armor"<<std::endl;}
    //若想让每个子类以不同的方式复用基类中的方法该怎么实现？
}