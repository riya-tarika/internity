#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vertex,edge;
	cout<<"Enter number of vertexes and edges"<<endl;
	cin>>vertex>>edge;
	int vertexes[vertex];
	cout<<"Enter vertexes name"<<endl;
	for(int i=0;i<vertex;i++)
	{
		cin>>vertexes[i];
	}
	int arr[vertex][vertex];
	cout<<"Enter 1 if edge is present between vertexes else zero"<<endl;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
            cout<<vertexes[i]<<"->"<<vertexes[j]<<endl;
			cin>>arr[i][j];
			if(arr[i][j]!=1 && arr[i][j]!=0)
			{
                cout<<"Enter 1 or 0"<<endl;
                cin>>arr[i][j];
			}
		}
	}
	int count=0, count1=0, max_vertex=0;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
			if(arr[i][j]==1)
				count++;
		}
		if(count>count1)
		{
			count1=count;
			max_vertex=i;
		}
		count=0;
	}
	cout<<"node with highest number of  branch is :->"<<vertexes[max_vertex]<<endl;
	cout<<"and the count is:->"<<count1<<endl;
	return 0;
}
