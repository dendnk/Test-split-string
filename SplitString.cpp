// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string input_s{"mama son mam food star mama mama dad food star wife mama son mama dad dad dad dad dad dad line sea food star"};

    cout << input_s << endl;

    istringstream iss(input_s);
    vector<string> words(istream_iterator<string>(iss), istream_iterator<string>{});

    map <string, int> map1{};

    for (auto w : words)
    {
        if (!map1.count(w))
        {
            map1.insert(pair<string, int>(w, 1));
        }
        else
        {
            (*map1.find(w)).second++;
        }
    }

    map<string, int>::iterator topPair{ map1.begin() }, it{ map1.begin() };

    int numTopWords{ 5 };

    for (int i(0); i < min(numTopWords, int(map1.size())); ++i)
    {
        for (int j(0); it != map1.end(); ++it)
        {
            if (it->second > topPair->second)
            {
                topPair = it;
            }
        }

        // DNK : To do what you want
        cout << "Most frequent word : " << topPair->first << " | Number of repetetions : " << topPair->second << endl;

        topPair->second = -1;
        it = map1.begin();
    }
}