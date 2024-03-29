//
// Created by ialom on 6/18/19.
//

#include <bits/stdc++.h>

using namespace std;

void printArray (int ara[], int len) {
    printf("The array: \n{");
    for(int i=0; i<len; i++) {
        cout << ara[i] << ",";
    }
    printf("} \n");
}

int findElement(int ara[], int len, int key) {
    printArray(ara, len);
    for(int i=0; i<len; i++){
        printf("i: %d - num: %d \n", i, ara[i]);
        if(ara[i] == key) return i;
    }
    return -1;
}

int binarySearch(int ara[], int len, int key) {
    printArray(ara, len);
    int low = 0, high = len;
    while(high > low){
        int mid = (low + high)/2;
        printf("Low: %d - Mid: %d - High: %d \n", ara[low], ara[mid], ara[high]);
        if(ara[mid] == key) {
            return mid;
        }
        else if(ara[key] < ara[mid]) high = mid;
        else low = mid;
    }
    return -1;
}

int findSorted(int ara[], int len, int key) {
    sort(ara, ara + len);
    return binarySearch(ara, len, key);
}

int main() {
    int ara[] = {10, 5, 15, 2, 99, 75, 64};
    int len = sizeof(ara)/ sizeof(ara[0]);
    int n = 99;

    int pos = findSorted(ara, len, n);

    pos ? cout << "Position of " << n << ": " << pos + 1 : cout << n << " is not found";

    return 0;
}