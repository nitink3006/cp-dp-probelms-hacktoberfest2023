#include <queue>

using namespace std;

struct Node {
  int id;
  int cost;

  bool operator<(const Node& other) const {
    return cost > other.cost;
  }
};

vector<vector<int>> graph;
vector<bool> visited;
priority_queue<Node> queue;

int ucs(int source, int goal) {
  visited[source] = true;
  queue.push({source, 0});

  while (!queue.empty()) {
    Node node = queue.top();
    queue.pop();

    if (node.id == goal) {
      return node.cost;
    }

    for (int neighbor : graph[node.id]) {
      if (!visited[neighbor]) {
        int new_cost = node.cost + 1;
        queue.push({neighbor, new_cost});
        visited[neighbor] = true;
      }
    }
  }

  return -1;
}

int main() {
  // Initialize the graph using an adjacency list

  graph.resize(5);

  // Add edges to the graph
  graph[0].push_back(1);
  graph[0].push_back(2);
  graph[1].push_back(3);
  graph[1].push_back(4);
  graph[2].push_back(3);
  graph[2].push_back(4);

  // Run the UCS algorithm to find the shortest path from the source node to the goal node

  int shortest_path = ucs(0, 4);

  // Print the shortest path

  cout << "The shortest path is: " << shortest_path << endl;

  return 0;
}
