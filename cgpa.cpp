#include<iostream>
using namespace std;

float GPA(float g, int h)
{
    
    return  g/h;
}
float Result(int n, float f)
{
    float grade_Po=+(f*n);
    return  grade_Po;
}

int main()
{
    int NS;
    int NC,NH;
    float grad, ar[8];
    float grand_Total_Points=0;
    float grade_Points=0;
    int total_Hours=0;
    int grand_Total_Hours=0;
    float gpa=0;
    cout<<" Welcome To CGPA Calcuator "<<endl;
    while(NS)
    {
        cout<<" Enter the Number of semesters.";
        cin>>NS;
        if(0<=NS<=8)
        {
            cout<<" Lets Start....."<<endl;
            break;
        }
        else
        {
            cout<<" Invalid Input "<<endl<<" Try Again!"<<endl;
        }
    }
        for(int i=1; i<=NS; i++)
        {    
            cout<<"Enter the data of Semester "<<i<<endl;
            cout<<"Enter the Number of courses: ";
            cin>>NC;
            grade_Points=0;
            total_Hours=0;
            for(int j=0; j<NC; j++)
            {
                //course iteration
                cout<<" Enter the Grades of course "<<(j+1)<<endl;
                cin>>grad;
                ar[j]=grad;
                cout<<" Enter the credit Hours:  ";
                cin>>NH;
                grade_Points += Result(NH, grad);
                total_Hours +=NH;
            }
        
        for(int i=0; i<NC; i++)
        {
            cout<<"Grade of Course "<<1<<endl;
            cout<<ar[i]<<endl;
        }
        cout<<"GPA of the Semester "<<i<<" is "<<GPA(grade_Points, total_Hours)<<endl;
        grand_Total_Points += grade_Points;
        grand_Total_Hours += total_Hours;
        }
        cout<<"Total Grade Points of whole Program: "<<grand_Total_Points<<endl;
        cout<<"Total credit Hours of whole Program: "<<grand_Total_Hours<<endl;
        cout<<"CGPA OF WHOLE PROGRAM IS "<<GPA(grand_Total_Points, grand_Total_Hours);
        cout<<endl<<"Program Ended! ";
}
