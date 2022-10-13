#include<iostream>
#include<vector>
#include"charactor.h"

int main(){
    //主角团初始化
    charactor Phein(0, 4, 500, 1, "Phein");
    charactor Ross(1, 4, 400, 1, "Ross");
    charactor RedPrince(2, 4, 600, 1, "RedPrince");
    charactor Evan(3, 4, 500, 1, "Evan");
    charactor Saber(4, 4, 450, 1, "Saber");

    charactor zhubaba(5, 6, 100000, 1, "zhubaba");
    Phein.showMessage();
    Ross.showMessage();

    Phein.islevelUp();  //尝试升级->因经验不足失败

    //队友测试（beta）
    Phein.addFriend(Ross);
    Phein.addFriend(RedPrince);
    Phein.addFriend(Evan);
    Phein.addFriend(Saber); //队伍已满，无法加入saber
    
    Phein.showMessage();
    Phein.showTeam();   //四人小队

    Ross.addFriend(Phein);  //双向建立friend
    Ross.showTeam();    //Ross的两人小队（这个逻辑有问题，需要再想想）
    
    //开发battle系统(暂时先弄1v1)
    charactor expBabyA(6, 4, 400, 1, "expBabyA");
    Phein.setBattle(expBabyA);

    Phein.showMessage();
    system("pause");
    return 0;

}

