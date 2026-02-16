#include <stdio.h>
#include <string.h>

/* === GDB TUTORIAL ===
   1. Compile: cc -g -O0 cmd_args.c
   2. Start:   gdb ./a.out
   3. Visuals: Type 'layout src'

   --- THE CRASH ---
   4. Run:     Type 'run' (No arguments!)
      -> CRASH! "Segmentation fault".
      -> Type 'print argv[1]'. It is 0x0 (NULL).
      -> The program tries to read a missing argument.

   --- THE FIX ---
   5. Restart: Type 'run secret123'
      -> GDB asks to restart? Type 'y'.
      -> Program runs successfully: "Access GRANTED!"
      
   Note: Always check argc before touching argv!
*/

int main(int argc, char *argv[]) {
    char password[] = "secret123";

    printf("Checking password...\n");

    // BUG: We access argv[1] directly without checking argc.
    // If run without args, argv[1] is NULL -> Crash inside strcmp.
    
    if (strcmp(argv[1], password) == 0) {
        printf("Access GRANTED!\n");
    } else {
        printf("Access DENIED.\n");
    }

    return 0;
}
