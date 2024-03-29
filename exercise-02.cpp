/*	Nama program	: Exercise-02
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 14 05 2019
	Deskripsi		: queue linkedlist
********************************************************************/
#include <iostream>
using namespace std;

struct ElemenQueue {
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};
Queue Q;

void createList(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}
void createElemt(pointer& pBaru){
    pBaru=new ElemenQueue;
    cout<<"Masukkan satu huruf : ";
    cin>>pBaru->info;
    pBaru->next=NULL;
}
void insertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { 
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else { 
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}
void deleteQueue(Queue& Q, pointer& pHapus){
    cout<<"Delete Queue"<<endl;
    if (Q.Head==NULL && Q.Tail==NULL) {
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { 
        pHapus=Q.Head;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { 
        pHapus=Q.Head;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}
void cetak(Queue Q){
    pointer pBantu=Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL){
        cout << "\n\tData masih kosong" << endl;
    }else{
        while(pBantu != NULL){
            cout << pBantu->info;
            pBantu=pBantu->next;
        }
    }
}
int main(){
    Queue Q;
    pointer p;
    int n;

    createList(Q);
    cout<<"Masukkan Banyak elemen : ";cin>>n;
    for(int i=0; i<n; i++)
    {
        createElemt(p);
        insertQueue(Q,p);
    }
    cetak(Q);
    cout <<endl;
    cout << "POP : "<<endl;
    for(int i=0;i<n;i++){
    deleteQueue(Q,p);
    cetak(Q);
    }
}