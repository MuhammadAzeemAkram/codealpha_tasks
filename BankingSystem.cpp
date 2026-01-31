#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace std;
class Customer
{
    public:
    
    void newCustomer()
    {
        string Name;
        int Balance=0; int Key;
        string   passkey, nm, pass ,AcNum;
        bool flag=0;
        cout<<"Enter Customer Name : ";
        cin>>Name;
        cout<<"Enter A Password : "<<endl;
        cout<<"PassWord must of minimum 4 characters "<<endl;
        cin>>passkey;
        if(passkey.length()<4)
        {
            cout<<"Transfer key is too short"<<endl;
            return;
        }
        ifstream cust1;
        cust1.open("CustomerDetails.txt");
        while(cust1>>nm>>pass>>AcNum)
        {
            if(Name==nm)
            {
                cout<<"Customer Name Already Exist!....."<<endl;
                flag=1;
                break;
            }
        }
        cust1.close();
        if(flag==0)
        {
            cout<<"Enter Transction key "<<endl;
            cout<<"Transction key must be of four digits only "<<endl;
            cin>>Key;
            cout<<"Your Account Number is "<<endl;
            AcNum=Name;
            AcNum+="GB1122";
            AcNum+=passkey;
            cout<<AcNum<<endl;
            ofstream cust2;
            cust2.open("CustomerDetails.txt" ,ios ::app);
            cust2<<Name<<"  "<<passkey<<"  "<<AcNum<<"  "<<endl;
            cout<<"Account Activate......"<<endl;
            cust2.close();
            ofstream cust3;
            cust3.open("TransKey.txt", ios::app);
            cust3<<Name<<"  "<<Key<<endl;
            cust3.close();
            ofstream cust4;
            cust4.open("Balance.txt" , ios::app);
            cust4<<Name<<"  "<<Balance<<endl;
            cust4.close();
        }
    }
    int CustomerLogin(string Name, string passkey)
    {
        int flag=0;
        int  Key;
        string nm, pass, AcNum;
        ifstream cust3;
        cust3.open("CustomerDetails.txt");
        while(cust3>>nm>>pass>>AcNum)
        {
            if(nm==Name && pass==passkey)
            {
                cout<<"Login Succussful ..... ....."<<endl;
                cust3.close();
                return 1;
            }
        }
        if(flag==0)
        {
            cout<<"Customer Name or PassWord is not correct."<<endl;
            cout<<"Please Try again with correct Data."<<endl; 
            cust3.close();
            return 0;
        }
    }
    void TermCondition()
    {
        cout<<"There are Terms and Conditions of Our Bank"<<endl;
        cout<<"Each customer may maintain only one account with Great Bank. Multiple accounts are strictly prohibited. Customers must provide accurate information, follow banking policies, comply with laws, and accept that the bank may suspend or close accounts for violations"<<endl;
    }
};
class Account : public Customer
{
    public:
    void AccountData(string Name)
    {
        int Key,balance;
        string passkey, pass, nm, AcNum;
        ifstream acc1;
        acc1.open("CustomerDetails.txt");
        while(acc1>>nm>>pass>>AcNum)
        {
            if(Name==nm)
            {
                cout<<"Your Account Details "<<endl;
                cout<<"Customer Name : "<<nm<<endl;
                cout<<"Account NUmber : "<<AcNum<<endl;
                break;
            }

        }
        acc1.close();
        ifstream acc2;
        acc2.open("Balance.txt");
        while(acc2>>nm>>balance)
        {
            if(Name==nm)
            {
                cout<<"Balance is "<<balance<<endl;
                break;
            }
        }
        acc2.close();
    }


};
class Transection : public Account
{
    public:
    
