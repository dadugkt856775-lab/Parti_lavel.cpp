#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "aab";

    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    priority_queue<pair<int, char>> pq;

    for (auto& p : freq)
        pq.push({p.second, p.first});

    string result;
    pair<int, char> previous = {0, '#'};

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        result += current.second;
        current.first--;

        if (previous.first > 0)
            pq.push(previous);

        previous = current;
    }

    if (result.size() != s.size())
        cout << "Not Possible";
    else
        cout << "Reorganized String: " << result;

    return 0;
}
