#include "bag.h"

Bag::Bag() {
    bag_size = 10;
}

int Bag::get_bag_size() const {
    return this->bag_size;
}

void Bag::set_bag_size(const int set_size) {
    this->bag_size = set_size;
}