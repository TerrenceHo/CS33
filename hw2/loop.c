// Terrence Ho
// 804793446
long loop(long x, long n){
    long result = 0;
    long mask;
    for(mask = 1; mask != 0; mask = mask << (0xff & n)){
        result |= (mask & x);
    }
    return result;
}
