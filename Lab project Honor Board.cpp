#include<bits/stdc++.h>
using namespace std;
class Contestant
{
    protected:
    int ACM_solve;
};
class Student : public Contestant
{
protected:
    float GPA;
    string name;
public:
    Student() { }
    Student(float G,int A,string N)
    {
        GPA=G;
        ACM_solve=A;
        name=N;
    }
    int checkgpa(float ab)
    {
        if(GPA==ab and ACM_solve>=100)
        return 1;
        else return 2;

    }
    float accessGPA()
    {
        return GPA;
    }
};
class Teacher : public Student
{
    string Tname,designation,department,University;
public :
    Teacher() { }
    Teacher (string T,string D,string Dept,string U)
    {
        Tname=T;
        designation=D;
        department=Dept;
        University=U;
    }
    Teacher (float a, int b , string c) : Student(a,b,c)  { }
    void show_student_info()
    {
        cout << setw(10) << name << setw(13) <<  GPA << endl << endl;
    }
    void show_teacher_info()
    {
            cout << endl
            <<"This List has been Prepared by" << endl
            << Tname << endl << designation << endl
            <<"Department of  " << department << endl << University << endl;
    }
};
int main()
{
    int i,n,a,b,j;
    Teacher *performance[9]={ new Teacher(3.27 , 200 , "Shakil"),
    new Teacher(3.81,101,"Tanvir"),
    new Teacher(3.52,45,"Robin"),
    new Teacher(3.86,34,"Tamanna"),
    new Teacher(3.46,199,"Fahim"),
    new Teacher(3.76,300,"Ashik"),
    new Teacher(3.26,267,"Nazim"),
    new Teacher(3.56,198,"Nahid")
     };
     Teacher assigned("Kamal Hossain Chowdhury", "Chairman" , "Computer Science and Engineering", "Comilla University");
    float arr[9],temp;
    int counter=0;
    float maximum;
    for(i=0;i<8;i++)
    {
        arr[i]=performance[i]->accessGPA();

    }
    for(i=0;i<8-1;i++)
        for(j=0;j<8-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j] = temp ;
        }
    }

  cout << " TOP 5 students on the honor Board are" << endl << endl;
  cout << setw(10) << "Student Name "  << setw(10) << "GPA" << endl  ;
  cout << setw(10) << "_____________"  << setw(10) << "____" << endl << endl ;
     for(i=7;i>=0;i--)
     {
         maximum=arr[i];
         for(j=0;j<8;j++)
         {
             if(performance[j]->checkgpa(maximum)==1)
             {
                 counter++;
                 performance[j]->show_student_info();
             }
             if(counter==5) break;
     }
    }
assigned.show_teacher_info();
return 0;
}
