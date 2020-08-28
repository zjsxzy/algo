void quickSort(std::vector<double>& vec, int left, int right){
    int i = left, j = right;
    int mid = (left + right) / 2;
    double pivot = vec[mid];
    while (i <= j){
        while (vec[i] < pivot) {
            i++;
        }
        while (vec[j] > pivot) {
            j--;
        }
        if (i <= j){
            swap(vec, i, j);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(vec, left, j);
    if (i < right)
        quickSort(vec, i, right);
}