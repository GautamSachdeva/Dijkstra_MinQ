#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector<int>  d(adj.size(),100000);
  d[s] = 0;
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
  for(int i = 0; i < adj.size() ; i++){
  	q.push(make_pair(d[i],i));
  }
  while(!q.empty()){
		pair<int,int> top = q.top();
		q.pop();
		int u = top.second;
		for(int i = 0; i < adj[u].size() ; i++){
			int v = adj[u][i];
			if(d[v] > d[u] + cost[u][i]){
				d[v] = d[u] + cost[u][i];
				q.push(make_pair(d[v],v));
			}
		}
  }
  if(d[t] != 100000){
  	return d[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
