int sumPositive(int array[], int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            result += array[i];
        }
    }
    return result;
}