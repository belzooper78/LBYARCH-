


void daxpy_c(long n, double A, double* X, double* Y, double* Z){
    for (int i = 0;i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}
