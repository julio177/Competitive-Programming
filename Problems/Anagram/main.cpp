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

int number_needed(string a, string b) {
    int iA[26] = {0};
    int res = 0;
    int i;
    
    for(i = 0; i < a.length(); i++)
        iA[a[i] - 'a']++;
    
    for(i = 0; i < b.length(); i++)
        iA[b[i] - 'a']--;
    
    for(i = 0; i < 26; i++)
        res += abs(iA[i]);
    
    return res;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}