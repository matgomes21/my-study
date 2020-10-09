#include<stdio.h>

void mergesort(int *v, int l, int r1, int r2) {
  int *v2 = malloc(sizeof(int) * (r2-l+1));
  int k = 0, i = l, j = r1+1;
  while(i<=r1 && j<=r2) {
    if(lesseq(v[i], v[j]))
      v2[k++] = v[i++];
    else v2[k++] = v[j++];
  }

  while(i<=r1){
    v2[k++] = v[i++];
  }
  
  while(j<=r2){
    v2[k++] = v[j++];
  }

  k = 0;
  for(i=l; i<=r2; i++) {
    v[i] = v2[k++];
  }

  free(v2);
}