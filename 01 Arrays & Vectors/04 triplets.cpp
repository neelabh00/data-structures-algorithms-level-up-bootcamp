#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> arr,int targetSum){
	//Logic 
	int n = arr.size();
	sort(arr.begin(),arr.end());
	set<vector<int> > result; // To make sure each triplet is unique
	vector<vector<int>> ans;
	

	// Pick every a[i], pair sum for remaining part
	for(int i=0; i<=n-3;i++){

		int j = i + 1;
		int k = n - 1;

		//two pointer approach
		while(j < k){
			int current_sum = arr[i];
			current_sum += arr[j];
			current_sum += arr[k];

			if(current_sum==targetSum){
				result.insert({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}
			else if(current_sum > targetSum){
				k--;
			}
			else{
				j++;
			}
		}

	}
	for(auto i: result){
		ans.push_back(i);
	}
	return ans;

}

int main(){

	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

	auto result = triplets(arr,S);

	for(auto v : result){
		for(auto no : v){
			cout<<no<<",";
		}
		cout<<endl;
	}


	return 0;
}
