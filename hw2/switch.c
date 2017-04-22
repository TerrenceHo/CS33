long switch_prob(long x, long n){
    long result = x;
    switch(n){
        /* fill in code here */
        case 60:
            result = x * 8;
            break;
        casei 62:
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
            x *= x;
            result = 75+x;
            break;
        case 65:
            x *= x;
            result = 75+x;
            break;
        default: 
            result = x + 75
    }
    return result;
}

/* gbd output
 * x/6gx 0x4006f8
 *
 * 0x4006f8:  0x00000000004005a1 0x00000000004005c3
 * 0x400708:  0x00000000004005a1 0x00000000004005aa
 * 0x400718:  0x00000000004005b2 0x00000000004005bf
 */
