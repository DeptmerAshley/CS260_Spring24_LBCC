#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>

using namespace std;

class Graph {
public:
    void add_vertex(const string& vertex);

    void add_edge(const string& vertex1, const string& vertex2, int weight);

    vector<string> shortest_path(const string& start, const string& end);

    vector<pair<string, pair<string, int>>> min_span_tree();

private:
    map<string, vector<pair<string, int>>> adjacencyList;

    string find_set(map<string, string>& parent, const string& vertex);

    void union_vertices(map<string, string>& parent, map<string, int>& rank, const string& root1, const string& root2);
};
#endif