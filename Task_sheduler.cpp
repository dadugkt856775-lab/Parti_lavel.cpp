#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> tasks = {
        'A', 'A', 'A', 'B', 'B', 'B'
    };

    int cooldown = 2;

    vector<int> freq(26, 0);

    for (char c : tasks)
        freq[c - 'A']++;

    priority_queue<int> pq;

    for (int x : freq) {
        if (x > 0)
            pq.push(x);
    }

    int time = 0;

    while (!pq.empty()) {
        vector<int> used;

        for (int i = 0; i <= cooldown; i++) {

            if (!pq.empty()) {
                int current = pq.top();
                pq.pop();

                current--;

                if (current > 0)
                    used.push_back(current);
            }

            time++;

            if (pq.empty() && used.empty())
                break;
        }

        for (int x : used)
            pq.push(x);
    }

    cout << "Minimum Time: " << time;

    return 0;
}
