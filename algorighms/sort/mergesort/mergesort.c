#include <stdio.h>
#include <stdlib.h>

void printarray(int* array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d,", array[i]);
    }
    printf("\n");
}

void merge(int* r, int* tmp, int lpos, int rpos, int rend){
    int lend = rpos - 1;
    int tmppos = lpos;
    int length = rend - lpos + 1;
    printf("merge: lpos=%d, lend=%d, rpos=%d, rend=%d\n", lpos, lend, rpos, rend);
    while((lpos <= lend) && (rpos <= rend)){
        if(r[lpos] <= r[rpos]){
            tmp[tmppos++] = r[lpos++];   	
        }else{
            tmp[tmppos++] = r[rpos++];
        }
        
        //printf("tmp[i]=%d\n", tmp[tmppos-1]);
    }

    while(lpos <= lend){
        tmp[tmppos++] = r[lpos++];
    }

    while(rpos <= rend){
        tmp[tmppos++] = r[rpos++];
    }

    int i;
    
    for(i = 0; i < length; i++, rend--){
        r[rend] = tmp[rend];
    }
    printarray(r, 10);
    printarray(tmp, 10);

}

void msort(int * r, int* tmp, int left, int right, int flag){
    int center;
    printf("msort: flat = %d, left=%d, right=%d\n", flag, left, right);
    if(left < right){
        center = (left + right) / 2;
        printf("center=%d\n", center);
        msort(r, tmp, left, center, 0);
        msort(r, tmp, center+1, right, 1);
	merge(r, tmp, left, center+1, right);
    }
    
}

void mergesort(int* r, int n){

    if(r == NULL || n == 0){
        return;
    }

    int * tmparray;
    tmparray = malloc(n*sizeof(int));
    if(tmparray != NULL){
        msort(r, tmparray, 0, n-1, 2);
        free(tmparray);
    }

}

int main(int argc, char** argv){

    int r[] = {14, 56, 72, 18, 4, 90, 38, 76, 98, 31};    
    printarray(r, 10);
    mergesort(r, 10);
    printarray(r, 10);   
    return 0;
}
