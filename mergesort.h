#ifndef _MERGESORT_H_
#define _MERGESORT_H_

void merge_sort(int a[], int aux[], int start, int end) {
    if (end <= start) return;
    int mid = (start + end) / 2;

    merge_sort(a, aux, start, mid);
    merge_sort(a, aux, mid + 1, end);

    int left = start;
    int right = mid + 1;
    int k;

    for (k = start; k <= end; k++) {
        if (left == mid + 1) {
            aux[k] = a[right];
            right++;
        } else if (right == end + 1) {
            aux[k] = a[left];
            left++;
        } else if (a[left] < a[right]) {
            aux[k] = a[left];
            left++;
        } else {
            aux[k] = a[right];
            right++;
        }
    }

    for (k = start; k <= end; k++) a[k] = aux[k];
}

#endif
