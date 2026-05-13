// O:(log (n))
int Binario(int vec[], int element, int start, int end) {
    int mid = (start + end) / 2;
    if(vec[mid] == element) {
        return mid;
    } else if(vec[mid] > element) {
        return Binario(vec, element, mid + 1, end);
    } else {
        return Binario(vec, element, mid - 1, start);
    }
}