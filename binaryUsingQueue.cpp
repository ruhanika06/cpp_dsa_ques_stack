#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();

        cout << s << " ";   // print the binary number

        // generate next two numbers
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);
    cout << endl;

    return 0;
}
