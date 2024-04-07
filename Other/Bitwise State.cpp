/* 
    假設要遍歷所有 bitwise state 的 subset, 例如 state 為 10101, 其 subset 會有 10101, 10100, 10001, 00101, 10000, 00100, 00001, 00000
*/
void TravseAllSubset(int state) {
    for (int subset = state; subset >= 0; subset = (subset-1) & state) {
        /*
            10101, 10100, 10001, 10000, 00101, 00100, 00001, 00000
        */
        int set1 = subset;
        int set2 = state - subset;
        // Do something...
    }
}
