#include <stdio.h>

void printarray(int* array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d,", array[i]);
    }
    printf("\n");
}

void smpcomparesort(int* r, int n){
    int i, j;
    int tmp;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(r[i] > r[j]){
                tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
            }
        }
    }
}

void bubblesort(int* r, int n){
    int i, j;
    int tmp;
    int lastexchange = n-1;
    int m = n - 1;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(r[j] > r[j+1]){
                tmp = r[j];
                r[j] = r[j+1];
                r[j+1] = tmp;
                lastexchange = j;
            }
        }
        m = lastexchange;
    }
}

void bubblesort1(int* r, int n){
    int i, j;
    int tmp;
    int m = 0;
    int lastexchange = 0;
    for(i = 0; i < n; i++){
        for(j = n - 1; j > m; j--){
            if(r[j] < r[j-1]){
                tmp = r[j];
                r[j] = r[j-1];
                r[j-1] = tmp;
                lastexchange = j;
            }
        }
        m = lastexchange;
    }
}


int main(int argc, char** argv){
    int r[] = {24, 7, 2, 9, 8, 56, 78, 29, 50, 1};
    printarray(r, 10);
    //smpcomparesort(r, 10);
    //bubblesort(r, 10);
    bubblesort1(r, 10);
    printarray(r, 10);

    return 0;
}
