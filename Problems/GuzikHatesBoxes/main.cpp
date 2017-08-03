#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
 
#define INF 1000000000
#define MIN -100000000
#define FOR(x, y, z) for(int x = int(y);  x < int(z); x++) 
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi boxes(1000000, 0);
vi backup;
int qty, students;

bool check(int m) {
	bool flag = false;

	backup = boxes;

	while(!flag) {
		flag = true;

		FOR(i, 0, students) {
			FOR(j, 0, qty) {
				m--;
				if(backup[j] != 0) {
					backup[j]--;
					m--;
					flag = false;
				}
			}
		}
	}

	return m > 0;
}

void binarySearch() {
	bool flag;
	int low = 0, up = 1000000, middle;

	while(low < up) {
		middle = (low + up) / 2;
		flag = check(middle);

		if(flag) {
			up = middle;
		} else {
			low = middle + 1;
		}
		cout << "low: " << low;
		cout << ", up: " << up << endl;
	}
	cout << low << endl;
}

int main()
{
	cin >> qty >> students;
	FOR(i, 0, qty) {
		cin >> boxes[i];
	}

	binarySearch();

	return 0;
}