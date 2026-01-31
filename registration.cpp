#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
class REG
{
    private:
    string nm, NM, PW;
    string key;
    string username;
    public:
    int Registration()
    {
        bool option=0;
        cout<<"Enter the username: ";
        cin>>nm;
        cout<<" Enter the Password: ";
        cin>>key;
        ifstream data;
        data.open("validity_Checking.txt");
        while(data>>NM>>PW)
        {
            data>>NM;
            if(NM==nm)
            {
                cout<<" User Already Register! "<<endl;
                data.close();
                option=1;
                break;
            }
                
        }
        if(option==0)
        {
            ofstream data1;
            data1.open("validity_Checking.txt", ios::app);
            data1<<nm<<"  "<<key<<endl;
            data1.close();
            cout<<"Registration Successful! "<<endl;
        }
    }
    int Login()
    {
        bool flag=0;
        cout<<"Enter username "<<endl;
        cin>>nm;
        cout<<"Enter Password "<<endl;
        cin>>key;
        ifstream data2;
        data2.open("validity_Checking.txt");
        while(data2>>NM>>PW)
        {
            if(NM==nm && PW==key)
            {
                cout<<" Login Successful........"<<endl;
                data2.close(); 
                flag=1;
                break;
            }
                
        }
        if(flag==0)
        {
        cout<<" ..Invalid Username OR Password.."<<endl;
        cout<<" Try Again! "<<endl;
        }
        data2.close();
    }
    void exit()
    {
        cout<<" Program is exiting.........."<<endl;
    }
    void display()
    {
        ifstream data4;
        data4.open("validity_Checking.txt");
        cout<<" This is the stored data. "<<endl;
        while(data4>>NM>>PW)
        {
        cout<<NM<<endl<<PW<<endl;
        }
        data4.close();
    }
};
int main()
{
    REG r1;
    int option;
    while(1)
    {
    cout<<"\n"" welcome to Mr.Great.com "<<endl<<endl;
    cout<<" Enter 1 for Login. "<<endl;
    cout<<" Enter 2 for Registration. "<<endl;
    cout<<" Enter 3 for Display. "<<endl;
    cout<<" Enter 4 for Exit."<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
        {
            r1.Login();
            break;
        }
        case 2:
        {
            
            r1.Registration();
            break;
        }
        case 3:
        {
            r1.display();
            break;
        }
        case 4:
        {
            r1.exit();
            break;
        }
        default:
        {
            cout<<"Invalid Input.";
            break;
        }
    }
    if(option==4)
    {
        break;
    }
    }    
    return 0;
}