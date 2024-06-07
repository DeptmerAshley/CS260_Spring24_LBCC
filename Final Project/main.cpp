#include "graph.h"

void print_test_result(const string& test_name, bool result) {
    cout << test_name << ": " << (result ? "Pass" : "Fail") << endl;
}

void test_add_vertex() {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("B");

    print_test_result("Test add_vertex", !g.shortest_path("A", "B").empty());
}

void test_add_edge() {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_edge("A", "B", 1);

    print_test_result("Test add_edge", !g.shortest_path("A", "B").empty());
}

void test_shortest_path() {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_edge("A", "B", 1);
    g.add_edge("B", "C", 2);

    auto path1 = g.shortest_path("A", "C");
    auto path2 = g.shortest_path("C", "A");

    bool result1 = (path1 == vector<string>({"A", "B", "C"}));
    bool result2 = (path2 == vector<string>({"C", "B", "A"}));

    print_test_result("Test shortest_path A to C", result1);
    print_test_result("Test shortest_path C to A", result2);
}

void test_min_span_tree() {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_edge("A", "B", 1);
    g.add_edge("B", "C", 2);
    g.add_edge("C", "D", 3);
    g.add_edge("D", "A", 4);
    g.add_edge("A", "C", 5);

    auto mst = g.min_span_tree();
    set<pair<string, string>> expected = {{"A", "B"}, {"B", "C"}, {"C", "D"}};

    set<pair<string, string>> mst_set;
    for (const auto& [u, vw] : mst) {
        mst_set.insert({u, vw.first});
    }

    print_test_result("Test min_span_tree", mst_set == expected);
}

int main() {
    cout << "Running Graph Tests...\n" << string(30, '=') << endl;
    test_add_vertex();
    test_add_edge();
    test_shortest_path();
    test_min_span_tree();
    cout << string(30, '=') << "\nTests completed.\n";

    return 0;
}