#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int SIZE=100;

class performers
{
    public:
    vector<string> v;         //stl

    void displayp()
    {
        ifstream fin;
        fin.open("Performers.txt");
        string c;
        while (!fin.eof())           //file handling
        {
            getline(fin,c);
            v.push_back(c);
        }
        fin.close();
        for(auto file_line : v)
        {
            cout<<file_line<<endl;;
        }

    }
};
template <class L>           //class template
class learners:public performers
{
    public:
        string c;
        ifstream fin;
        L age,ans;
        learners()            //constructor
        {
            cout<<"Welcome to your new music journey!"<<endl;
            cout<<"Select the options of your choice to find required information"<<endl;
        }
        void displayl()
        {

            cout<<"What do you want to learn?"<<endl;
            cout<<"1.Keyboard"<<"\n"<<"2.Guitar"<<"\n"<<"3.Drums"<<"\n"<<"4.Vocals"<<endl;
            cin>>ans;
            fin.open("Learners.txt");
            while (!fin.eof())
            {
                getline(fin,c);
                v.push_back(c);
            }
            fin.close();
            cout<<"Enter your age:"<<endl;
            cin>>age;
            if(age<5)
            {
                throw age;
            }
            else
            {
                for(auto file_line : v)
                {
                    cout<<file_line<<endl;
                }
            }


        }

};
class teachers: public performers          //inheritance
{
   public:
       void displayt(string q)            //polymorphism    function overloading
       {
           cout<<"Qualification:"<<q<<endl;
           cout<<"Match your qualifications with the requirements below"<<endl;
       }
   void displayt()
    {
        ifstream fin;
        fin.open("Teachers.txt");
        string c;
        while (!fin.eof())
        {
            getline(fin,c);
            v.push_back(c);
        }
        fin.close();
        for(auto file_line : v)
        {
            cout<<file_line<<endl;
        }

    }
};
int main()
{

    ofstream fout;
    int choice;
    string q;
    performers p;
    learners<int> l;
    teachers t;
    do
    {
        cout<<"Do you want to "<<"\n"<<"1.Perform"s<<"\n"<<"2.Learn"<<"\n"<<"3.Teach"<<"\n"<<"4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                p.displayp();
                break;

            case 2:

                try
                {
                    l.displayl();
                }
                catch(int age)
                {
                    cout<<"Children less than the age of "<<age<<" are not recommended to learn an instrument"<<endl;
                }
                break;

            case 3:
                cout<<"Enter your music qualifications:"<<endl;
                getline(cin>>ws,q);
                t.displayt(q);
                t.displayt();
                break;

            case 4:
                return 0;

        }
    }while(1);

    return 0;
}
