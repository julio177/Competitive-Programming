#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 1000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int nums[maxN], tail[maxN];
int T, N;

// Binary search (note boundaries in the caller)
int CeilIndex(int arr[], int l, int r, int key) {
	int m;

    while (r - l > 1) {
	    m = l + (r - l) / 2;
	    if (arr[m] >= key)
	        r = m;
	    else
	        l = m;
    }

    return r;
}

void LongestIncreasingSubsequenceLength() {
    if (N == 0)
        return;

    int length = 1; // always points empty slot in tail
 
    tail[0] = nums[0];

    FOR(i, 1, N) {
        if (nums[i] < tail[0])
            // new smallest value
            tail[0] = nums[i];
        else if (nums[i] > tail[length - 1])
            // nums[i] extends largest subsequence
            tail[length++] = nums[i];
        else
            // nums[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than nums[i]
            // (and also, nums[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length - 1, nums[i])] = nums[i];
    }
    return;
}

int main(int argc, char const *argnums[])
{
	int len;
	cin >> T;
	FOR(i, 0, T) {
		memset(nums, 0, sizeof(nums));
		memset(tail, -1, sizeof(tail));

		cin >> N;
		FOR(j, 0, N) {
			cin >> nums[j];
		}
		cin >> len;
		LongestIncreasingSubsequenceLength();
		cout << tail[len - 1] << endl;
	}
	return 0;
}