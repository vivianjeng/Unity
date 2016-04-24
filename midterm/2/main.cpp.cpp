#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
};


struct node* root;

struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);

int main()
{
    root = NULL;
    int n, v;
	vector<int> s;

    while(cin>>n){
    	s.push_back(n);
    }

    for(int i=1; i<s.size(); i++){
        root = insert(root, s[i]);
    }

	preOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");


    return 0;
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        if(r->value != -1)
        	printf("%d ", r->value);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
    	if(r->value != -1)
        	printf("%d ", r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        if(r->value != -1)
        	printf("%d ", r->value);

    }
}
