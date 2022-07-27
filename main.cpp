// Breadth First Search
//
//

#include <iostream>
#include <vector>
#include <queue>
#include "utils.h"

using namespace std;

struct NextEdge {
  int next_id, distance;
};

auto compare = [](NextEdge a, NextEdge b) {
  if(a.distance <= b.distance) return false;
  return true;
};

vector<int> shortestDistanceToNodes(const vector<vector<edge>>& nodes, int node_id) {
  priority_queue<NextEdge, vector<NextEdge>, decltype(compare)> edges_to_process(compare);
  edges_to_process.push({node_id, 0});

  vector<int> res(nodes.size(), -1);

  while(edges_to_process.size() > 0) {
    NextEdge current_edge = edges_to_process.top();
    edges_to_process.pop();

    if(res[current_edge.next_id] != -1) continue;

    res[current_edge.next_id] = current_edge.distance;

    for(int i = 0; i < nodes[current_edge.next_id].size(); ++i) {
      edges_to_process.push({nodes[current_edge.next_id][i].next_id, current_edge.distance + nodes[current_edge.next_id][i].distance});
    }
  }
  return res;
}

int main() {
  int nodes_num, connections_num, node_for_which_find_shortest_dst;
  cin >> nodes_num >> connections_num >> node_for_which_find_shortest_dst;
  node_for_which_find_shortest_dst--;
  vector<vector<edge>> nodes(nodes_num);

  fillin_graph(nodes, connections_num);
  print_graph(nodes);

  vector<int> res = shortestDistanceToNodes(nodes, node_for_which_find_shortest_dst);
  for(auto i : res) {
    cout << i << " ";
  }
  cout << "\n";
}
