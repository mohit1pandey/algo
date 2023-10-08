#include <iostream>
using namespace std;

void merge(int a[], int l, int r, int mid){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int L1[n1];
    int L2[n2];
    for (int i = 0; i < n1; i++){
        L1[i] = a[i+l];
    }

    for (int j = 0; j < n2; j++){
        L2[j] = a[mid+1+j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2){
        if (L1[i] <= L2[j]){
            a[k] = L1[i];
            i++;
        } else{
            a[k] = L2[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        a[k] = L1[i];
        i++;
        k++;
    }

    while (j < n2){
        a[k] = L2[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int l, int r){
    if (l < r){
        int mid = (l+r)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        merge(a, l, r, mid);
    }
}

int main(){
    int arr[] = {23, 21, 20, 15, 14, 13, 12};
    int s = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, s-1);

    for (int i = 0; i < s; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
