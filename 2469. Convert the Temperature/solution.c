double* convertTemperature(double celsius, int* returnSize) {
    double* ans = malloc(2*sizeof(double));
    *returnSize = 2;
    ans[0] = celsius+273.15, ans[1] = celsius * 1.80 + 32.00;
    return ans;
}