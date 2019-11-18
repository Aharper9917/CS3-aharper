/*
Modified by: Allen Harper 
On: 11/10/19

Problem:
https://open.kattis.com/problems/shortestpath1
*/
#include <iostream>
#include <climits>
#include <queue>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <cassert>

using namespace std;
using iPair = pair<int, int>;

using namespace std;

// finds SSSP to all the nodes from given source
// can be modified to find shortest path to a single destination
// see Single Destination comment below
template<class T>
void Dijkstra(T & G, int source, vector<int>& dist) {
    // min priority_queue of vertices that need to be processed
    // stores pair of <weight, vertex>
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    dist.resize(G.nodeCount());
    fill(dist.begin(), dist.end(), INT_MAX);
    vector<bool> visited(G.nodeCount(), false);
    dist[source] = 0;
    pq.push({0, source}); // {weight, vertex}

    while (! pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        // Single Destination:
        // if interested to find the path to one destination
        // check here if u == dest node; break if so
        if (visited[u]) continue;
        visited[u] = true;
        for(auto p: G.neighbors(u)) {
            int v = p.first;
            if (visited[v]) continue;
            int w = p.second;
            // if there's a shorter path to v through u
            int d = dist[u] + w;
            if (d < dist[v]) {
                dist[v] = d;
                pq.push({d, v});
                // update parent vector if path needs to be recorded
                //parent[v] = u;
            }
        }
    }
}

// Directed Graph using Adjacency List
// update addEdge() for Undirected Graph
class Graph {
    private:
        vector<list<iPair> > graph; // list stores pair of neighbor id and weight
    
    public:
        Graph(size_t n) {
            for (int i=0; i<n; i++) {
                list<iPair> v; // create an empty list of int, int pair type
                graph.push_back(v);
            }
        }
    
        // return the number of vertices/nodes
        size_t nodeCount() {
            return graph.size();
        }
        
        // add a new edge from node u to node v, with weight w
        // assumes nodes are numbered from 0 to n-1
        void addEdge(int u, int v, int w) {
            graph[u].push_back({v, w});
            // if undirected graph must add edge from v to u
            // graph[v].push_bck({u, w}); 
        }

        // returns list of pairs containing neighbors of u, and weight
        list<iPair> neighbors(int u) {
            return graph[u];
        }
};

void test(){
    Graph graph1(4);
    vector<int> dist1;
    graph1.addEdge(3, 0, 2);
    graph1.addEdge(0, 1, 2);
    graph1.addEdge(1, 2, 2);
    Dijkstra<Graph>(graph1, 0, dist1);
    assert(dist1[3] == INT_MAX);
    assert(dist1[2] == 4);
    assert(dist1[1] == 2);
    assert(dist1[0] == 0);

    Graph graph3(2);
    vector<int> dist2;
    graph3.addEdge(0, 1, 100);
    Dijkstra<Graph>(graph3, 0, dist2);
    assert(dist2[1] == 100);
    assert(dist2[0] == 0);

    cout << "All Test Cases Pasted..." << endl;
}

int main(int argc, const char** argv) {
    int n, m, q, s, u, v, w;

    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else{
        // Pull data in
        while (cin >> n && cin >> m && cin >> q && cin >> s)
        {
            Graph graph(n);
            vector<int> dist;
            vector<int> queries;

            if(n == 0 && m == 0 && q == 0 && s == 0)
                break;
            for (int i = 0; i < m; i++)
            {
                cin >> u >> v >> w;
                graph.addEdge(u, v, w);
            }

            // get queries
            int query;
            for (int i = 0; i < q; i++)
            {
                cin >> query;
                queries.push_back(query);
            }

            //run algorithm for each node 
            Dijkstra<Graph>(graph, s, dist);
            for(auto query : queries)
            {
                // display each query dist 
                if(dist[query] == INT_MAX) {
                    cout << "Impossible" << endl;
                }
                else {
                    cout << dist[query] << endl;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}