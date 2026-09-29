#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ababcbacadefegdehijhklij";

    vector<int> last(26, 0);

    for (int i = 0; i < s.size(); i++)
        last[s[i] - 'a'] = i;

    vector<int> result;
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);

        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    cout << "Partition Sizes: ";

    for (int x : result)
        cout << x << " ";

    return 0;
}
