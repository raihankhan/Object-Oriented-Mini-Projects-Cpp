#include<bits/stdc++.h>
using namespace std;
float arr[9];
int i,cnt=0;

class Person
{
    protected:
    string name;
public:
    Person() { }
    Person(string name)
    {
        this->name=name;
    }
    string acces_person()
    {
        return name;
    }
};

class Contestant
{
    protected:
    int ACM_solve;
};

class Student : public Contestant,public Person
{
protected:
    float GPA;
   // string name;
public:
    Student() { }
    Student(string Name,float GPA,int ACM_solve):Person(Name)
    {
        this->GPA=GPA;
        this->ACM_solve=ACM_solve;
        //name=N;
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
    void show_student_info()
    {
        cout << setw(10) << acces_person() << setw(13) <<  GPA << endl << endl;
    }
};

class Teacher : public Person
{
    protected:
    string designation,Username,Password;
public :
    Teacher() { }
    Teacher (string name,string designation,string Username, string Password):Person(name)
    {

        this->designation=designation;
        this->Username=Username;
        this->Password=Password;
    }
    //Teacher (float a, int b , string c) : Student(a,b,c)  { }
    string access_username(){ return Username;}
    string access_password(){ return Password;}
    void show_teacher_info()
    {
            cout << endl
            <<"This List has been Prepared by" << endl
            << acces_person() << endl << designation << endl;
    }
    int Match_info(string Username,string Password)
    {
        if(this->Username==Username and this->Password==Password)
            return 1;
        else return 2;
    }
    void Bubblesort()
{
int i,j;
float temp;
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
}
};

class Department
{
   protected:
       string Department_name;
       string saved_username[3],saved_password[3];
   public:
       Department() { Department_name="Department of Computer Science and Engineering"; }
       void Save_username_password(string j,string k,int l)
       {
           saved_username[l]=j;
           saved_password[l]=k;
       }
    int  Access_Request1(string Username)
    {
        for(i=0;i<3;i++)
        {
            if(saved_username[i]==Username)
            {
                cnt=1;
                return i;
            }
        }
    }
    int Access_Request2(string Password,int Index)
    {
        if(Password==saved_password[Index])
            return 1;
    }
    void show_dept_name()
    {
        cout << Department_name << endl << endl;
    }
};

class Date
{
    public :
    string  Month[14];
    void Month_initializer()
    {
        Month[0]=" ",Month[1]="January",Month[2]="February",Month[3]="March",Month[4]="April",Month[5]="May",Month[6]="June",Month[7]="July",Month[8]="August",Month[9]="September",Month[10]="October",Month[11]="November",Month[12]="December";
    }
    int year,month,date,x;
    void Incertpresenttime(tm *ltm)
    {
        year=ltm->tm_year + 1900 ;
        month=ltm->tm_mon + 1;
        date=ltm->tm_mday ;

    }
    void display()
    {
        cout << "Date of publication " << endl;
        cout << date << "th  " << Month[month] << "  ," << year << endl;
    }
};

int main()
{
    int n,a,b,j,Index=-1;
    Student *performance[9]={ new Student("Shakil",3.27 , 200  ),
    new Student("Tanvir",3.81,101),
    new Student("Robin",3.52,45),
    new Student("Tamanna",3.86,34),
    new Student("Fahim",3.46,199),
    new Student("Ashik",3.76,300),
    new Student("Nazim",3.26,267),
    new Student("Nahid",3.56,198)
     };


    Department CSE;
    Teacher *assigned_teacher[3]={
         new Teacher("Kamal Hossain Chowdhury", "Chairman","Kamal_Hossain","kamal1234" ),
         new Teacher("Mahmudul Hasan Raju", "Assistant professor", "Mahmudul_Hasan","raju4321"),
         new Teacher("Faisal Bin Abdul Aziz", "Assistant professor","Faisal_Aziz","faisal1234")
     };

     string temp_username,temp_password;
    for(i=0;i<3;i++)
    {
        temp_username=assigned_teacher[i]->access_username();
        temp_password=assigned_teacher[i]->access_password();
        CSE.Save_username_password(temp_username,temp_password,i);
    }


    string Username,Password;

    cout << "Enter the Username" << endl;
    cin >> Username;
    Index=CSE.Access_Request1(Username);
    while(cnt!=1)
    {
    cout << "Invalid Username. Enter again" << endl;
    cin >> Username;
    Index=CSE.Access_Request1(Username);
    }

    cnt=0;

    cout << "Enter the Password" << endl;
    cin >> Password;
    cnt=CSE.Access_Request2(Password,Index);
    while(cnt!=1)
    {
    cout << "wrong password. Enter again" << endl;
    cin >> Password;
    cnt=CSE.Access_Request2(Password,Index);
    }



    float temp;
    int counter=0;
    float maximum;
    for(i=0;i<8;i++)
    {
        arr[i]=performance[i]->accessGPA();
    }


    assigned_teacher[Index]->Bubblesort();


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


assigned_teacher[Index]->show_teacher_info();
CSE.show_dept_name();


time_t now = time(0);
tm *ltm = localtime(&now);
Date A;
A.Incertpresenttime(ltm);
A.Month_initializer();
A.display();


return 0;
}
