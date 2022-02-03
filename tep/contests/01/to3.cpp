#include <iostream>
#include<stdlib.h>

using namespace std;

typedef struct node {
  int x;
  struct node *next;
} Node;

Node *le,*scout,*scout2;

void insert(int x){
  Node *born;
  born = (Node *)malloc(sizeof(Node));
  born->x = x;
  scout->next = born;
  born->next = NULL;
  scout = born;
}

int main() {
  float x;
  int e, n=0,skip=0;
  long long int sum=0;

  le = (Node *) malloc(sizeof(Node));
  le->next = NULL;
  scout = le;

  cin >> x;

  for(int y=x;y>0;y/=10){
    insert(y%10);
    n++;
  }

  for(scout=le->next;scout!=NULL; scout=scout->next){
    sum+=scout->x;
  }

  if(sum%3==0){
    cout << 0 << endl;
    return 0;
  }

  for(e=1;e<n;e++){
    sum=0;
    scout = le->next;
    for(int i=0; i<n && scout!=NULL; i++){
      if(i!=skip){
        sum+=scout->x;
      }
      scout = scout->next;
    }
    skip++;
  }

  cout << -1 << endl;

  return 0;
}