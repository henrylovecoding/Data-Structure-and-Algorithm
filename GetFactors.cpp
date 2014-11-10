// FindNextValueinBST.cpp                                        //
// ver 1.1                                                       //
// Language: standard C++                                        //
// Platform: Thinkpad E530, Windows 7, SP #1                     //
// Application: Demonstrate DFS method using recursion           //
// Author: Henry He          henrysyr03@gmail.com                //
///////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>

using namespace std;

void Getfactors(int n, vector<vector<int>>& res, vector<int>& solution, vector<int>factors, int step, int multip)
{
	if (step == factors.size())
	{
		return;
	}
	if (multip > n)
	{
		return;
	}
	if (multip == n)
	{
		res.push_back(solution);
		return;
	}
	
	for (int i = step; i < factors.size(); i++)
	{
		solution.push_back(factors[i]);
		Getfactors(n, res, solution, factors, i, multip * factors[i]);
		solution.pop_back();
	}
}


vector<int>CalculateFactors(int n)
{
	vector<int> factors;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			factors.push_back(i);
		}
	}
	return factors;


}
