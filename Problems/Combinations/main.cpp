#include <iostream>
#include <vector>

using namespace std;

int combi = 0;
int calls = 0;

void combo(vector<int> num, int found, int total, vector<int> ans, int remaining) {
	calls++;
	if(found == total) {
		combi++;
		return;
	}
	if(found + remaining < total) {
		return;
	}
	if(num.empty()) {
		return;
	}

	int aux;

	aux = num[0];
	num.erase(num.begin());
	combo(num, found, total, ans, remaining - aux);
	ans.push_back(aux);
	combo(num, found + aux, total, ans, remaining - aux);

	return;
}

int main(int argc, char const *argv[])
{
	vector<int> num = { 55, 38, 29, 29, 20, 20, 18, 16, 16, 15,
                  14, 13, 12, 11, 11, 11, 11, 10, 10, 10,
                  10, 9, 9, 9, 8, 8, 7, 7, 7, 6, 6, 6, 6,
                  6, 6, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3,
                  3, 3, 3, 3, 3
                };
	vector<int> ans;
	combo(num, 0, 270, ans, 538);
	cout << combi << endl;
	cout << calls << endl;
	return 0;
}