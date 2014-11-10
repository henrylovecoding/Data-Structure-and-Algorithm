// FindNextValueinBST.cpp                                        //
// ver 1.1                                                       //
// Language: standard C++                                        //
// Platform: Thinkpad E530, Windows 7, SP #1                     //
// Application: A better way than Strstr(), a higher efficient way/ 
//              of substring                                     //
// Author: Henry He      henrysyr03@gmail.com                    //
///////////////////////////////////////////////////////////////////

#include<string>
#include<iostream>

using namespace std;

bool iscontain(string text, string pattern)
{
	int len_text = text.size();
	int len_pattern = pattern.size();
	if (len_text < len_pattern)
		return false;
	int i = 0;
	while ( i + pattern.size() <= text.size())
	{
		int index = i;
		int j = 0;
		while( j < len_pattern)
		{
			if (text[index] == pattern[j])
			{
				index++;
				j++;
			}
			else  //not match
			{
				int k = len_pattern - 1;
				int count = 0;
				for (k; k >= 0; k--)
				{
					count++;
					if (pattern[k] == text[i + len_pattern])
					{
						i += count ;
						break;
					}
				}
				if (k < 0)
					i += pattern.size() + 1;
				break;
			}
		}
		if (j == pattern.size())
			return true;
	}
	return false;
}

