#include<iostream> #include<string> #include<stdlib.h>
using namespace std;
class RBTnode { public: RBTnode* left; RBTnode* right; RBTnode* parent; int key; string color; RBTnode() //Default Constructor { parent=NULL; left=NULL; right=NULL; key=0; color="red"; } RBTnode(int value) //Parameterised Constructor { parent=NULL; left=NULL; right=NULL; key=value; color="red"; } };
class RBT { public: RBTnode* root; RBTnode* nil; RBT() { nil = new RBTnode(-1); nil->color="black"; nil->left=NULL; nil->right=NULL; root=nil; } void insertnode(); //void deletenode(int); void showtree(RBTnode*); void insertfixup(RBTnode*); void leftrotate(RBTnode*); void rightrotate(RBTnode*);
};
void RBT :: insertnode() { int node_key; cout<<"\nEnter the value of the new node :\n"; cin>>node_key; RBTnode* node = new RBTnode(node_key); RBTnode* ptr; RBTnode* ptr2; ptr=root; if (ptr==nil) { root=node; root->color="black"; root->parent=nil; root->left=nil; root->right=nil;
} else {
while(ptr!=nil) { ptr2=ptr; if (node_key==ptr->key) { cout<<"\nERROR : Repition!\n"; break; } else if (ptr->key>node_key) ptr=ptr->left; else ptr=ptr->right; } if (ptr2->key>node_key) { ptr2->left=node; node->parent=ptr2; node->left=nil; node->right=nil; } else if (ptr2->key<node_key) { ptr2->right=node; node->parent=ptr2; node->left=nil; node->right=nil; }
}
insertfixup(node); cout<<"\nTree after inserting "<<node_key<<" is ->\n";
showtree(root);
}
void RBT :: insertfixup(RBTnode* z) { cout<<"\n1\n"; while ((z->parent)->color=="red") { cout<<"\n2\n"; if (z->parent==((z->parent)->parent)->left) { cout<<"\n**3\n"; RBTnode* y = ((z->parent)->parent)->right; if (y->color=="red") { cout<<"\n4\n"; (z->parent)->color="black"; y->color="black"; ((z->parent)->parent)->color="red"; z=(z->parent)->parent; } else if (z==(z->parent)->left) { (z->parent)->color="black"; ((z->parent)->parent)->color="red"; rightrotate((z->parent)->parent); z=(z->parent)->parent; } else if (z==(z->parent)->right) { cout<<"\n5\n"; z=z->parent; cout<<"\nJust before 1st rotation\n"; leftrotate(z); (z->parent)->color="black"; ((z->parent)->parent)->color="red"; rightrotate((z->parent)->parent); } } else { RBTnode* y = ((z->parent)->parent)->left; if (y->color=="red") { (z->parent)->color="black"; y->color="black"; ((z->parent)->parent)->color="red"; z=(z->parent)->parent; } else if (z==(z->parent)->right) { (z->parent)->color="black";
((z->parent)->parent)->color="red"; leftrotate((z->parent)->parent);
} else if (z==(z->parent)->left) { z=z->parent; rightrotate(z); (z->parent)->color="black"; ((z->parent)->parent)->color="red"; leftrotate((z->parent)->parent); }
}
}
root->color="black";
}
void RBT :: leftrotate(RBTnode* y) { cout<<"\n***LEFT ROTATE***\n"; RBTnode* x = y->right; if (x==nil) { cout<<"Error : Left rotation cannot be performed!\n"; exit(0); } if (x->left!=nil) y->right=x->left; x->left=y; x->parent=y->parent; y->parent=x; if (x->parent==nil) root=x; }
void RBT :: rightrotate(RBTnode* y) { cout<<"\n***RIGHT ROTATE***\n"; RBTnode* x = y->left; if (x==nil) { cout<<"Error : Right rotation cannot be performed!\n"; exit(0); } if (x->right!=nil) y->left=x->right; x->right=y; x->parent=y->parent; y->parent=x; if (x->parent==nil) root=x; } /*
void RBT :: deletenode(int key) { if (root==NULL) { cout<<"\nError : Empty Tree!\n"; } else if ((root->left==NULL) && (root->right==NULL)) { if (root->key==key) { delete root; root=NULL; } else cout<<"\nError : Node not found!\n"; } else { RBTnode* ptr = root; int flag=0; while((ptr->left!=NULL) && (ptr->right!=NULL)) { if (key==ptr->key) { flag=1; break; } else if (key<ptr->key) ptr=ptr->left; else if (key>ptr->key) ptr=ptr->right; } if (flag==1) { if ((ptr->left==NULL) && (ptr->right==NULL)) { if (ptr=(ptr->parent)->left) { (ptr->parent)->left=NULL; delete ptr; } else if (ptr=(ptr->parent)->right) { (ptr->parent)->right=NULL; delete ptr; } } else if ((ptr->right==NULL) && (ptr->left!=NULL)) { (ptr->left)->parent=ptr->parent; delete ptr; }
else if ((ptr->left==NULL) && (ptr->right!=NULL)) { (ptr->right)->parent=ptr->parent; delete ptr; } else { RBTnode* y = ptr->right; while(y!=NULL) y=y->left; ptr->key=y->key; if (y->right==NULL) { (y->parent)->left=NULL; delete y; } else { (y->right)->parent=y->parent; delete y; } }
}
}
} */ void RBT :: showtree(RBTnode* ptr) { if(ptr!=nil) { showtree(ptr->left); cout<<"\nKey : "<<ptr->key<<" "; cout<<"Color : "<<ptr->color<<"\n"; showtree(ptr->right); } }
int main() { RBT tree; char ans='y'; cout<<"\n***INSERTION***\n"; do { tree.insertnode(); cout<<"\nDo you want to continue? <y/n>\n"; cin>>ans; } while(ans=='y'||ans=='Y'); cout<<"\nThe tree is ->\n"; tree.showtree(tree.root); /*int value; char ch='y';
cout<<"\n***DELETION***\n"; do { cout<<"\nEnter the value to be deleted: "; cin>>value; tree.deletenode(value); cout<<"\nDo you want to continue> <y/n>\n"; cin>>ch; } while(ch=='y'||ch=='Y'); cout<<"\nThe tree is ->\n"; tree.showtree(tree.root);
*/
cout<<endl;
}
