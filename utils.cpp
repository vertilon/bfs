#include <iostream>
#include <vector>
#include "utils.h"


using namespace std;

void print_graph(const vector<vector<edge>>& nodes) {
  for(int i = 0; i < nodes.size(); ++i) {
    cout << "Node " << i + 1 << " edges(id(dst)): ";
    for(int j = 0; j < nodes[i].size(); ++j) {
      cout << nodes[i][j].next_id + 1 << "(" << nodes[i][j].distance << ")" << ", ";
    }
    cout << "\n";
  }
}

void fillin_graph(vector<vector<edge>>& nodes, const int connections_num) {
  for(int i = 0; i < connections_num; ++i) {
    int node_id, next_id, distance;
    cin >> node_id >> next_id >> distance;
    nodes[node_id - 1].push_back({next_id - 1, distance});
    nodes[next_id - 1].push_back({node_id - 1, distance});
  }
}
