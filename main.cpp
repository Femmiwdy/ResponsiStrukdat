#include<iostream>
#include<string>
#define MAX 20
using namespace std;


void push(char);
void print();
char pop();
string stackk(string pesan);
char stk[20];
int priority(char);
int top=-1;
bool isFull();
bool isEmpty();

int main()
{
    int cont;
    string pesan, postfix;
    cout<<"masukkan pesan : ";
    cin>>pesan;
    postfix = stackk(pesan);
    //print();
    return 0;
}

bool isFull(){
    if(top == MAX - 1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

// prosedur memasukkan operator ke stack
void push(char oper)
{
    if(isFull())
    {
        cout<<"stack penuh";
    }

    else
    {
        top++;
        stk[top]=oper;
    }
}

// fungsi untuk menghapus data dari stack
char pop()
{
    char ch;
    if(isEmpty())
    {
        cout<<"stack kosong!!!!";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
void print(){
    if (top == -1) {
        cout << "empty";

    }else {
        cout << "          Stack : ";
        cout << "\n===========================" << endl;
 for (int i = top; i >= 0; i--){
        cout << "     XXXXX[ " << stk[top] << " ]XXXXX" << endl;
 }
        cout << "===========================" << endl;
    }
}


string stackk(string pesan)
{
    int i=0;
    string stc = "";



    // looping selama urutan terakhir string tidak kosong
    while(pesan[i]!='\0')
    {


        // jika ketemu alpabet, push ke stack
        if(pesan[i]=='a' || pesan[i]=='z')
        {
            push(pesan[i]);
            i++;
        }


        //jika ketemu *, pop dari stack
        else if(pesan[i]=='*')
        {
            if(pesan[i]=='*')
            {
                while(stk[top]!='A' && stk[top]!='Z')
                {
                    stc.insert(stc.end(),pop());
                }
                pop();
                i++;
            }


            }

        else
        {

            // jika stack kosong, push ke stack
            if(isEmpty())
            {
                push(pesan[i]);
                i++;
            }
            else if( priority(pesan[i]) <= priority(stk[top])) {
                stc.insert(stc.end(),pop());

                // jika prioritas operator sama dengan operator di stack, pop
                while(priority(stk[top]) == priority(pesan[i])){
                    stc.insert(stc.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(pesan[i]);
                i++;
            }


        }
        while(top!=-1)
    {
        stc.insert(stc.end(),pop());
    }
    cout<<"Cetak : "<<stc;
    return stc;
    }
}
int priority (char alpha){

    if(alpha == '*' || alpha =='*')
    {
        return 1;
    }
}




