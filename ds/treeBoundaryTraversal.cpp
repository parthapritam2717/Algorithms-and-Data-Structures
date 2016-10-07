/* A binary tree node
struct node
{
    int data;
    struct Node* left, * right;
}; */


void printLeaves(node *root){
    if(root==NULL){
        return;
    }
    if(root){
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" ";
        }
        printLeaves(root->left);
        printLeaves(root->right);
    }
}
void printLeftBorder(node *root){
    if(root==NULL){
        return;
    }
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printLeftBorder(root->left);
        }
        else if(root->right){
            cout<<root->data<<" ";
            printLeftBorder(root->right);
        }
    }
}
void printRightBorder(node *root){
    if(root==NULL){
        return;
    }
    if(root){
        if(root->right){
             printRightBorder(root->right);
             cout<<root->data<<" ";
        }
        else if(root->left){
            printRightBorder(root->left);
            cout<<root->data<<" ";
        }
    }

}


void printBoundary(node *root)
{
//Your code here
    if(root==NULL){
        return;
    }
    if(root){
        cout<<root->data<<" ";
        printLeftBorder(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printRightBorder(root->right);
    }
}
