#ifndef __MATERIEL__
#define __MATERIEL__
#include<iostream>
#include<vector>
#include"charactor.h"
//装备类
class materiel{
public:
    //构造函数
    materiel(int m_user_id, int m_type)
    :   user_id(m_user_id),
        type(m_type)
    {}
    //析构
    ~materiel(){}
    //交换装备
    void swapMateriel (materiel targetM){
        int temp_id = this->user_id;
        this->user_id = targetM.user_id;
        targetM.user_id = temp_id;
    };

private:
    int user_id;    //拥有者的id
    const int type;       //装备种类: 1:weapon, 2:armor
};

//武器类（继承materiel）
class weapon : public materiel{
public:
    // weapon(int m_attackDistance, int m_attack)
    // :   attackDistance(m_attackDistance),
    //     attck(m_attack),
    //     type(1)   
    // {}
private:
    int attackDistance; //攻击距离
    int attck;          //攻击力
    const int type;     //种类
};

//护甲类（继承materiel）
class armor : public materiel{
public:
    // armor(int m_armor)
    // :   myarmor(m_armor),
    //     type(2)
    // {}
private:
    int myarmor;         //护甲值
    const int type;      //种类
};
#endif