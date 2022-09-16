#include <unordered_map>
#include <queue>

string reArrangeString(string &s)
{
    // Write your code here.
    string ans = "";
    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;

    // step 1 push all char to map with frequency
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;

    // step 2 push the elements of map in pair form in max heap(based on frequency)
    for (auto it : mp)
        pq.push(make_pair(it.second, it.first));

    // step 3 loop until heap has > 1 element
    /*
        extract the most and next most frequent char from heap and add to answer
        pop them from heap too
        now if frequency is > 1 then
        decrement the frequency of both char from map and push then back to heap
    */
    while (pq.size() > 1)
    {
        char mostFreq = pq.top().second;
        pq.pop();
        char nextFreq = pq.top().second;
        pq.pop();

        ans += mostFreq;
        ans += nextFreq;

        if (mp[mostFreq] > 1)
        {
            mp[mostFreq]--;
            pq.push(make_pair(mp[mostFreq], mostFreq));
        }

        if (mp[nextFreq] > 1)
        {
            mp[nextFreq]--;
            pq.push(make_pair(mp[nextFreq], nextFreq));
        }
    }

    // step 4 now if there are chars left in heap and that char has frequency 1
    // then add that char to ans
    // else if frequency is greater than 1 then return empty string as it cannot be arranged

    if (pq.size())
    {
        char top = pq.top().second;
        if (mp[top] > 1)
            return "";
        else
        {
            ans += top;
        }
    }
    return ans;
}
