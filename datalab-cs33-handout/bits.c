/* 
 * CS:APP Data Lab 
 * 
 * <Terrence Ho 804793446>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    /* Negate x, then OR the result with x, thus making the first bit a 1 if x
     * is a non-zero number.  Shift left 31 times, making the result -1 if it x
     * is not a zero or 0 if it is.  Add one and return. */
    int invertedX = ~x + 1;
    int orX = (x | invertedX);
    int result = orX >> 31;
    return result + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /* mask takes in the first bit of every byte.  Then each sum takes in the
     * first bit of every byte.  Do this for every bit in each byte by shifting
     * right once every time.  Then add up all the sums and the result takes in
     * each byte and adds it all together.  Each byte in sum should hold the
     * number of 1 bits in x for the byte.  Result is the number of 1 bits.
     */
    int mask = 0x1 | (0x1<<8) | (0x1<<16) | (0x1<<24); //0000 0001 0000 0001 0000 0001 0000 0001
    int sum1 = x & mask;
    int sum2 = (x >> 1) & mask;
    int sum3 = (x >> 2) & mask;
    int sum4 = (x >> 3) & mask;
    int sum5 = (x >> 4) & mask;
    int sum6 = (x >> 5) & mask;
    int sum7 = (x >> 6) & mask;
    int sum8 = (x >> 7) & mask;
    int sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
    int result = (sum & 0xFF) + ((sum >> 8) & 0xFF) + ((sum >> 16) & 0xFF) + ((sum >> 24) & 0xFF);
    return result;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    /* Flip both numbers, AND them, and flip it result. */
    int masked = (~x & ~y);
    int result = ~masked;
    return result;
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
    /* nMax is used to check if it is 32.  If it is, jsut return it.  Otherwise,
     * use maskBits to find the bits we are copying.  Then shift it in
     * increments of n * 2^i, where i ranges from 0-4.  However, if n * 2^i is
     * greater than 32, it won't shift it at all, or attempts to shift left by 0
     * times.  Return the maskBits value.
     */
    int nMax = ~(!(n & 31)-1);  //Checks for n==32
    int maskBits = ~(~0 << n) & x;  //Mask lower n bits, which will be copied
    int shift2 = n * 2;
    int shift4 = n * 4;
    int shift8 = n * 8;
    int shift16 = n * 16;
    maskBits = maskBits | maskBits << n;
    maskBits = maskBits | maskBits << (shift2 * !(shift2/32));
    maskBits = maskBits | maskBits << (shift4 * !(shift4/32));
    maskBits = maskBits | maskBits << (shift8 * !(shift8/32));
    maskBits = maskBits | maskBits << (shift16 * !(shift16/32));
    return (maskBits & ~nMax) | (x & nMax);
}
/*
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /* when you shift left by n-1, the remainder should either all be 1 or zero,
     * and so by getting by inverse x and x with a sign mask, you can determine
     * if it is all zero at the end.  If it is, then it can fit within the bit
     * n.  */
    int sign = x >> 31; //sign bit
    int shift = n + ~0;
    int result = (~x & sign) + (x & ~sign);
    return !(result >> shift);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /* Shift multiple n by 8 to get the location of first bit we want then shift
     * right to that bit and apply a mask on the last byte.*/
    int shift = n << 3;
    int xShift = x >> shift;
    int result = xShift & 0xFF;
    return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /*  negate x, and find the difference between the two numbers. Return the
     *  opposite of the sign of the difference.  We check for overflow if the
     *  signs of x and y are different, and that x is a negative number.  If
     *  either either flow happened with x as a negative number or !diff sign is
     *  true, return 1, else 0.
    */ 

    int diffSign = (~x + 1 + y) >> 31 & 1; 
    int xSign = (0x1 << 31) & x;
    int ySign = (0x1 << 31) & y;
    int oCheck = ((xSign ^ ySign) >> 31) & 1; 
    return (oCheck & (xSign>>31)) | (!diffSign & !oCheck);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    /* We want to ultiamtely return the sign bit, so we first flip the sign bit */ 
    /* with ~x. ~x + 1 accounts for zero.  We then right shift 31 times and then */ 
    /* mask it to get the last bit. */
    int notX = ~x;
    notX = notX & (~x + 1);
    return (notX >> 31) & 1;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    /* Shift right x by n, and then create a mask that excludes all the bits in
     * the very beginning that are supposed to be ignored. And shifted x and the
     * mask.*/
    int shiftedX = x >> n;
    int m = (0x1 << 31) >> n;
    int mask = ~(m << 1);
    return shiftedX & mask;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
   /* shit 0x1 31 times to the left to get 0x80000000, which is T_MIN */ 
    int x = 0x1;
    int result = x << 31;
    return result;
}
