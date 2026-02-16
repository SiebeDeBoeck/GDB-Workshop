#include <stdio.h>

/* === GDB TUTORIAL ===
   1. Compile: cc -g -O0 null_pointer.c
   2. Start:   gdb ./a.out
   
   3. Visuals: Type 'layout src'
      (If screen gets messy, press Ctrl + L to refresh)

   4. Run:     Type 'run'
      -> CRASH! "Program received signal SIGSEGV, Segmentation fault."
      -> GDB highlights the line: *ptr = new_value;

   5. Inspect: Type 'print ptr'
      -> Result: (int *) $1 = 0x0
      -> Meaning: You are writing to NULL.

   6. Quit:    Type 'quit' (or 'q')
*/

void update_value(int *ptr, int new_value) {
    // CRASH HAPPENS HERE
    *ptr = new_value; 
    printf("Value updated to: %d\n", *ptr);
}

int main() {
    int number = 10;
    int *my_pointer = NULL; // BUG: Initialized to NULL

    printf("Starting program...\n");

    update_value(&number, 20); // This works
    update_value(my_pointer, 30); // This crashes

    printf("End of program.\n");
    return 0;
}
