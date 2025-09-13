#include <iostream>
#include <stack>
using namespace std;

void dailyTemperatures(int temperatures[], int n) {
    int answer[n];         // store days to wait
    stack<int> s;          // stack to store indices

    for (int i = n - 1; i >= 0; i--) {
        // Pop indices with temperatures <= current
        while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
            s.pop();
        }

        if (s.empty())
            answer[i] = 0;          // no warmer day
        else
            answer[i] = s.top() - i; // days until warmer

        s.push(i);
    }

    // Print the answer array
    cout << "Days to wait for warmer temperature: ";
    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";
    cout << endl;
}

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    dailyTemperatures(temperatures, n);
    return 0;
}
