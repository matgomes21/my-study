#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node {
  int x,y;
  struct node *next;
} Node;

Node *le,*scout,*scout2;

void insert(int x,int y){
  Node *born;
  born = (Node *)malloc(sizeof(Node));
  born->x = x;
  born->y = y;
  scout->next = born;
  born->next = NULL;
  scout = born;
}

int checkCollinear(int x1, int x2, int x3, int y1, int y2, int y3){
  if((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))==0)return 1;
  return 0;
}

int main() {
  int n,x,y,check;

  le = (Node *) malloc(sizeof(Node));
  le->next = NULL;
  scout = le;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> x >> y;
    insert(x,y);
  }

  for(le=le->next;le->next->next!=NULL;le=le->next){
    for(scout=le->next;scout->next!=NULL;scout=scout->next){
      for(scout2=scout->next;scout2!=NULL;scout2=scout2->next){
        if(checkCollinear(le->x,scout->x,scout2->x,le->y,scout->y,scout2->y)){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;

  return 0;
}