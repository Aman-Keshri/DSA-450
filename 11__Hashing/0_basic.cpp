#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // unordered map has Time = O(1)
    // map has Time = O(logN)

    unordered_map<string, int> mp;

    // insert
    pair<string, int> p = make_pair("aman", 1);
    mp.insert(p);

    pair<string, int> p1("keshri", 2);
    mp.insert(p1);

    mp["accenture"] = 1;

    // search
    cout << mp["keshri"] << endl;
    cout << mp.at("aman") << endl;

    // if element is not present in map then .at() function will give error
    // cout << mp.at("un") << endl;

    // but when not present element is searched using map[]
    // then a entry for the not present is created in map and assigned to zero
    // then that zerovalu is returned
    cout << mp["un"] << endl;

    // and if after the above search .at()  function is called on not present
    // element then it will also display zero as entry is already created for it
    cout << mp.at("un") << endl;

    // size
    cout << mp.size() << endl;

    // to check presence
    // count function give 0 if not present else return the entry corresponding to key
    cout << mp.count("bro") << endl;

    // earse
    mp.erase("un");
    cout << mp.size() << endl;

    // traverse map
    for (auto i : mp)
        cout << i.first << "  " << i.second << endl;

    // iterator
    unordered_map<string, int>::iterator it = mp.begin();

    cout << "\nusing itertor" << endl;
    while (it != mp.end())
    {
        cout << it->first << "  " << it->second << endl;
        it++;
    }

    return 0;
}