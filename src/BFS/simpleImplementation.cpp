#include <string>
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

const int N = 1e3+10;

int n,f,t;

vector<int> g[N];
bool vis[N];
int cost[N];

int BFS(int src,int dst) {
	vis[src] = true;
	cost[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		if(current == dst)
			return cost[current];
		vis[current] = true;
		for(int i=0;i<(int)g[current].size();++i) {
			if(!vis[g[current][i]]) {
				vis[g[current][i]] = true;
				cost[g[current][i]] = cost[current]+1;
				q.push(g[current][i]);
			}
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for(int i=0;i<n;++i) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	cout << BFS(1,n) << endl;
	return 0;
}
