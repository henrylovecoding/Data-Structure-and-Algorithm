// Display4.cpp                                                    //
// ver 1.1                                                          //
// Language: standard C++                                           //
// Platform: Thinkpad E530, Windows 7, SP #1                        //
// Application: DFS algorithm, output combination of digits smaller //
//              than a given number (4) here                        //
// Author: Henry He       henrysyr03@gmail.com                      //
//////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;

//solution 1:
void recurse(vector<vector<int>>& res, vector<int>&tmp, int target, int N )
{
	if (target < 0)
		return;
	if (target == 0)
	{
		res.push_back(tmp);
		return;

	}
	for (int i = 1; i <= N; i++)
	{
		tmp.push_back(i);
		recurse(res,tmp,target-i,N);
		tmp.pop_back();


	}



}

#ifdef fourn
void main()
{
	vector<vector<int>>res;
	vector<int>temp;
	int N = 4;
	recurse(res,temp,N,N);
	for (int i = 0; i < res.size();i++)
	for (int j = 0; j < res[i].size(); j++)
	{
		cout << res[i][j];
		if (j == res[i].size() - 1)
			cout << endl;
	}
	system("pause");


}
#endif