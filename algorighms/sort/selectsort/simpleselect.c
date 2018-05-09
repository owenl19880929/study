#include <stdio.h>

void printarray(int* array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d,", array[i]);
    }
    printf("\n");
}

void smp_selectsort(int* r, int n){
    int i, j, k;
    for(i = 0; i < n; i++){
        k = i;
        j = i + 1;
        for(j = i + 1; j < n; j ++){
	    if(r[j] < r[k]){
                k = j;
            }
        }
    
        if(r[i] != r[k]){
            int x;
            x = r[i];
	    r[i] = r[k];
	    r[k] = x; 
        }
    }
}

int main(int argc, char** argv){
    int r[] = {34, 12, 56, 6, 9, 90, 25, 63, 17,59};
    printarray(r, 10);
    smp_selectsort(r, 10);
    printarray(r, 10);
    return 0;
}
