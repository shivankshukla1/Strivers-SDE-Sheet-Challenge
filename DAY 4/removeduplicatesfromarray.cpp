int removeDuplicates(vector<int> &arr, int n) {
	int ind = 1, curr = arr[0];
	for(int i = 0; i < n; i ++){
		if(arr[i] != curr){
			arr[ind] = arr[i];
			curr = arr[ind];
			ind += 1;
		}
	}
	return ind;
}