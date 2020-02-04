#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<time.h>

using namespace std;
int number();

class Game
{
    char name[15];
    int qu_no;
    char qu[150];
    char a[30],b[30],c[30];
    char ans;
private:
    void getdata();
    void getdata1();
    void writedata();
    void setqu(int,int);
    int valid(int,char,int);
public:
    void playgame(int);
    void playgame1(int);
    int getnumber(int);
    void addqu(int);
    void writefile(int);
    void print();
    void print1();
    void displayall(int);
    void deletequ();
    void deletequ(int);
    void deleteQCC(int,int);
};
void Game::deleteQCC(int num,int a)
{
    if(a==1)
    {
        ifstream fin;
        ofstream fout;
        fin.open("QBEE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"\nFile Not found"<<endl;
        else
            {
            fout.open("tmp.dat",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
                {
                if(qu_no!=num)
                    {
                        fout.write((char*)this,sizeof(*this));
                    }
                        fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("QBEE.dat");
                rename("tmp.dat","Question.dat");
            }
    }
    else if(a==2)
    {
        ifstream fin;
        ofstream fout;
        fin.open("QDE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"\nFile Not found"<<endl;
        else
            {
            fout.open("tmp.dat",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
                {
                if(qu_no!=num)
                    {
                        fout.write((char*)this,sizeof(*this));
                    }
                        fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("QDE.dat");
                rename("tmp.dat","Question.dat");
            }
    }
    else
    {
        ifstream fin;
        ofstream fout;
        fin.open("Question.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"\nFile Not found"<<endl;
        else
            {
            fout.open("tmp.dat",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
                {
                if(qu_no!=num)
                    {
                        fout.write((char*)this,sizeof(*this));
                    }
                        fin.read((char*)this,sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("Question.dat");
                rename("tmp.dat","Question.dat");
            }
    }
}

int Game::valid(int k,const char l,int a)
{
    if(a==1)
    {
        int flag=0;
        ifstream fin;
        fin.open("QBEE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==k)
                {
                    if(ans==l)
                        flag=1;
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        return flag;
    }
    else if(a==2)
    {
        int flag=0;
        ifstream fin;
        fin.open("QDE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==k)
                {
                    if(ans==l)
                        flag=1;
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        return flag;
    }
    else
    {
        int flag=0;
        ifstream fin;
        fin.open("Question.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==k)
                {
                    if(ans==l)
                        flag=1;
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        return flag;
    }
}
int Game::getnumber(int a)
{
    if(a==1)
    {
        int tmp=0;
        ifstream fin;
        fin.open("QBEE.dat",ios::in|ios::binary);
        if(!fin)
        {
             return ++tmp;
        }
        else
        {
                fin.read((char*)this,sizeof(*this));
                while(!fin.eof())
                {
                    tmp=qu_no;
                    fin.read((char*)this,sizeof(*this));
                }
                fin.close();
        }
        return ++tmp;
    }
    else if(a==2)
    {
        int tmp=0;
        ifstream fin;
        fin.open("QDE.dat",ios::in|ios::binary);
        if(!fin)
        {
             return ++tmp;
        }
        else
        {
                fin.read((char*)this,sizeof(*this));
                while(!fin.eof())
                {
                    tmp=qu_no;
                    fin.read((char*)this,sizeof(*this));
                }
                fin.close();
        }
        return ++tmp;
    }
    else
    {
        int tmp=0;
        ifstream fin;
        fin.open("Question.dat",ios::in|ios::binary);
        if(!fin)
        {
             return ++tmp;
        }
        else
        {
                fin.read((char*)this,sizeof(*this));
                while(!fin.eof())
                {
                    tmp=qu_no;
                    fin.read((char*)this,sizeof(*this));
                }
                fin.close();
        }
        return ++tmp;
    }
}
void Game::addqu(int co)
{
    cin.ignore();
    qu_no=getnumber(co);
    cout<<"Question :"<<qu_no<<endl;
    cout<<"Enter Question :"<<endl;
    cin.getline(qu,150);
    cout<<"Enter Option A:"<<endl;
    cin.getline(a,24);
    cout<<"Enter Option B:"<<endl;
    cin.getline(b,24);
    cout<<"Enter Option C:"<<endl;
    cin.getline(c,24);
    cout<<"Enter Answer (Like A,B,C)"<<endl;
    cin>>ans;
}
void Game::writefile(int a)
{
    if(a==1)
    {
        ofstream fout("QBEE.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
    else if(a==2)
    {
        ofstream fout("QDE.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
    else
    {
        ofstream fout("Question.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
}
void Game::print()
{
    cout<<"\n--------------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<qu_no<<". "<<qu<<endl;
    cout<<"A:"<<a<<endl<<"B:"<<b<<endl<<"C:"<<c<<endl;
    cout<<"\n--------------------------------------------------------------------------------------------------------------\n"<<endl;
}
void Game::print1()
{
    cout<<"\n--------------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<qu_no<<". "<<qu<<endl;
    cout<<"A:"<<a<<endl<<"B:"<<b<<endl<<"C:"<<c<<"\nAnswer :"<<ans<<endl;
    cout<<"\n--------------------------------------------------------------------------------------------------------------\n"<<endl;
}
void Game::displayall(int a)
{
    if(a==1)
    {
        ifstream fin;
        fin.open("QBEE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                print1();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
    else if(a==2)
    {
        ifstream fin;
        fin.open("QDE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                print1();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
    else
    {
        ifstream fin;
        fin.open("Question.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                print1();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
}
void Game::deletequ()
{
    remove("Question.dat");
}
void Game::getdata()
{
    cout<<"Enter Name :"<<endl;
    cin.ignore();
    cin.getline(name,14);
    writedata();
}
void Game::getdata1()
{
    cout<<"\nPlayer 1"<<endl;
    cout<<"Enter Name :"<<endl;
    cin.ignore();
    cin.getline(name,14);
    writedata();
    cout<<"Player 2"<<endl;
    cout<<"Enter Name :"<<endl;
    cin.ignore();
    cin.getline(name,14);
    writedata();
}
void Game::writedata()
{
    ofstream fout("Player.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void Game::setqu(int no,int a)
{
    if(a==1)
    {
        ifstream fin;
        fin.open("QBEE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==no)
                {
                    print();
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
    else if(a==2)
    {
        ifstream fin;
        fin.open("QDE.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==no)
                {
                    print();
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
    else
    {
        ifstream fin;
        fin.open("Question.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File not found"<<endl;
        else
        {
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(qu_no==no)
                {
                    print();
                    break;
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }
}
void Game::playgame(int a)
{
    int score=0;
    int cnt=0;
    ifstream fin;
    fin.open("Player.dat",ios::in|ios::binary);
    if(!fin)
    {
         getdata();
         writedata();
    }
    while(cnt!=3)
    {
        char tmp;
        int no=number();
        setqu(no,a);
        lab:
        cin>>tmp;
        if(tmp=='A' || tmp=='B' || tmp=='C'){
                    if(valid(no,tmp,a))
                    {
                        cout<<"\n\t\t\tYour Answer Is Correct!!!"<<endl;
                        score=score+10;
                        cout<<"\n\t\t\tScore :"<<score<<endl;
                    }
                    else
                    {
                        cout<<"Wrong Answer !!!"<<"\nCorrect Answer :"<<ans<<endl;
                        cnt++;
                        cout<<"You missed chanced "<<cnt<<"/3"<<endl;
                    }
        }
        else
        {
            cout<<"\nYou can't Enter Other than this (A,B,C)"<<endl;
            cout<<"\nEnter Again"<<endl;
            goto lab;
        }
        Sleep(3000);
    }
    cout<<"Well Played!!!"<<endl;
    cout<<"Your Total Score :"<<score<<endl;
    fin.close();
    remove("Player.dat");
}
void Game::playgame1(int a)
{
    int scoreone=0,scoretwo=0;
    int cnt=0;
    ifstream fin;
    fin.open("Player1.dat",ios::in|ios::binary);
    if(!fin)
    {
         getdata1();
         writedata();
    }
    cout<<"\n----------------------\xB1\xB1\xB1\xB1\xB1Player 1\xB1\xB1\xB1\xB1\xB1----------------------"<<endl;
    while(cnt!=3)
    {
        char tmp;
        int no=number();
        setqu(no,a);
        lab2:
        cin>>tmp;
        if(tmp=='A' || tmp=='B' || tmp=='C'){
            if(valid(no,tmp,a))
                {
                    cout<<"Your Answer Is Correct!!!"<<endl;
                    scoreone=scoreone+10;
                    cout<<"Score :"<<scoreone<<endl;
                }
                else
                {
                    cout<<"Wrong Answer !!!"<<"\nCorrect Answer Is :"<<ans<<endl;
                    cnt++;
                    cout<<"You missed chanced "<<cnt<<"/3"<<endl;
                }
        }
        else{
            cout<<"\nYou can't Enter Other than this (A,B,C)"<<endl;
            cout<<"\nEnter Again"<<endl;
            goto lab2;
        }
        Sleep(1000);
    }
    cout<<"Well Played!!!"<<endl;
    cout<<"Your Total Score :"<<scoreone<<endl;
    cout<<"\n\t\t\t\tWait 5 Second"<<endl;
    Sleep(5000);
    cnt=0;
    system("cls");
    cout<<"\n----------------------\xB1\xB1\xB1\xB1\xB1Player 2\xB1\xB1\xB1\xB1\xB1----------------------"<<endl;
    while(cnt!=3)
    {
        char tmp;
        int n=number();
        setqu(n,a);
        lab4:
        cin>>tmp;
        if(tmp=='A' || tmp=='B' || tmp=='C'){
                if(valid(n,tmp,a))
                {
                    cout<<"Your Answer Is Correct!!!"<<endl;
                    scoretwo=scoretwo+10;
                    cout<<"Score :"<<scoretwo<<endl;
                }
                else
                {
                    cnt++;
                    cout<<"You missed chanced "<<cnt<<"/3"<<endl;
                }
        }
        else{
            cout<<"\nYou can't Enter Other than this (A,B,C)"<<endl;
            cout<<"\nEnter Again"<<endl;
            goto lab4;
        }
        Sleep(1000);
    }
    cout<<"\nWell Played!!!"<<endl;
    cout<<"Your Total Score :"<<scoretwo<<endl;
    system("cls");
    Sleep(5000);
    cout<<"\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1"<<endl;
    if(scoreone>scoretwo)
        cout<<"\t\t\t\tPlayer 1 Won the Game"<<"\n\t\t\t\tScore :"<<scoreone<<endl;
    else if(scoreone<scoretwo)
        cout<<"\t\t\t\tPlayer 2 Won the Game"<<"\n\t\t\t\tScore :"<<scoretwo<<endl;
    else
        cout<<"\t\t\t\tScore is equal\n\t\t\t\t Draw match!!!"<<endl;
    cout<<"\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1"<<endl;
    remove("Player1.dat");
}

int main()
{

    Game q;
    int code1;
    /*while(1)
    {
        cout<<number()<<endl;
    }*/
    //for(int i=1;i<43;i++)
    //q.setqu(i);
    //for(int i=39;i<49;i++)
    //q.deleteQCC(24);
    int ch;

    while(1)
    {
        cout<<"\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 Welcome KBC Game\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1"<<endl;
        lable:
        cout<<"\n----------------------------------------------------------"<<endl;
        cout<<"\n1.Single Player\n2.Two Player\n3.Developer\n4.Exit"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"\nEnter Your Choice>>"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                lb1:
                cout<<"1.BEE\n2.DE\n3.DCN"<<endl;
                cout<<"Choose Subject >>"<<endl;
                cin>>code1;
                if(code1>3 || code1<1)
                {
                    cout<<"Wrong Choice!!"<<endl;
                    goto lb1;
                }
                else
                q.playgame(code1);
                break;
            }
        case 2:
            {
                lb3:
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"1.BEE\n2.DE\n3.DCN"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Choose Subject >>"<<endl;
                cin>>code1;
                if(code1>3 || code1<1)
                {
                    cout<<"Wrong Choice!!"<<endl;
                    goto lb3;
                }
                else
                q.playgame1(code1);
                break;
            }
        case 3:
            {
                int ch1,code;
            lab10:
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"1.BEE\n2.DE\n3.DCN"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Choose Subject >>"<<endl;
                cin>>code;

                if(code>3 || code<1)
                {
                    cout<<"Wrong Choice!!!"<<endl;
                    goto lab10;
                }
                else
                {
                        while(1)
                    {
                        cout<<"\n\t1.Add New Question\n\t2.Display All Question\n\t3.Delete Question\n\t4.Delete All\n\t5.Exit\n\tEnter Your Choice>>"<<endl;
                        cin>>ch1;
                        switch(ch1)
                        {
                        case 1:
                            {
                                q.addqu(code);
                                q.writefile(code);
                                break;
                            }
                        case 2:
                            {
                                q.displayall(code);
                                break;
                            }
                        case 3:
                            {
                                int t;
                                cout<<"\nEnter Question No:"<<endl;
                                cin>>t;
                                q.deleteQCC(t,code);
                                break;
                            }
                        case 4:
                            {
                                //q.deletequ();
                                cout<<"Not Permitted !!!"<<endl;
                                break;
                            }
                        case 5:
                            {
                                goto lable;
                                break;
                            }
                        default :
                            {
                                cout<<"Wrong Choice!!!"<<endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        case 4:
            {
                exit(0);
                break;
            }
        default :
            {
                cout<<"Wrong Choice!!!"<<endl;
                break;
            }
        }
    }
}
int number()
{
    int v;
    srand(time(NULL));
    v=rand()%60;
    Sleep(500);
    if(v!=0)
     return v;
    else
      return(number());
}
