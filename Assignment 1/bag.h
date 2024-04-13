#ifndef BAG_H
#define BAG_H


#include <vector>
#include "marble.h"

using namespace std;

class Bag {
    private: 
        int bag_size;
        
    public:
        Bag();     //Default Constructor

        //Accessor
        int get_bag_size() const;
        Marble get_vector() const;

        //Mutator
        void set_bag_size(const int);

        vector<Marble> bag;
};



#endif