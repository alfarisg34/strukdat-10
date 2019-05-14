/*	Nama program	: Exercise-01
	Nama			: Alfari Sidnan Ghilmana
	NPM				: 140810180011
	Tanggal buat	: 14 05 2019
	Deskripsi		: queue array
********************************************************************/
#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Queue{
    char isi[maxElemen];
    int head;
    int tail; 
};
void insertQueue(Queue& Q, char elemen) {
    if (Q.tail==maxElemen-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}
void deleteQueue(Queue& Q, char& elemenHapus){
    cout<<"Delete Queue (Antrian) "<<endl;
    if (Q.head>Q.tail){ 
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        for (int i=0;i<Q.tail;i++){ 
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}
int main(){
    Queue Q;
    char elemen;
    int n;

    Q.head = 0;
    Q.tail = -1;
    cout<<"Banyak data : ";cin>>n;
    for (int i=0;i<n;i++){
        insertQueue(Q,elemen);
        cout<<"Input : ";cin>>Q.isi[Q.tail];
    }
    for (int i=0;i<n;i++){
        cout<<Q.isi[i];
    }
    cout<<endl;
    cout<<"POP"<<endl;
    for (int i=0;i<n;i++){
        deleteQueue(Q,elemen);
    }
}