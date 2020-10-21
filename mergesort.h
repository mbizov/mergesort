#ifndef _MERGESORT_H_
#define _MERGESORT_H_

void merge_sort(int a[], int temp[], int start, int end) {
    if (end <= start) return;
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    int k;
    
    merge_sort(a, temp, start, mid);
    merge_sort(a, temp, mid + 1, end);
    
    for (k = start; k <= end; k++) {
        if (left == mid + 1) {
            temp[k] = a[right];
            right++;
        } else if (right == end + 1) {
            temp[k] = a[left];
            left++;
        } else if (a[left] < a[right]) {
            temp[k] = a[left];
            left++;
        } else {
            temp[k] = a[right];
            right++;
        }
    }

    for (k = start; k <= end; k++) a[k] = temp[k];
}

#endif
