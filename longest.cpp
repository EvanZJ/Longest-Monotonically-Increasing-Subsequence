#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {4, 1, 13, 7, 0, 2, 8, 11, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> g[n];
	for(int i = n-1; i >= 0; i--){
        g[i].push_back(arr[i]);
		for(int j = i+1; j < n; j++){
			if(g[i].size() <= 1){
				if(arr[j] > arr[i]){
					if(g[j].size() > 1){
						g[i].clear();
                        g[i].push_back(arr[i]);
                        for (auto& it : g[j]) {
                            g[i].push_back(it);
                        }
					}
					else{
						g[i].push_back(arr[j]);
					}
				}
			}
			else{
				if(g[i].back() < arr[j]){
                    if(g[j].size() >= g[i].size()){
                        g[i].clear();
                        g[i].push_back(arr[i]);
                        for (auto& it : g[j]) {
                            g[i].push_back(it);
                        }
                        break;
                    }
                    else{
					    g[i].push_back(arr[j]);
                    }
				}
				else{
					if(g[j].front() > arr[i]){
						if(g[j].size() >= g[i].size()){
                            //clear g[i], readd arr[i], add g[j] to g[i]
                            g[i].clear();
                            g[i].push_back(arr[i]);
                            for (auto& it : g[j]) {
                                g[i].push_back(it);
                            }
                            break;
                        }
					}
				}
			}
		}
	}
	cout << "--hasil--" << endl;
	int maxi = 0;
	int loc;
	for(int i = 0; i < n; i++){
		if(maxi < g[i].size()){
			maxi = g[i].size();
			loc = i;
		}
	}
	cout << "Longest Monotonically Increasing Subsequence : " << maxi << " number" << endl;
	cout << "List : ";
	for (auto& it : g[loc]) {
		cout << it << " ";
	}
	cout << endl;
}
