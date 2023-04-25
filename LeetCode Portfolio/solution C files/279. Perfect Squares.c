//Zadie Moon
//https://leetcode.com/problems/perfect-squares/
int numSquares(int n){
    
    int min_num_squares[n+1]; // define array
    min_num_squares[0] = 0; // base case

    for (int i = 1; i <= n; i++) {
        min_num_squares[i] = INT_MAX; // initialize to INT_MAX
        for (int j = 1; j*j <= i; j++) {
            min_num_squares[i] = fmin(min_num_squares[i], min_num_squares[i-j*j] + 1);
        }
    }

    return min_num_squares[n];
}
