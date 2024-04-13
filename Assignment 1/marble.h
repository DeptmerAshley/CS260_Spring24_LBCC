#ifndef MARBLE_H
#define MARBLE_H

#include <string>

using namespace std;

class Marble {
    private:
        string color;
        string size;
    public:
        Marble();       //Default Constructor

        //Accessor
        string get_marble_color() const;
        string get_marble_size() const;

        //Mutator
        void set_marble_color(const string);
        void set_marble_size(const string);
};


#endif