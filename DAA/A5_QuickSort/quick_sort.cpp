#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int p, int r, int &counter) {
    int x = arr[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        counter++;
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quick_sort(int *a, int p, int r, int &counter) {
    if(p < r) {
        int q = partition(a, p, r, counter);
        quick_sort(a, p, q-1, counter);
        quick_sort(a, q+1, r, counter);
    }
}

int rand_partition(int *arr, int p, int r, int &counter) {
    int x = arr[r];
    int i = rand() % (r-p+1)+p;
    swap(arr[i], arr[r]);
    counter++;
    return partition(arr, p, r, counter);
}

void rand_quick_sort(int *b, int p, int r, int &counter) {
    if(p < r) {
        int q = rand_partition(b, p, r, counter);
        rand_quick_sort(b, p, q-1, counter);
        rand_quick_sort(b, q+1, r, counter);
    }
}

int main () {
    int n;
    cout<<"Enter number of elements in array : ";
    while(!(cin>>n) || (n<=0)) {
        cout<<"Enter valid positive number : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int a[n], b[n];
    srand(time(0));

    cout<<"Enter elements in array : ";
    for(int i=0; i<n; i++) {
        while(!(cin>>a[i])) {
            cout<<"Enter valid positive number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        b[i] = a[i];
    }

    int quick_cnt = 0, rand_quick_cnt = 0;
    quick_sort(a, 0, n-1, quick_cnt);
    cout<<"Array after quick sort : ";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\nAnd number of steps required were : "<<quick_cnt;

    rand_quick_sort(b, 0, n-1, rand_quick_cnt);
    cout<<"\n\nArray after randomized quick sort : ";
    for(int i=0; i<n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<"\nAnd number of steps required were : "<<rand_quick_cnt<<"\n";
    return 0;
}