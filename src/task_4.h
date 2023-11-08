#include <iostream>
#include <vector>

using namespace std;

int problem4() {
    int n;
    cin >> n;

    vector<vector<int>> stacks(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        stacks[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> stacks[i][j];
        }
    }

    bool isProperlyStacked = true;
    for (int i = 0; i < n; ++i) {
        int type = 1;
        for (int j = 0; j < stacks[i].size(); ++j) {
            if (stacks[i][j] != type) {
                isProperlyStacked = false;
                break;
            }
            ++type;
        }
    }

    if (isProperlyStacked) {
    } else {
        vector<int> counts(n + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < stacks[i].size(); ++j) {
                ++counts[stacks[i][j]];
            }
        }

        for (int type = 1; type <= n; ++type) {
            int sourceStack = -1;
            int targetStack = type - 1;

            for (int i = 0; i < n; ++i) {
                if (counts[stacks[i][stacks[i].size() - 1]] == type && stacks[i].size() > 1) {
                    sourceStack = i;
                    break;
                }
            }

            if (sourceStack == -1) {
                // No solution
                cout << 0 << endl;
                return 0;
            }

            cout << sourceStack + 1 << " " << targetStack + 1 << endl;

            --counts[stacks[sourceStack][stacks[sourceStack].size() - 1]];
            stacks[sourceStack].pop_back();
            stacks[targetStack].push_back(type);
        }
    }

    return 0;
}
