#ifndef __CHARACTOR__
#define __CHARACTOR__
#include<iostream>
#include<vector>
#include"skill.h"
#include"task.h"
#include"materiel.h"
using namespace std;

//人物类：后续应该会作为主角的继承
class charactor{
public:
    charactor(int m_id, int m_ap, int m_hp, int m_level, string m_name)
        : id(m_id), ap(m_ap), hp(m_hp), level(m_level), name(m_name)
    {
        expPool.resize(levelMax, 100);  //目前先将每一个等级的经验上线都设置为100
        isfriend.resize(100);   //最多设置100个npc
        exp = 0;                //经验归零
        //装备栏设置为 10×10
        mymateriel.resize(10);
        for(int i = 0; i<mymateriel.size(); i++){
            mymateriel[i].resize(10);
        }
    }
    //由id获得charator类
    charactor& getCharactor(){return *this;}
    
    //获得id,ap,hp,name
    int getID() const {return id;}
    int getAp() const {return ap;}
    int getHp() const {return hp;}
    string getName() const {return name;}

    //show message
    void showMessage();

    //升级操作(目前设置只有战斗结束后会加经验，后续应该还有任务触发)
    void islevelUp();

    //添加队友(上限为4)
    void addFriend(charactor R);

    //show your team
    void showTeam();

    //1v1 battle
    void setBattle(charactor R);    
    
private:
    const int levelMax = 18;    //最大等级固定18
    int id; //唯一id
    string name;    //人物名称
    int ap;  //行动点数
    int hp;  //生命
    int exp; //经验
    enum blood{human, elf, skull, dwarf};   //种族
    vector<int> expPool; //经验池，存放各个等级的最大经验值
    int level;   //等级
    vector<skill> myskill;  //技能列表，动态增加的
    vector<charactor> myfriend; //队友列表
    vector<task> mytask;    //任务列表
    vector<int> isfriend;   //敌对关系列表，负数代表敌对，100以上代表队友
    vector<vector<materiel>> mymateriel;   //装备（包含武器）
    //属性
    int armour; //护甲值

};

//show basic message
void charactor::showMessage(){
    cout<<"charactor message: "<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"id: "<<id<<endl;
    cout<<"hp: "<<hp<<endl;
    cout<<"exp: "<<exp<<endl<<endl;
}
//人物升级操作
void charactor::islevelUp (){
        // level = level >= levelMax ? level : level+1;
        cout<<name<<" is trying to level up!"<<endl;
        if(exp >= expPool[level] && level < levelMax){
            cout<<name<<" levelup! "<<endl;
            exp -= expPool[level];
            level++;
            //其他维度增长,暂时随便设置一下
            hp += 100;
        }
        else{
            cout<<name<<",you are too weak"<<endl<<endl;
        }
    }

//添加队友(单向,考虑修改)
void charactor::addFriend (charactor R){
    cout<<"you are inviting "<<R.name<<" into your team!"<<endl;
    int num = myfriend.size();
    if(num < 3){
        myfriend.emplace_back(R);
        // R.myfriend.emplace_back(*this); //有小bug，不知道要不要这样设计
        isfriend[R.id] = 101;
        cout<<R.name<<" is one of us now!"<<endl<<endl;
    }
    else{
        cout<<"sry "<<R.name<<" soilder's ready"<<endl<<endl;
    }
}

//展示队友列表
void charactor::showTeam(){
    int num = myfriend.size();
    cout<<name<<"'s team: "<<endl<<"["<<endl;
    cout<<"   "<<name<<"(myself)"<<endl;
    for(int i = 0; i<num; i++){
        cout<<"   "<<myfriend[i].name<<endl;
    }
    cout<<"              "<<"]"<<endl<<endl;
}

//1v1Battle system
void charactor::setBattle(charactor R){
    cout<<"the battle between "<<this->getName()<<" and"<<R.name<<" is going on!"<<endl;
    this->showMessage();
    R.showMessage();
    int myHp = this->getHp();
    int hisHp = R.hp;
    while(myHp > 0 && hisHp > 0){
        int myAct = 0;
        //1.这里后续应该比较先攻，先以myact优先，也先不考虑ap了，后续再实现
        //2.这里应该是展示你所拥有的技能组以及每个技能对应的操作数和效果
        cout<<"please choose your act mode, 1 for attack, 2 for defense, 3 for heal, else for nothing."<<endl;
        cin>>myAct;
        if(myAct == 1){hisHp -= 200;}   //随便设置一个攻击力
        else if(myAct == 3){myHp += 50;}    //随便设置一个回复

        //敌方操作
        myHp -= 100;    //随便设置一下

        cout<<"My hp now: "<<myHp<<endl<<"enemy's hp now: "<<hisHp<<endl;
    }
    if(myHp <= 0){cout<<"you lose the game !"<<endl;}
    if(hisHp <= 0){
        cout<<"winner is you !"<<endl;
        this->exp += 100;   //随便设置一个值作为获胜的奖励
        this->islevelUp();
    }
}
#endif