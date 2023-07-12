int search(int* arr, int n, int key) {
    int answer = -1;
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[l] <= arr[mid]){
            if(arr[l] <= key && key <= arr[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else{
            if(arr[mid] <= key && key <= arr[r]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }

    return answer;
}