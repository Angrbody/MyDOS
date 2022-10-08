#include<iostream>
#include<vector>
#include"charactor.h"

int main(){
    charactor Phein(0, 4, 500, 1, "Phein");
    charactor Ross(1, 4, 400, 1, "Ross");
    charactor RedPrince(2, 4, 600, 1, "RedPrince");
    charactor Evan(3, 4, 500, 1, "Evan");
    charactor Saber(4, 4, 450, 1, "Saber");

    Phein.showMessage();
    Ross.showMessage();

    Phein.islevelUp();

    Phein.addFriend(Ross);
    Phein.addFriend(RedPrince);
    Phein.addFriend(Evan);
    Phein.addFriend(Saber);
    return 0;

}

