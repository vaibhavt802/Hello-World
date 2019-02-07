#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

class node
{
	public:
		int data;
		node* left,*right;
		node (int x)
		{
			data = x;
			left = right = NULL;
		}
};

class AVL
{
	node *root;
	public :
		AVL ()
		{
			root = NULL;
		}
		void create ();
		node* insert_rec(node *,int );
		void inorder ();
		void inorder_rec (node *);
		node *LL (node *);
		node *LR (node *);
		node *RR (node *);
		node *RL (node *);
		int height (node *);
		int bal_fact (node *);
		int Bal_fact (node *);
		void delete_nonrec ();
		node *delete_rec (node *);
};

void AVL :: create ()
{
	char arr[20];
	while (1)
	{
		cout<<"Enter data to inseert or stop to stop\n";
		cin>>arr;
		if (strcmp(arr,"stop") == 0)
		{
			break;
		}
		int x = atoi (arr);
		root = insert_rec (root,x);
	}
}

node *AVL :: insert_rec (node *T, int x)
{
	//node *p = T;
	if (T == NULL)
	{
		return new node (x);
	}
	if (T->data > x)
	{
		T->left = insert_rec (T->left,x);
		if (bal_fact (T) == 2)
		{
			if (x < T->left->data)
			{
				T = LL (T);
			}
			else
			{
				T = LR (T);
			}
		}
		return T;
	}
	else if (T->data < x)
	{
		T->right = insert_rec (T->right,x);
		if (bal_fact (T) == 2)
		{
			if (x < T->right->data)
			{
				T = RR (T);
			}
			else
			{
				T = RL (T);
			}
		}
		return T;
	}
	return T;
}

node * AVL :: LL (node *t)
{
	node *p = t->left;
	t->left = p->right;
	p->right = t;
	return p;
}

node *AVL :: RR (node *t)
{
	node *p = t->right;
	t->right = p->left;
	p->left = t;
	return p;
}

node *AVL :: LR (node *t)
{
	node *p = t->left;
	node *y = p->right;
	t->left = y;
	p->right = y->left;
	y->left = p;
	t = LL (t);
	return t;
}

node *AVL :: RL (node *t)
{
	node *p = t->right;
	node *y = p->left;
	t->right = y;
	p->left = y->right;
	y->right = p;
	t = RR (t);
	return t;
}

int AVL :: height (node *t)
{
	if (t == NULL)
		return -1;
	return 1+max (height (t->left),height (t->right));
}

int AVL :: bal_fact (node *t)
{
	int x = (height(t->left) - height (t->right));
	if (x < 0)
	{
		x = -(x);
	}
	return x;
}

int AVL :: Bal_fact (node *t)
{
	return (height(t->left) - height (t->right));
}

void AVL :: delete_nonrec ()
{
	int x;
	cout<<"Enter data to delete\n";
	cin>>x;
	root = delete_rec (root, x);
}

node *AVL :: delete_rec (node *t, int x)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (x < t->data)
	{
		t->left = delete_rec (t->left,x);
	}
	else if (x > t->data)
	{
		t->right = delete_rec (t->right,x);
	}
	if (t->left == NULL && t->right == NULL)
	{
		delete t;
		return NULL;
	}
}

void AVL :: inorder()
{
	inorder_rec (root);
}

void AVL :: inorder_rec (node *p)
{
	if (p != NULL)
	{
		inorder_rec (p->left);
		cout<<p->data<<"\t";
		inorder_rec (p->right);
	}
}

int main ()
{
	AVL obj;
	int x = 0;
	while (1)
	{
		cout<<"Enter\n1 - create a tree\n2 - delete a node\n3 - show a tree\n4 - exit\n";
		cin>>x;
		switch (x)
			{
				case 1:
					obj.create ();
					break;
				case 2:
					break;
				case 3:
					obj.inorder();
					break;
				case 4:
					exit (0);
					break;
			}
	}
}

