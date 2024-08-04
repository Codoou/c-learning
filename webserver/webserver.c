#include <stdio.h>

int main() {
    printf("Hello World\n");

    int counter, max;
    counter = 1;
    max = 100;

    // main loop
    while (1)
    {
        printf("%d\n",counter);
        counter++;
        /* code */
        if (counter > max)
        {
            /* code */
            break;
        }
        
    }
    
    return 0;
}