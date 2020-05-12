#include<bits/stdc++.h>
using namespace std;
#define IB insert_beginning()
#define IE insert_end()
#define DB delete_beginning()
#define DE delete_end()
int cnt = 0;

struct Node{
	int val;
	struct Node *prev = NULL, *next = NULL;
} *first = NULL, *temp = NULL, *last = NULL;

Node* create(){
	struct Node* temporary = (struct Node *) malloc(sizeof(struct Node));
	temporary->val = ++cnt;
	return temporary;
}

void show_list(){
	cout<<"List status : ";
	temp = first;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void insert_beginning(){
	temp = create();
	if(first==NULL){
		first=last=temp;
	}else{
		first->prev = temp;
		temp->next = first;
		first = temp;
	}
	show_list();
}

void insert_end(){
	temp = create();
	if(first==NULL){
		first=last=temp;
	}else{
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
	show_list();
}

void delete_beginning(){
	if(first==NULL) return;
	if(first->next==NULL){
		free(first);
		first=last=NULL;
		cnt--;
	}else if(first!=NULL){
		temp = first->next;
		temp->prev = NULL;
		first->next = NULL;
		free(first);
		first = temp;
		cnt--;
	}
	show_list();
}

void delete_end(){
	if(first==NULL) return;
	if(first->next==NULL){
		free(first);
		first=last=NULL;
		cnt--;
	}else if(first!=NULL){
		temp = last->prev;
		temp->next = NULL;
		last->prev = NULL;
		free(last);
		last = temp;
		cnt--;
	}
	show_list();
}

signed main(){
	IB;IB;IE;IE;DB;DE;DB;DE;DB;
	return 0;
}