    void Deposit(string Name, int Balan)
    {
        int  balance;
        string  nm, Mode="Deposit";
        bool flag=false;
        ifstream acc3;
        acc3.open("Balance.txt");
        ofstream acc4;
        acc4.open("temp.txt" , ios::app);
        while(acc3>>nm>>balance)
        {
            if(Name==nm)
            {
                cout<<"Customer Validity Checked"<<endl;
                balance+=Balan;
                acc4<<nm<<"  "<<balance<<endl;
                flag=true;

            }
            else{
                acc4<<nm<<"  "<<balance<<endl;
            }
        }
        acc3.close();
        acc4.close();
        if(flag==true)
        {
            ofstream TD2("TransDetails.txt" ,ios::app);
            TD2<<Name<<"  "<<Mode<<"  "<<Balan<<endl;
            remove("Balance.txt");
            rename("temp.txt","Balance.txt");
            cout<<"Balance updated"<<endl;
        }
        else{
            remove("temp.txt");
            cout<<"Balance did'n t Update"<<endl;
        }}
    //Withdraw the ammount
    void Withdraw(string Name)
    {
        int balance, Balan, n, key,d,Ba;
        bool foo =false, flag=false;
        string nm,Mode;
        Mode="Withdraw";
        for(int i=1; i<=3; i++)
        {
        cout<<"Enter the data you want to withdraw! "<<endl;
        cin>>Balan;
        ifstream acc6;
        acc6.open("Balance.txt");
        ofstream acc7;
        acc7.open("temp.txt");
        while(acc6>>nm>>balance)
        {
            if(Name==nm)
            {
                if(balance>Balan)
                {
                Ba=balance-Balan;
                acc7<<nm<<"  "<<Ba<<endl;
                flag=true;
                break;
                }
                else{
                    cout<<"Balance is not enough!"<<endl;
                    foo=true;
                    break;
                }
            

            }
            else{
                acc7<<nm<<"  "<<balance<<endl;
            }
        }
        acc6.close();
        acc7.close();
        if(foo==true)
            break;
        if(flag==true)
        {
            ofstream TD("TransDetails.txt", ios::app);
            TD<<Name<<"  "<<Mode<<"  "<<Balan<<endl;
            remove("Balance.txt");
            rename("temp.txt","Balance.txt");
            cout<<"Withdrawal Successful"<<endl;
        }
        else{
            remove("temp.txt");
            cout<<"Balance did'n t Update"<<endl;
        }
    }}
    void Transfer(string Name)
    {
        int balance, Balan, n, key,d;
        bool foo=false, flag=false;
        string nm,Mode,RName;
        Mode="FundTransfer";
        for(int i=1; i<=3; i++)
        {
        cout<<"Enter the data you want to Transfer! "<<endl;
        cin>>Balan;
        cout<<"Enter UserName of Reciever."<<endl;
        cin>>RName;
        ifstream acc8;
        acc8.open("Balance.txt");
        ofstream acc9;
        acc9.open("temp.txt");
        while(acc8>>nm>>balance)
        {
            if(Name==nm)
            {
                if(balance>Balan)
                {
                balance-=Balan;
                acc9<<nm<<"  "<<balance<<endl;
                flag=true;
                    foo=true;
                }
                else{
                    cout<<"Balance is not enough!"<<endl;
                    break;
                } 
            

            }
            else{
                acc9<<nm<<"  "<<balance<<endl;
            }
        }
        acc8.close();
        acc9.close();
        
        if(flag==true)
        {
            ofstream TD("TransDetails.txt", ios::app);
            TD<<Name<<"  "<<Mode<<"  "<<Balan<<endl;
            remove("Balance.txt");
            rename("temp.txt","Balance.txt");
            Deposit(RName,Balan);
            cout<<"Transfer Successful"<<endl;
        }
        else{
            remove("temp.txt");
            cout<<"Balance did'n t Update"<<endl;
        }
        if(foo==true)
        {
            break;
        }
    }
}
    void TransectionDetails(string Name)
    {
        string nm,Mode;
        int Balan;
        
        ifstream TD1("TransDetails.txt");
        while(TD1>>nm>>Mode>>Balan)
        {
            if(nm==Name)
            {
                cout<<"Account Username is "<<Name<<endl;
                cout<<"Mode of Transction : "<<Mode<<endl;
                cout<<"Transection Balance : "<<Balan<<endl;
            }
        }
    }

};
int main()
{
    Transection T1;
    int n;
    bool flag=0;
    string Nam, Name,passkey;
    cout<<"-----....---Welcome to Great Bank---.....-----"<<endl;
    while(flag==0)
    {
    cout<<"Enter 1 for Create Account : "<<endl;
    cout<<"Enter 2 for Login in Your Account : "<<endl;
    cout<<"Enter 3 for Terms and Conditions : "<<endl;
    cout<<"Enter 4 for Exit the Bank : "<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            T1.newCustomer();
            break;
        }
        case 2:
        {
            cout<<"Enter Customer Name : ";
        cin>>Name;
        cout<<"Enter Account PassWord : ";
        cin>>passkey;
            flag=T1.CustomerLogin(Name, passkey);
            Nam=Name;
            break;
        }
        case 3:
        {
            T1.TermCondition();
            break;
        }
        case 4 :
        {
            break;
        }
        default:
        {
            cout<<"INVALID INPUT....PLEASE TRY AGAIN "<<endl;
            break;
        }
    }
    if(n==4)
        {
            cout<<"Sir! Please There is the Exit Gate"<<endl;
            cout<<"For Any Assistance Please Come Again "<<endl;
            break;
        }
    }
    if(flag==1)
    {
        T1.AccountData(Nam);
        while(1)
        {
        cout<<"Enter 1 for Deposit in Your Account"<<endl;
        cout<<"Enter 2 for Withdraw from Your Account"<<endl;
        cout<<"Enter 3 for Transfer Funds from Your Account"<<endl;
        cout<<"Enter 4 for Transection history of Your Account"<<endl;
        cout<<"Enter 5 for Terms&Conditions."<<endl;
        cout<<"Enter 6 for Balance Inquairy."<<endl;
        cout<<"Enter 7 for Exiting the bank"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
            {int Balan;
                cout<<"Enter the Amount you want to deposit in Your Account : ";
                cin>>Balan;
                T1.Deposit(Nam ,Balan );
                break;
            }
            case 2:
            {
                T1.Withdraw(Nam);
                break;
            }
            case 3:
            {
                T1.Transfer(Nam);
                break;
            }
            case 4:
            {
                T1.TransectionDetails(Nam);
                break;
            }
            case 5:
            {
                T1.TermCondition();
            }
            case 6:
            {
                T1.AccountData(Nam);
                break;
            }
            case 7:
            {
                flag=0;
                break;
            }
            default:
            {
                cout<<"INVALID INPUT"<<endl;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Program is Exiting"<<endl;
            break;
        }
    }

}
}