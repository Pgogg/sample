#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<vector<int>> v = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int n = v.size();
    stack<int> s;

    // Step 1: Push all people into stack
    for(int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate until one candidate remains
    while(s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();

        if(v[i][j] == 1) {
            // i knows j → i cannot be celeb
            s.push(j);
        } else {
            // i does not know j → j cannot be celeb
            s.push(i);
        }
    }

    // Step 3: Verify candidate
    int celeb = s.top();
    for(int i = 0; i < n; i++) {
        if(i != celeb && (v[i][celeb] == 0 || v[celeb][i] == 1)) {
            cout << -1 << endl; // No celeb
            return 0;
        }
    }

    cout << celeb << endl; // Print celeb index
    return 0;
}
