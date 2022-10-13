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

    //battle act
    void battleAct(charactor R);    

    //get battle message
    vector<int> getBattleMessage();

    //update message
    void updateMessage(vector<int> newMessage);//0.hp 1.ap 2.armor 3.wisdom 4.strength
    
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
    //初始属性
    int armor = 0; //护甲值
    int wisdom = 10; //智慧
    int strength = 10; //力量
};
#endif