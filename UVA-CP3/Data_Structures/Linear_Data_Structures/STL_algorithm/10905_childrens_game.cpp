#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ord(string &a, string &b){
    return a + b > b + a;
}

int main() {
	vector<string> v;
	int n;
	string a;
	while(scanf("%d ",&n), n){
	    v.clear();
	    while(n--){
	        cin >> a;
	        v.push_back(a);
	    }
        sort(v.begin(), v.end(), ord);
        for(int i = 0; i < v.size(); i++)
            cout << v[i];
	    cout << "\n";
	}
}
