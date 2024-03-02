#include <stdio.h>

/*

   This file is for debugging only.

*/

int increase(int number)
{
    return number + 1; // Type "number" ("?number" for MacOS) and enter in the debug console. Then hit "step-out"
}

int main(int argc, char **argv)
{
    // Simple main program to check that you can debug your code
    // Debugging is a very important skill to have

    // Add a breakpoint (red dot) at line 15 of this file!
    int a = 1;
    a = a + 1;             // Just here! Open the debug console, and type "a" ("?a" for MacOS) and enter! Then, hit "step-over"
    printf("a = %d\n", a); // Type "a" ("?a" for MacOS) and enter again, what's its value now?

    a = increase(a); // Try to hit "step-into" here, and then "step-over" to see what happens

    return 0;
}