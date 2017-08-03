#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k, int t) {
    vector<int> res;
    k = t == 1 ? abs(n - k) : k;
    for(int i = 0; i < n; i++) {
        res.push_back(a[(i + k) % n]);
        //cout << i << " + " << k <<" % " << n << " = " << (i + k) % n << endl;
    }
    return res;
}


int main(){
    int n;
    int k;
    int t;
    cout << "Insert numbers quantity, shifts, left(0) or right(1):" << endl;
    cin >> n >> k >> t;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k, t);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}