#include <stdio.h>
#include <stdint.h>

int main() {
    int x = 5;
    x += ++x + x++;
    
    printf("%d %d %d\n", x);
    
    return 0;
}