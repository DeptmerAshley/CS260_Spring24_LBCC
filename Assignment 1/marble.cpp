#include "marble.h"

Marble::Marble() {
    color = "red";
    size = "S";
}

string Marble::get_marble_color() const {
    return this->color;
}

string Marble::get_marble_size() const {
    return this->size;
}

void Marble::set_marble_color(const string set_color) {
    this->color = set_color;
}

void Marble::set_marble_size(const string set_size) {
    this->size = set_size;
}