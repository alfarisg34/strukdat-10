/*	Nama program	: Exercise-03
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 14 05 2019
	Deskripsi		: tree
********************************************************************/
#include <iostream>
using namespace std;

struct Simpul {
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;
void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout << "Masukkan satu angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}
void insertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
    Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left,pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right,pBaru);
    else
        cout<<"sudah ada";
}
void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<" ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}
void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<" ";
        inOrder(Root->right);
    }
}
void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<" ";
    }
}
void notasiKurung(Tree Root){
    if (Root != NULL){
        cout<<"( ";
        cout<< Root->info;
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout<<" )";
        }
}
int main(){
    Tree Root;
    pointer pBaru;
    int pilihan;
    Root = NULL;
    do{
        cout<<"\tMENU"<<endl;
        cout<<"1. Input"<<endl;
        cout<<"2. Preorder"<<endl;
        cout<<"3. Inorder"<<endl;
        cout<<"4. Postorder"<<endl;
        cout<<"5. Notasi Kurung"<<endl;
        cout<<"pilihan : ";cin>>pilihan;
        switch (pilihan)
        {
        case 1:
            CreateSimpul(pBaru);
            insertBST (Root,pBaru);
            break;
        
        case 2:
            cout<<"preorder"<<endl;
            preOrder (Root);
            cout<<endl;
            break;

        case 3:
            cout<<"inorder"<<endl;
            inOrder (Root);
            cout<<endl;
            break;

        case 4:
            cout<<"postorder"<<endl;
            postOrder (Root);
            cout<<endl;
            break;

        case 5:
            cout<<"postorder"<<endl;
            notasiKurung(Root);
            cout<<endl;
            break;

        default:
            break;
        }
    }while(pilihan==1||pilihan==2||pilihan==3||pilihan==4||pilihan==5);
    
    
}