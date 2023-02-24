// 1344. Negative cycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n, m;
long long G[2501][2501] = { 0 };
//bool w[2501][2501] = { 0 }; //record whether there is a edge
long long edge[10000][3] = { 0 };
int edges = 0;


void readgraph()
{
	cin >> n;//n vertices
	cin >> m;//m edges
	int t1, t2, l;
	for (int i = 0;i < m;i++)
	{
		cin >> t1 >> t2 >> l;
		edge[edges][0] = t1;
		edge[edges][1] = t2;
		edge[edges][2] = l;
		edges++;

		/*
		if (G[t1][t2] == 0 or G[t1][t2] > l)
		{
			G[t1][t2] = l;
			//w[t1][t2] = 1;
			edge[edges][0]=t1;
			edge[edges][1] = t2;
			edge[edges][2] = l;
			edges++;
		}
		*/

	}
}


int main()
{
	readgraph();

	//Bellman-Ford

	//Initialize
	//The starting point is a supervertex with index=0, and G[0][i]=0 for all i.
	//for (int i = 1;i <= n;i++) w[0][i] = 1;

	long long dist[2501] = { 0 };
	int pre[2501] = { 0 };

	for (int i = 1;i <= n;i++)
	{
		dist[i] = 10000000000*m;
		pre[i] = -1;
	}

	//Repeat relaxing
	for (int i = 1;i <= n-1;i++) //do it N-1 times
	{
		for (int j = 0;j < m;j++)
		{
			int u, v;
			u = edge[j][0];
			v = edge[j][1];
			if (dist[u] + edge[j][2] < dist[v])
			{
				dist[v] = dist[u] + edge[j][2];
				pre[v] = u;
			}
		}


		/*
		//go through each edge
		for (int u = 0;u <= n;u++)
		{
			for (int v = 0;v <= n;v++)
			{
				if (w[u][v])//there is an edge u->v
				{
					if (dist[u] + G[u][v] < dist[v])
					{
						dist[v] = dist[u] + G[u][v];
						pre[v] = u;
					}
				}
			}
		}
		*/
	}

	int U, V; //store the last edge

	bool flag = false;//false means there is no negative cycle

	//Go through the edges one more time to examine
	/*
	for (int u = 0;u <= n;u++)
	{
		for (int v = 0;v <= n;v++)
		{
			if (w[u][v])//there is an edge u->v
			{
				if (dist[u] + G[u][v] < dist[v])
				{
					flag = true;
					U = u;
					V = v;
					break;
				}
			}
		}
	}
	*/
	for (int j = 0;j < m;j++)
	{
		int u, v;
		u = edge[j][0];
		v = edge[j][1];
		if (dist[u] + edge[j][2] < dist[v])
		{
			flag = true;
			dist[v] = dist[u] + G[u][v];
			pre[v] = u;
			U = u;
			V = v;
			break;
		}
	}

	if (!flag)
	{
		cout << "No";
		return 0;
	}
	
	cout << "Yes" << endl;

	int marked[2501] = {0};//record whether the vertex has appeared
	marked[U] = 1;
	marked[V] = 1;

	int temp = pre[U];
	while (1)
	{
		if (marked[temp] == 1) break;
		marked[temp] = 1;
		temp = pre[temp];
	}

	//Now temp is the beginning and the end of the negative cycle
	//Calculate the total vertices in this cycle
	int counter = 1;
	int fixed = temp;
	int cycle[2501] = { 0 };
	cycle[1] = fixed;
	temp = pre[fixed];
	while (1)
	{
		if (temp == fixed) break;
		if (temp != 0 ) 
		{
			counter++;
			cycle[counter] = temp;
		}

		temp = pre[temp];
	}
	cout << counter << endl;
	for (int i = counter;i >= 1;i--)
	{
		cout << cycle[i] << " ";
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
