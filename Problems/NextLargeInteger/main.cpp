#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tests, cant, aux, m, j;
	vector<int> numbers, results;
	bool flag = false;
	cin>> tests;
	while(tests > 0) {
	    numbers.clear();
	    results.clear();
	    cin >> cant;
	    for(int i = 0; i < cant; i++) {
	        cin >> aux;
	        numbers.push_back(aux);
	    }
	    
	    for(int i = cant - 1; i >= 0; i--) {
	        
	    }
	    
	    for(int i = cant - 1; i >= 0; i--) {
	        cout << results[i] << " ";
	    }
	    cout << endl;
	    tests--;
	}
	return 0;
}