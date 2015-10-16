#include <stdio.h>

int main()
{
    char string[20] = "test the input";
    int len_of_command = sizeof(string)/(sizeof(char));
    printf("len = %d\n", len_of_command);
    return 0;
}