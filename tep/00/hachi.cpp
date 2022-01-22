#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node {
  long long int x;
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

int checkMultiple(int x1, int x2, int x3){
  int sum=0;
  sum+=x1;
  sum*=10;
  sum+=x2;
  sum*=10;
  sum+=x3;
  if(sum%8==0)return 1;
  return 0;
}

int main() {
  long long int s,copy,x,check,n=0,sum=0;

  le = (Node *) malloc(sizeof(Node));
  le->next = NULL;
  scout = le;

  cin >> s;

  copy = s;

  for(;s>0;s/=10){
    insert(s%10);
    n++;
  }

  if(n==0){
    cout<< "No" << endl;
    return 0;
  }

  if(n==1){
    if(copy%8==0)
      cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  if(n==2){
    if(copy%8==0){
      cout << "Yes" << endl;
      return 0;
    }

    sum+=le->next->x;
    sum*=10;
    sum+=le->next->next->x;
    if(sum%8==0){
      cout << "Yes" << endl;
      return 0;
    }
    cout << "No" << endl;
    return 0;
  }

  for(le=le->next;le->next->next!=NULL;le=le->next){
    for(scout=le->next;scout->next!=NULL;scout=scout->next){
      for(scout2=scout->next;scout2!=NULL;scout2=scout2->next){
        if(checkMultiple(le->x,scout->x,scout2->x)||checkMultiple(le->x,scout2->x,scout->x)||checkMultiple(scout->x,le->x,scout2->x)||checkMultiple(scout->x,scout2->x,le->x)||checkMultiple(scout2->x,le->x,scout->x)||checkMultiple(scout2->x,scout->x,le->x)){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;

  return 0;
}