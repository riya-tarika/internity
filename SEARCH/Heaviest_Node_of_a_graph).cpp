#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cout << "Enter the no of Nodes";
	cin >> n; // No of Nodes in graph;
	int wt[n];

	// All weights corresponding to the nodes;
	cout << "Enter the weight of all Nodes" << endl;
	for(int i = 0;i<n;i++)
	{

		cin >> wt[i];
	}
	vector<vector<int>> graph(n);
	for(int i = 0;i<n;i++)
	{
		vector<int> v;
		cout << "Enter the No Nodes connected to " << i << "th Node" << endl;
		int m;
		cin >> m;
		cout << "Enter all Nodes connected to " << i <<"th node" << endl;
		for(int j = 0;j<m;j++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		graph[i] = v;
	}
	for(int i = 0;i<n;i++)
	{
		vector<int> adj = graph[i]; // array of all adj. node to ith node

		pair<int,int> node[adj.size()]; // pair array for all adj. nodes and their corresponding weights.
		for(int j = 0;j<adj.size();j++)
		{
			node[j].first = wt[adj[j]];
			node[j].second = adj[j];
		}

		sort(node,node+adj.size());
		cout << "Heaviest Node according to" << i << " th Node" <<  ":- ";
		cout << node[adj.size() - 1].second << endl;
	}
	return 0;
}
