#include "stdafx.h"
#include "AlgorithmTest.h"
#include <vector>
#include <algorithm>

using namespace std;

int AlgorithmTest::start(int argc, char *argv[])
{
	int n = 5;
	vector<int> money{ 1, 2, 5 };
	int answer = 0;
	sort(money.begin(), money.end());
	for (auto i : money)
	{
		cout << i << " ";
	}
	int TryIndex = money.size() - 1;
	while (TryIndex > 0)
	{
		int remainMoney = n % money[TryIndex];
		if (!remainMoney)
		{
			answer++;
			TryIndex--;
			cout << "TryIndex : " << TryIndex << "Answer : " << answer << endl;
			continue;
		}

		int curMoney = n;
		int curTryIndex = TryIndex;
		while (curMoney >= 0 && curTryIndex >= 0)
		{
			int NumOfValue = curMoney / money[curTryIndex];
			curMoney -= NumOfValue * money[curTryIndex];
			curTryIndex--;
		}
		if (curMoney == 0)
		{
			answer++;
		}
		else
		{
			TryIndex--;
			continue;
		}
	}


	answer %= 1000000007;
	return answer;
}
