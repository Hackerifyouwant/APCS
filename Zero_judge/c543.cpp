#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

int ladderNumbers[100001][10];

void Initialize() {
	for (int i = 1; i <= 100000; i++) {
		ladderNumbers[i][9] = 1;
		for (int j = 8; j >= 0; j--)
			ladderNumbers[i][j] = (ladderNumbers[i - 1][j] + ladderNumbers[i][j + 1]) % MOD;
	}
    
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	Initialize();
	string input;
	int answer, last;
	bool isLadderNumber;
	while (cin >> input) {
		answer = 0, last = 1, isLadderNumber = true;
		for (int i = 1; i != input.size(); i++) {
			for (int j = 1; j < 10; j++)
				answer += ladderNumbers[i][j], answer %= MOD;
			if (input[i] < input[i - 1])
				isLadderNumber = false;
		}
		for (; last < input[0] - '0'; last++)
			answer += ladderNumbers[input.size()][last], answer %= MOD;
		for (int i = 1; i != input.size() && input[i - 1] <= input[i]; i++)
			for (; last < input[i] - '0'; last++)
				answer += ladderNumbers[input.size() - i][last], answer %= MOD;
		cout << answer + (isLadderNumber ? 1 : 0) << endl;
	}
}