 #include<iostream>
 #include<fstream>
 using namespace std;
 int main()
 {}
 int changePassword()
    { string nm , NM ;
        int key ,PW;
        bool check=0;
        cout<<"Enter username. ";
        cin>>nm;
        cout<<" Enter old Password";
        cin>>key;
        ifstream data3("validity_Checking.txt");
        ofstream data5("temp.txt");
        while(data3>>NM>>PW)
        {
            if(nm==NM && key==PW)
            {
                cout<<"Enter New passWord";
                cin>>PW;
                check=1;

            }
            data5<<NM<<"  "<<PW<<endl;

        }
        if(check==1)
        {
            cout<<"Helloo"<<endl;
            remove("validity_Checking.txt");
            rename("temp.txt", "validity_Checking.txt");
            data5.close();
            data3.close();
        }
        else
        {
            remove("temp.txt");
            data3.close();
            cout<<"Invalid Information Try Again"<<endl;
        }
        
    }