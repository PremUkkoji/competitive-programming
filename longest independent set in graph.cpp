// in this program every node has atmost 2 childs

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left=NULL, *right=NULL;
} *root=NULL;

node* create_node(int n){
	struct node *temporary = (struct node *) malloc(sizeof(struct node));
	temporary->data = n;
	return temporary;
}

int countMaximumIndependentSet(struct node *root, map< int, pair<int, int> >& memo){
	if(root == NULL)
		return 0;

	// if its already calculated send it from here itself don't further calculate it
	if(memo.find(root->data) != memo.end())
		return max(memo[root->data].first, memo[root->data].second);

	// including current node and grandchilds
	int include = 1;
	if(root->left!=NULL)
		include += countMaximumIndependentSet(root->left->left, memo) + countMaximumIndependentSet(root->left->right, memo);
	if(root->right!=NULL)
		include += countMaximumIndependentSet(root->right->left, memo) + countMaximumIndependentSet(root->right->right, memo);

	// excluding current node and including childs
	int exclude = countMaximumIndependentSet(root->left, memo) + countMaximumIndependentSet(root->right, memo);

	// if not already present memorize it
	memo[root->data].first = include;
	memo[root->data].second = exclude;

	return max(include, exclude);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// creating graph
	root = create_node(10);
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
	node1 = create_node(20);
	node2 = create_node(30);
	node3 = create_node(40);
	node4 = create_node(50);
	node5 = create_node(60);
	node6 = create_node(70);
	node7 = create_node(80);

	root->left = node1;
	root->right = node2;
	node1->left = node3;
	node1->right = node4;
	node2->right = node5;
	node4->left = node6;
	node4->right = node7;

	map< int, pair<int, int> > memo;

	cout<<countMaximumIndependentSet(root, memo);

	return 0;
}