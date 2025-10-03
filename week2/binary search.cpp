// binary search
#include<iostream>
using namespace std;
bool binarysearch(int array[], int n, int x){
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = (left + right)/2;
		if(array[mid] == x){
			return true;
		}
		else if(array[mid] < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	int x;
	cin >> x;
	int array[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}
	if(binarysearch(array,n,x)){
		cout << "found";
	}
	else{
		cout << "no found";
	}
	return 0;
}
