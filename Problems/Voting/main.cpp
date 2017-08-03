#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int nums, d, r, k;
	d = 0;
	r = 0;
	string s;
	queue<int> R, D;

	cin >> nums;
	cin >> s;

	for(int i = 0; i < nums; i++) {
		if(s[i] == 'D') {
			D.push(i);
			d++;
		}
		else {
			R.push(i);
			r++;
		}
	}

	while(r > 0 && d > 0) {
		if(D.front() < R.front()) {
			R.pop();
			r--;
			D.push(D.front() + nums);
			D.pop();
		}
		else {
			D.pop();
			d--;
			R.push(R.front() + nums);
			R.pop();
		}
		nums++;
	}

	if(r == 0) {
		cout << 'D';
	}

	else {
		cout << 'R';
	}

	return 0;
}