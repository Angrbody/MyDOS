#ifndef __CHARACTOR__
#define __CHARACTOR__
#include<iostream>
#include<vector>
#include"skill.h"
#include"task.h"
using namespace std;

//人物类：后续应该会作为主角的继承
class charactor{
public:
    charactor(int m_id, double m_ap, double m_hp, int m_level, string m_name)
        : id(m_id), ap(m_ap), hp(m_hp), level(m_level), name(m_name)
    {
        expPool.resize(levelMax);
        isfriend.resize(100);
    }
    //获得id,ap,hp
    int getID() const {return id;}
    int getAp() const {return ap;}
    int getHp() const {return hp;}

    //show message
    void showMessage();

    //升级操作(目前设置只有战斗结束后会加经验，后续应该还有任务触发)
    void islevelUp();

    //添加队友(上限为4)
    void addFriend(charactor c);
        
    
private:
    const int levelMax = 18;    //最大等级固定18
    int id; //唯一id
    string name;    //人物名称
    double ap;  //行动点数
    double hp;  //生命
    double exp; //经验
    vector<double> expPool; //经验池，存放各个等级的最大经验值
    int level;   //等级
    vector<skill> myskill;  //技能列表，动态增加的
    vector<charactor> myfriend; //队友列表
    vector<task> mytask;    //任务列表
    vector<int> isfriend;   //敌对关系列表，负数代表敌对，100以上代表队友
};

//show basic message
void charactor::showMessage(){
    cout<<"name: "<<name<<endl;
    cout<<"id: "<<id<<endl;
    cout<<"hp: "<<hp<<endl;
    cout<<"exp: "<<exp<<endl;
}
//人物升级操作
void charactor::islevelUp (){
        // level = level >= levelMax ? level : level+1;
        if(exp >= expPool[level] && level < levelMax){
            cout<<name<<" levelup! "<<endl;
            exp -= expPool[level];
            level++;
            //其他维度增长,暂时随便设置一下
            hp += 100;
        }
        else{
            cout<<"you are too weak to levelup!"<<endl;
        }
    }

//添加队友
void charactor::addFriend (charactor c){
    int num = myfriend.size();
    if(num < 3){
        myfriend.emplace_back(c);
        isfriend[c.id] = 101;
        cout<<c.name<<" is one of us now!"<<endl;
    }
    else{
        cout<<"sry, soilder's ready"<<endl;
    }
}

#endif