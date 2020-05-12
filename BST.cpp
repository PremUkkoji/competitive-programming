#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	struct Node *left = NULL, *right = NULL;
} *temp = NULL, *root = NULL;

void insert(struct Node *root, struct Node *temp){
	if(temp->val <= root->val){
		if(root->left == NULL)
			root->left = temp;
		else
			insert(root->left, temp);
	}
	if(temp->val > root->val){
		if(root->right == NULL)
			root->right = temp;
		else
			insert(root->right, temp);
	}
}

void create(int n){
	temp = (struct Node *) malloc(sizeof(struct Node));
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
}

void inorder(Node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

void preorder(Node *root){
	if(root!=NULL){
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}

void search(int key){
	temp = root;
	while(temp!=NULL){
		if(temp->val == key){
			cout<<"\nfound";
			return;
		}
		if(key < temp->val){
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}
	cout<<"\nnot found";
}

signed main(){
	int arr[] = {6,9,2,1,2,3,2,5,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		create(arr[i]);
		if(root == NULL){
			root = temp;
		}else{
			insert(root, temp);
		}
	}
	cout<<"inorder : ";
	inorder(root);
	cout<<"\npreorder : ";
	preorder(root);
	cout<<"\npostorder : ";
	postorder(root);

	search(7);
	search(10);
	search(1);
	return 0;
} 