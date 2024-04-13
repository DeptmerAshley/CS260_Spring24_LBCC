#include"bag.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

int main() {
    Bag user_bag;
    string user_pick;
    int user_bag_size;
    cout << "Would you like to set the size of the bag? (Y/N)\n";
    cin >> user_pick;
    if (user_pick == "Y" or "y")
    {
        cout << "\nWhat size is your bag?\n";
        cin >> user_bag_size;
        user_bag.set_bag_size(user_bag_size);
    }
    else if (user_pick == "N" or "n")
    {
        
    }
    else
    {
        return 0;
    }

    srand(time(0));
    for (int i = 0; i < user_bag.get_bag_size(); i++) 
    {
        cout << "6965969696969696969\n\n";
        int hold = rand() % 6;
        if (hold = 1) {
            string new_color  = "Black";
            user_bag.bag[i].set_marble_color(new_color);     
        }
        else if (hold = 2) {
            string new_color  = "Green";
            user_bag.bag[i].set_marble_color(new_color);     
        }
        else if (hold = 3) {
            string new_color  = "Blue";
            user_bag.bag[i].set_marble_color(new_color);     
        }
        else if (hold = 4) {
            string new_color  = "Purple";
            user_bag.bag[i].set_marble_color(new_color);     
        }
        else if (hold = 5) {
            string new_color  = "Red";
            user_bag.bag[i].set_marble_color(new_color);     
        }
    }

    for (int j = 0; j < user_bag.get_bag_size(); j++) 
    {
        int hold = rand() % 4;
        if (hold = 1) {
            string new_size  = "L";
            user_bag.bag[j].set_marble_size(new_size);     
        }
        else if (hold = 2) {
            string new_size  = "S";
            user_bag.bag[j].set_marble_size(new_size);     
        }
        else if (hold = 3) {
            string new_size  = "M";
            user_bag.bag[j].set_marble_size(new_size);     
        }
    }

    for (int k = 0; k < user_bag.get_bag_size(); k++) 
    {
        cout << user_bag.bag[k].get_marble_color() << "\n";
        cout << user_bag.bag[k].get_marble_size() << "\n\n";
    }
    //return 0;
}