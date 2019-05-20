#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name,designation;

};
class Society_Member : public Person
{
    int vote;
    int top;
public :
    Society_Member() { }
    Society_Member(int n) { vote=n; }
    Society_Member(string m, string n )
    {
        designation=n;
        name=m;
        vote=0;
    }
    void getvote(int v)
    {
        vote=v;
    }

    void showdata()
    {
        cout << "Candidate  "  << name << "  got " << vote << "  votes " << endl;
    }
    string accessdata()
    {
        return name;
    }
    int accessvote()
    {
        return vote;
    }
    int updater(int k)
    {
        if(k<vote)
            return 1;
        else return 2;
    }

    Society_Member operator+(Society_Member);
};

Society_Member Society_Member :: operator+( Society_Member c)
{
    Society_Member temp;
    temp.vote = vote + c.vote ;
   // cout << temp.vote<< endl;
    return temp;
}

class Students : public Person
{
public:
    string ID;
    Students() { }
    Students(string m, string n )
    {
        ID=n;
        name=m;
    }
};

class Teachers : public Person
{
public:
    Teachers() { }
    Teachers(string m, string n )
    {
        designation=n;
        name=m;
    }
};



int main()
{
    Society_Member *Member[5]= {new Society_Member("Dipto B.Das","Vice President"),
                       new Society_Member("Jawad Shafi", "General Secretary"),
                       new Society_Member("Kaysar Ahmed", "Joint General Secretary"),
                       new Society_Member("Sadia Nowshin", "Executive"),
                       new Society_Member("Umme Honey Fomy", "Executive")
    };


    Students *random[5]= {new Students("Akramul Shanto","11609022"),
                 new Students("Kaysar Ahmed", "11609033"),
                 new Students("Rakib Mia", "11609012"),
                 new Students("Sakib Hasan", "11601039"),
                 new Students("KM Raj", "11608052")
    };

    Teachers *teacher[3]= {new Teachers("Kamal Hossain","Assistant Professor"),
                 new Teachers("Mahmudul Hasan", "Assistant Professor"),
                 new Teachers("Khairun Nahar Iva", "Lecturer")
    };


    int i,j,n,v;
    string winner;
    cout << "Enter 1 to if you're very dissatisfied \nEnter 2 to if you're dissatisfied \nEnter 3 to if you're neutral \nEnter 4 to if you're satisfied \nEnter 5 to if you're very satisfied\n " << endl;
    for(i=0; i<5; i++)
    {
        cout << "HI " << random[i]->name << " ID No: " << random[i]->ID << " Please give your vote." << endl;
        for(j=0; j<5; j++)
        {
            cout << "Enter your vote for " << Member[j]->name << " , " << Member[j]->designation << ":" ;
            cin >> v;
            Society_Member current_vote(v);
            Society_Member previous_vote(Member[j]->accessvote());
            current_vote = previous_vote+current_vote ;
            Member[j]->getvote(current_vote.accessvote());

        }

    }

    cout << endl << endl;
    for(i=0; i<3; i++)
    {
        cout << "HI " << teacher[i]->name << ", " << teacher[i]->designation << " Please give your vote." << endl;
        for(j=0; j<5; j++)
        {
            cout << "Enter your vote for " << Member[j]->name << " , " << Member[j]->designation << ":" ;
            cin >> v;
            Society_Member current_vote(v);
            Society_Member previous_vote(Member[j]->accessvote());
            current_vote = previous_vote+current_vote ;
            Member[j]->getvote(current_vote.accessvote());
        }

    }
    int top=0,x;
    cout << endl << endl;
    for(i=0; i<5; i++)
    {
        Member[i]->showdata();
    }

    for(i=0; i<5; i++)
    {
        if (Member[i]->updater(top)==1)
        {
            x=i;
            top=Member[i]->accessvote();
        }
    }

    cout << endl << endl;
    cout << Member[x]->name << " is the best society member " << endl;
    return 0;
}

