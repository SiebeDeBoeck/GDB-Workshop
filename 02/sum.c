#include <stdio.h>

/* === GDB TUTORIAL ===
   1. Compile: cc -g -O0 logic_error.c
   2. Start:   gdb ./a.out
   3. Visuals: Type 'layout src'

   4. Break:   Type 'break main' (You see a B+ icon)
   5. Run:     Type 'run'
   
   6. Step:    Type 'next' (or 'n') repeatedly.
      -> Watch the code flow line by line.

   7. Inspect Garbage Value:
      -> inside 'calculate_sum', type 'print sum'.
      -> You see a random huge number (garbage) because it wasn't initialized.

   8. Inspect Loop Error:
      -> Keep pressing 'n' inside the loop.
      -> Type 'print i' and 'print length'.
      -> Notice the loop runs when i == 5, which is out of bounds!
*/

int calculate_sum(int *arr, int length) {
    int sum; // BUG 1: Not initialized (contains garbage)
    
    // BUG 2: Loop condition '<=' instead of '<'
    // This causes an out-of-bounds read at index 5
    int i = 0;
    while (i <= length) 
    {
        sum += arr[i];
        i++;:
    }
    return sum;
}

int main() {
    int data[5] = {10, 20, 30, 40, 50};
    
    printf("Calculating sum...\n");
    
    int result = calculate_sum(data, 5);
    
    printf("The sum is: %d\n", result);
    
    return 0;
}
