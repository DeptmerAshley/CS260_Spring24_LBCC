void Linked_List::insert(int value) {
    Node* inserting = new Node;
    inserting->value = value;

    if (this->head == NULL) {
        this->head = inserting;
        this->length += 1;
    } 
    else if(inserting->value <= this->head->value) {
        push_front(value);
    }
    else if (this->length == 1 && inserting->value >= this->head->value) {
        this->head->next_node = inserting;
        this->length += 1;
    }
    else {
        Node* hold = this->head;
        do {
            if (inserting->value < hold->next_node->value) {   
                break;
            }
            hold = hold->next_node;
            if (hold->next_node == NULL) {
                break;
            }
        } while (inserting->value > hold->next_node->value);
        inserting->next_node = hold->next_node;
        hold->next_node = inserting;
        this->length += 1;
    }
}

void Linked_List::search(int search_value) {
    Node* hold = this->head;
    for (int i = 0; i < this->length; i++) {
        if (search_value == hold->value) {
            cout << "Found: " << hold->value <<endl;
            break;
        }
        hold = hold->next_node;
    }
}


Almost completely revamped Insert function that can properly sort integers in an ascending order. 
A search function that finds a value in the list and outputs it to the terminal. If the value cannot
be found it says so and moves on. 
A remove function that searches for a given value and removes it. If not found it says so and moves on.

If the program does not fully execute (seg faults) plz run it again so that you may see the full output. 
Actively working on debugging this error.

My big O complexity should be completely linear.