#include <bits/stdc++.h>
using namespace std;

// Stack implementation using array //for queue (end+1)%size for circular array
int main() {
    int arr[200];
    int n;
    int top = -1;
    int t=top;
    cout << "Enter the number of entries: ";
    cin >> n;
    cin.ignore(); // Clear input buffer

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s == "pop()") {
            if (top >= 0) {
                top++;
            } else {
                cout << "No element is present\n";
            }
        } else if (s == "top()") {
            if (top >=-1) {
                cout << arr[top+1] << endl;
            } else {
                cout << "Stack is empty\n";
            }

        } else if (s == "size()") {
            cout << (t-top + 1) << endl;
        } else if (s.substr(0, 5) == "push(" && s.back() == ')') {
            // Extract number from push(x)
            string num_str = s.substr(5, s.size() - 1); // Extract content inside push(...)
            int val = stoi(num_str);
            t++;
            arr[t] = val;
        } else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
