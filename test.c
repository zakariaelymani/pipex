#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int i = open("file.txt", O_WRONLY | O_CREAT, 0777);
    // int i = open("file.txt", O_WRONLY | O_CREAT, 0777);
   
   dup2(i, 1);
    printf("output to this file don't freez your self\n");
}