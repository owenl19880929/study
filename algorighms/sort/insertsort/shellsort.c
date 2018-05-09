#include <stdlib.h>
#include <stdio.h>

typedef struct JDtag {
  int key;
  int value;
}JD;

void printarray(int* array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d,", array[i]);
    }
    printf("\n");
}


void shellsort(int* r, int n, int* d, int T){
    int i , j, k;
    int x;
    k = 0;
    
    while(k < T){
        printf("######k=%d, d[k]=%d######\n", k , d[k]);
        printarray(r, n);       
        for(i = d[k]; i<n; i++){
            x = r[i];
            j = i - d[k];
	    printf("@@@i=%d, x=r[i]=%d, j=%d@@@\n", i, r[i], j);
	    while((j >= 0) && x < r[j]){
                printf("r[j]=%d\n", r[j]);
	        r[j+d[k]] = r[j];
                j = j - d[k];
	    }
	    r[j+d[k]] = x;
        }
        k++;
    }
}



void swapInt(int * a,int*b)
{
 int c=*a;
 *a=*b;
 *b=c;
}

void shell(int*data,unsigned int len)
{
    if(len<=1||data==NULL)
        return;
    int div, i, j, k;
    for(div=len/2;div>=1;div=div/2)//定增量div，并不断减小
    {
        printf("---------------div=%d---------------\n", div);
        for(i = 0; i < div; ++i)
        {
	    printf("######current is group:%d\n", i);
            for(j = i + div; j < len; j += div){
                int x = data[j];
                k = j - div;
		while((k >= 0) && (data[k] > x)){
		    data[k+div] = data[k];
		    k -= div;
		}
		data[k+div] = x;
            }
      
        }
    }
}

int main(int argc, char** argv){

    //int* r = malloc(10);
    int r[] = {49, 38, 65, 97, 76, 13, 27, 48, 55, 4, 3, 37, 45, 20,46};
    //int* d = malloc(3);
    int d[] = {5, 3, 1};

    printarray(r, 15);    
    //shellsort(r, 15, d, 3);
    shell(r, 15);
    printarray(r, 15);
  
    

    return 0;
}
