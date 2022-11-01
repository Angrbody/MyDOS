#ifndef __MATERIEL__
#define __MATERIEL__
#include<iostream>
#include<vector>
#include<string>
#include"charactor.h"
using namespace std;
//装备类
class materiel{
public:
    //构造函数
    materiel(int m_user_id, int m_type, string m_name)
    :   user_id(m_user_id),
        type(m_type),
        name(m_name)
    {}
    //default construction
    materiel(): user_id(-1), type(-1), name("")
    {}

    //析构
    virtual ~materiel(){}

    //交换装备
    void swapMateriel (materiel targetM){
        int temp_id = this->user_id;
        this->user_id = targetM.user_id;
        targetM.user_id = temp_id;
    }

    //更新拥有者id
    void updateMessage(int id){
        this->user_id = id;
    }

    //展示装备
    void show();

    //获得id,type,name
    const int& getID() const{return this->user_id;}
    const int& getType() const{return this->type;}
    const string& getName() const{return this->name;}
protected:
    int user_id;    //拥有者的id
    int type;       //装备种类: 1:weapon, 2:armor
    string name;    //装备名称
};

//武器类（继承materiel）
class weapon : public materiel{
public:
    weapon(int m_user_id, int m_type, string m_name, int m_attackDistance, int m_attack) : 
        materiel(m_user_id, m_type, m_name),
        attackDistance(m_attackDistance),
        attack(m_attack)
    {}
    //展示weapon信息
    void Wshow();

    int getAttack(){return attack;}
private:
    int attackDistance; //攻击距离
    int attack;          //攻击力
};

//护甲类（继承materiel）
class armor : public materiel{
public:
    armor(int m_user_id, int m_type, string m_name, int m_armor) : 
        materiel(m_user_id, m_type, m_name),
        myarmor(m_armor)
    {}
    //展示armor信息
    void Ashow();
    int getArmor(){return myarmor;}
private:
    int myarmor;         //护甲值
};
#endif