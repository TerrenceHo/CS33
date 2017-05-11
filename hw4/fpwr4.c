/* Terrence Ho */
/* 804793446 */

// 2.90

float fpwr2(int x){
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if(x < -149){
        /* Too small */
        exp = 0; 
        frac = 0;
    } else if (x < -126){
        /* Denormalized Result */
        exp = 0;
        frac = 1 << (x + 149);
    } else if (x < 255){
        /* Normalized Result */
        exp = x + 127;
        frac = 0;
    } else {
        /*  Too Big. Return +00*/
        exp = 255;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return utf(u);
}
