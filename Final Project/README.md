For the final project I will be designing a basic social networking system that defines nodes as users and connections between users for  the edges. There will be functions to add users, add connections and find the shortest path between friends. 

Complexity:
add_vertex: O(1)
add_edge: O(1)
shortest_path: O((n + x) log n)
min_span_tree: O(x log n)

int main() {
    cout << "Running Graph Tests...\n" << string(30, '=') << endl;
    test_add_vertex();
    test_add_edge();
    test_shortest_path();
    test_min_span_tree();
    cout << string(30, '=') << "\nTests completed.\n";

    return 0;
}

Running Graph Tests...
==============================
Test add_vertex: Pass
Test add_edge: Pass
Test shortest_path A to C: Pass
Test shortest_path C to A: Pass
Test min_span_tree: Pass
==============================
Tests completed.