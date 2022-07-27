#include <vector>

using namespace std;


struct edge {
  int next_id, distance;
};

void print_graph(const vector<vector<edge>>&);
void fillin_graph(vector<vector<edge>>&, const int);
