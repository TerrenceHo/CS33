//Terrence Ho
//804793446
long switch_prob(long x, long n){
    long result = x;
    switch(n){
        case 60:
            result = x * 8;
            break;
        case 62:
            result = x * 8;
            break;
        case 63:
            result = x;
            result = result >> 0x3;
            break;
        case 64:
            result = x;
            result = result << 0x4;
            result -= x;
            x = result;
        case 65:
            x *= x;
        default: 
            result = x + 75;
    }
    return result;
}

