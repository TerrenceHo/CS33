/* Terrence Ho */
/* 804793446 */

// 2.90

static float u2f(unsigned u){
    union {
        unsigned u_num;
        float f_num;
    } result;
    result.f_num = 0;
    result.u_num = u;
    return result.f_num;

}

/* Compute 4**x */
float fpwr4(int x){
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if(x < -74){
        /* Too small */
        exp = 0; 
        frac = 0;
    } else if (x < -63){
        /* Denormalized Result */
        exp = 0;
        frac = 1 << ((2 * (x + 74)) + 1);
    } else if (x < 64){
        /* Normalized Result */
        exp = (2 * x) + 127;
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




