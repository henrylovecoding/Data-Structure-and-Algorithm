#include<iostream>
#include<vector>
#include<string>

using namespace std;




void helper(int table[4][4], vector<vector<bool>>&visited, int m, int n, int x, int y)
{
	if (x < 0 || y >= n || x >= m || y < 0)
		return;
	if (table[x][y] == 0 || visited[x][y]==true)
		return;
	else
	{
			visited[x][y] = true;
			helper(table, visited, m, n, x + 1, y);
			helper(table, visited, m, n, x - 1, y);
			//else if (table[x][y - 1] == 1)
			helper(table, visited, m, n, x, y - 1);
			//else if (table[x][y + 1] == 1)
			helper(table, visited, m, n, x, y + 1);
	}
	

	
   
	

}



int countCluster(int table[4][4], vector<vector<bool>>&visited, int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (table[i][j] == 1 && visited[i][j] == false)
			{
				helper(table, visited, m, n, i, j);
				count++;
			}
		}
		return count;
}

#ifdef countclust
void main()
{
	int table[4][4] = { { 1, 0, 1, 0 }, { 0, 1, 0, 1 }, { 1, 0, 1, 0 }, { 0, 1, 0, 1 } };
	vector<vector<bool>>visited(4, vector<bool>(4, false));
	int res = countCluster(table, visited, 4, 4);
	cout << res;
	system("pause");




}
#endif