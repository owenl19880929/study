#include <stdio.h>

int main(int argc, char** argv)
{
    int i = 0;

    if(i != 0)
        goto a;

    printf("before goto \n");

a:
    printf("a lable \n");



}
