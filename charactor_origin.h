//battleact 1.0，bug未修复时
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

    //update message
    void updateMessage(vector<int> newMessage) {//0.hp 1.ap 2.armor 3.wisdom 4.strength
        hp = newMessage[0];
        ap = newMessage[1];
        armor = newMessage[2];
        wisdom = newMessage[3];
        strength = newMessage[4];
    }

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
    vector<vector<int>> battleAct(charactor R);    

    //get battle message
    vector<int> getBattleMessage() const;
    
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
            //其他维度增长,暂时随便设置一下（后续应该修改为可选择加两点）
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
    cout<<"the battle between "<<this->getName()<<" and "<<R.name<<" is going on!"<<endl;
    this->showMessage();
    R.showMessage();
    // int &myHp = this->hp;
    // int &hisHp = R.hp;
    while(this->hp > 0 && R.hp > 0){
        //可能应该弄一个battle vector，把所有加入战斗的人放进来，暂时先弄1v1吧
        if(this->wisdom >= R.wisdom){
            vector<vector<int>> myact = this->battleAct(R); //这里其实重复操作了，不知道能不能修改，晚上测试一下(测试结果是可以深层调用的)
            this->updateMessage(myact[0]);
            R.updateMessage(myact[1]);
            cout<<this->name<<" hp now: "<<this->hp<<endl<<R.name<<" hp now: "<<R.hp<<endl;
            //敌方操作（需要修改）
            vector<vector<int>> hisact = R.battleAct(*this);
            R.updateMessage(hisact[0]);
            this->updateMessage(hisact[1]);
            cout<<this->name<<" hp now: "<<this->hp<<endl<<R.name<<" hp now: "<<R.hp<<endl;
        }
        else{
            //敌方操作
            vector<vector<int>> hisact = R.battleAct(*this);
            R.updateMessage(hisact[0]);
            this->updateMessage(hisact[1]);
            cout<<this->name<<" hp now: "<<this->hp<<endl<<R.name<<" hp now: "<<R.hp<<endl;
            //我方操作
            vector<vector<int>> myact = this->battleAct(R);
            this->updateMessage(myact[0]);
            R.updateMessage(myact[1]);
            cout<<this->name<<" hp now: "<<this->hp<<endl<<R.name<<" hp now: "<<R.hp<<endl;
        }
    }
    if(this->hp <= 0){cout<<"you lose the game !"<<endl;}
    if(R.hp <= 0){
        cout<<"winner is you !"<<endl;
        this->exp += 100;   //随便设置一个值作为获胜的奖励
        this->islevelUp();
    }

}

//获得battle需要的基本信息
std::vector<int> charactor::getBattleMessage() const{
    vector<int> res;
    res.push_back(hp);
    res.push_back(ap);
    res.push_back(armor);
    res.push_back(wisdom);
    res.push_back(strength);
    //后续再补充
    return res;
}

//封装每个角色的单次操作
vector<vector<int>> charactor::battleAct(charactor R){
    vector<int> mConfig = this->getBattleMessage(); //0.hp 1.ap 2.armor 3.wisdom 4.strength
    vector<int> rConfig = R.getBattleMessage();//0.hp 1.ap 2.armor 3.wisdom 4.strength
    vector<vector<int>> res;
    int myAct;
    cout<<"please choose your act mode, 1 for attack, 2 for defense, 3 for heal, else for nothing."<<endl;
    cin>>myAct;
    //attack
    if(myAct == 1){
        cout<<this->name<<" is attacking !"<<endl;
        int this_attack = mConfig[4]*10;
            if(this_attack > rConfig[2] > 0){
                this_attack -= rConfig[2];
                rConfig[2] = 0;
            }
            else if(this_attack <= rConfig[2]){
                this_attack = 0;
                rConfig[2] -= this_attack;
            }
            rConfig[0] -= this_attack;
            }   //力量决定的thisAttack

    //defense
    else if(myAct == 2){
        cout<<this->name<<" is intensing his sheild !"<<endl;
        mConfig[2] += 50;  //固定的加盾
    }

    //heal
    else if(myAct == 3){
        cout<<this->name<<" is trying to heal hisself !"<<endl;
        int this_heal = mConfig[3]*3; //智慧决定的回复
        if(mConfig[0] + this_heal <= this->hp){
            mConfig[0] += this_heal;
        }
        else{
            mConfig[0] = this->hp;
        }
    }
    res.emplace_back(mConfig);
    res.emplace_back(rConfig);
    return res;
}
#endif