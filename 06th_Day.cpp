#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include "DayHeaders.h"

using namespace std;


void Day_06(ifstream& InputFile)
{

	// initialize light grid
	vector<vector<int>> Lights(1000);
	vector<int> Row(1000, 0);
	fill(Lights.begin(), Lights.end(), Row);

	// read input line per line, parse coordinates and define actions
	string line;

	while (getline(InputFile, line))
	{
		string Action;
		// define what action to do with the groups of coordinates
		for (string check : { "toggle","turn on","turn off" })
		{
			if (line.find(check) != string::npos)
			{
				Action = check;
				line.erase(0, check.size() + 1);
				break;
			}
		}
		// parse numbers - there's probably a smarter way of doing this
		auto delimiter = line.rfind(",");
		int V = stoi(line.substr(delimiter + 1));
		line.erase(delimiter);
		delimiter = line.rfind("h");
		int H = stoi(line.substr(delimiter + 1));
		line.erase(delimiter);
		delimiter = line.find(",");
		int h = stoi(line.substr(0,delimiter));
		line.erase(0, delimiter + 1);
		int v = stoi(line);
		// note to myself: even if there are other characters present in the string, stoi converts only the numbers!
		
		for_each(Lights.begin() + h, Lights.begin() + H+1,
			[v,V,Action](vector<int> &Row)
		{
			for_each(Row.begin() + v, Row.begin() + V+1, [Action](int &Light)
			{ 
				if ( Action == "turn on") Light = 1;
				if ( Action == "turn off") Light = 0;
				if (Action == "toggle")
				{
					Light == 0 ? Light = 1 : Light = 0;
				}
			});
		});
		

	}

	int TotalLights = 0;
	for (auto Row : Lights)
	{
		TotalLights += count_if(Row.begin(), Row.end(), [](int light) {return light == 1; });
	}

	cout << "There is a total of " << TotalLights << " lights turned on!";




}
