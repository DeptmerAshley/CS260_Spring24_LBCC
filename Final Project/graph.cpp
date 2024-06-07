#include "graph.h"

void Graph::add_vertex(const string& vertex) {
    adjacencyList[vertex] = vector<pair<string, int>>();
}

void Graph::add_edge(const string& vertex1, const string& vertex2, int weight) {
    adjacencyList[vertex1].push_back({vertex2, weight});
    adjacencyList[vertex2].push_back({vertex1, weight});
}

vector<string> Graph::shortest_path(const string& start, const string& end) {
    if (adjacencyList.find(start) == adjacencyList.end() || adjacencyList.find(end) == adjacencyList.end()) {
        return vector<string>();
    }

    map<string, int> distances;
    map<string, string> previous;
    vector<string> nodes;

    for (const auto& vertex : adjacencyList) {
        if (vertex.first == start) {
            distances[vertex.first] = 0;
        } else {
            distances[vertex.first] = INT_MAX;
        }
        nodes.push_back(vertex.first);
    }

    while (!nodes.empty()) {
        auto smallest = min_element(nodes.begin(), nodes.end(), [&](const string& lhs, const string& rhs) {
            return distances[lhs] < distances[rhs];
        });

        string u = *smallest;
        nodes.erase(smallest);

        if (u == end) {
            vector<string> path;
            while (previous.find(u) != previous.end()) {
                path.push_back(u);
                u = previous[u];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        if (distances[u] == INT_MAX) break;

        for (const auto& neighbor : adjacencyList[u]) {
            int alt = distances[u] + neighbor.second;
            if (alt < distances[neighbor.first]) {
                distances[neighbor.first] = alt;
                previous[neighbor.first] = u;
            }
        }
    }
    return vector<string>();
}

vector<pair<string, pair<string, int>>> Graph::min_span_tree() {
    vector<pair<string, pair<string, int>>> mst;
    vector<pair<int, pair<string, string>>> edges;

    for (const auto& vertex : adjacencyList) {
        for (const auto& neighbor : vertex.second) {
            edges.push_back({neighbor.second, {vertex.first, neighbor.first}});
        }
    }

    sort(edges.begin(), edges.end());

    map<string, string> parent;
    map<string, int> rank;

    for (const auto& vertex : adjacencyList) {
        parent[vertex.first] = vertex.first;
        rank[vertex.first] = 0;
    }

    for (const auto& edge : edges) {
        string u = edge.second.first;
        string v = edge.second.second;

        string root1 = find_set(parent, u);
        string root2 = find_set(parent, v);

        if (root1 != root2) {
            mst.push_back({u, {v, edge.first}});
            union_vertices(parent, rank, root1, root2);
        }
    }

    return mst;
}

string Graph::find_set(map<string, string>& parent, const string& vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find_set(parent, parent[vertex]);
    }
    return parent[vertex];
}

void Graph::union_vertices(map<string, string>& parent, map<string, int>& rank, const string& root1, const string& root2) {
    if (rank[root1] > rank[root2]) {
        parent[root2] = root1;
    } else if (rank[root1] < rank[root2]) {
        parent[root1] = root2;
    } else {
        parent[root2] = root1;
        rank[root1]++;
    }
}