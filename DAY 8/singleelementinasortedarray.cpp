int singleNonDuplicate(vector<int>& arr)
{
	int l = 0, r = arr.size() - 2;
	while(l <= r){
		int mid = (l+r)/2;
		if(mid%2 == 0){
			if(arr[mid] == arr[mid + 1]){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}else{
			if(arr[mid] == arr[mid - 1]){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
	}
	return arr[l];
}