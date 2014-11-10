// FindPeek.cpp                                                     //
// ver 1.1                                                          //
// Language: standard C++                                           //
// Platform: Thinkpad E530, Windows 7, SP #1                        //
// Application: Binary Search, find the peek in an array which is   //
//              half increasing and half decreasing                 //
// Author: Henry He     henrysyr03@gmail.com                        //
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;

int findpeek(int A[], int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return A[0];
	int start = 0;
	int end = n - 1;
	while (start + 1 < end)
	{
		int mid = start + (end - start) / 2;
		if (A[mid] < A[mid - 1])
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
	return A[start] > A[end] ? A[start] : A[end];

}

