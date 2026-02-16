#include <stdio.h>

/* === GDB TUTORIAL ===
   1. Compile: cc -g -O0 stack_overflow.c
   2. Start:   gdb ./a.out
   3. Visuals: Type 'layout src'

   4. Run:     Type 'run'
      -> CRASH! "Segmentation fault"

   5. Analyze: Type 'bt' (backtrace)
      -> You see a massive list of 'factorial' calls.

   6. Navigate:
      -> Type 'up' (moves up the stack to the caller).
      -> Look at the code window, it jumps to the recursive call.
      -> Type 'print n'.
      -> Repeat 'up' and 'print n'. You see n becoming negative (-1, -2...).
      -> Conclusion: Missing base case (if n <= 1 return 1).
*/

int factorial(int n) {
    // BUG: Missing base case! Infinite recursion.
    
    int temp = n * factorial(n - 1);
    return temp;
}

int main() {
    int number = 5;
    printf("Calculating factorial of %d...\n", number);
    
    int res = factorial(number);
    
    printf("Result: %d\n", res);
    return 0;
}
