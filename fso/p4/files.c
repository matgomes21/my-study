#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
  long int n1,n2;
  int b1,b2;
  int flag;
  FILE *p1,*p2;

  for(int i=1;i<argc-1;i++){
    p1 = fopen(argv[i], "r");

    for(int j=i+1;j<argc;j++){

      p2 = fopen(argv[j], "r");
      
      fseek(p1, 0, SEEK_END);
      fseek(p2, 0, SEEK_END);

      n1 = ftell(p1);
      n2 = ftell(p2);

      if(n1!=n2){
        printf("%s %s diferentes\n",argv[i],argv[j]);
      }
      else{
        rewind(p1);
        rewind(p2);

        flag=1;

        for(int k=0;k<n1&&flag;k++){
          b1 = getc(p1);
          b2 = getc(p2);
          if(b1!=b2){
            printf("%s %s diferentes\n",argv[i],argv[j]);
            flag=0;
          }
        }
        if(flag) printf("%s %s iguais\n",argv[i],argv[j]);

      }
      fclose(p2);
    }
    fclose(p1);
  }

  return 0;
}