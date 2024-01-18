#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string N;
    int B;
    cin >> N >> B;
    reverse(N.begin(), N.end());

    long long result = 0;
    for (int i = 0; i < N.size(); i++) {
        if ('0' <= N[i] && N[i] <= '9') {
            result += (N[i] - '0') * static_cast<long long>(pow(B, i));
        }
        else {
            result += (N[i] - 'A' + 10) * static_cast<long long>(pow(B, i));
        }
    }

    cout << result << '\n';
    return 0;
}
