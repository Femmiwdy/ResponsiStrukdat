#include <iostream>
#include <string>

#define MAX 20
using namespace std;

void push(char);
char pop();
string isi(string);
int priority (char);
char stk[MAX];
int top = -1;
bool isFull();
bool isEmpty();
void cetak();

int main(){
    string pesan,fix;
    cout << "Masukkan Pesan : ";
    cin>>pesan;
    fix = isi(pesan);
    cetak();
    return 0;
}

bool isFull(){
    if(top == MAX -1)
        return true;
    else
        return false;
}

bool isEmpty(){
    if(top== -1)
        return true;
    else
        return false;

}

void push(char oper){
    if(isFull()){
        cout<<" ";
    }else{
        top++;
        stk[top] = oper;
    }
}

char pop(){
    char ch;
    if(isEmpty()){
        cout<< " ";
    }else{
        ch = stk[top];
        stk[top]= '\0';
        top--;
        return ch;
        }
    return 0;
}

string isi(string pesan){
    int i = 0;
    string pst = "";

    while(pesan[i]!='\0'){

        if(pesan[i]>='A' && pesan[i]<='Z'){
            pst.insert(pst.end(),pesan[i]);
            i++;
        }
        else if(pesan[i] == '*' ){
                pop();
                i++;

        }
        else{
            if(top == -1){
                push(pesan[i]);
                i++;
            }
            else if(priority(pesan[i]) <= priority(stk[top])){
                pst.insert(pst.end(),pop());

                while(priority(pesan[i]) == priority(stk[top])){
                   pst.insert(pst.end(),pop());
                   if(top < 0){
                    break;
                   }
                }
                push(pesan[i]);
                i++;
            }
            else if(priority(pesan[i]) > priority(stk[top])){
            push(pesan[i]);
            i++;
        }
    }
}
    while(top != -1){
        pst.insert(pst.begin(),pop());
    }

    cout<<"Cetak : " << pst;
    return pst;
}

    int priority(char alpha){
        if(alpha == '+' || alpha == '-'){
            return 1;
        }
        if(alpha == '*' || alpha == '/'){
            return 2;
        }
        if(alpha == '$'){
            return 3;
        }
    return 0;
}
void cetak(){
    for(int i =0 ; i<=top ; i++){
        cout<<stk[i]<<" ";
    }
}








