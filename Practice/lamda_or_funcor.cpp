#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Person{
    Person():lastName("noname"),firstName(""),age(0),job_id(0),position_id(0){}
    Person(const string& _lastName, const string& _firstName, int _age, int _job_id, int _position_id)
        :lastName(_lastName),
          firstName(_firstName),
          age(_age),
          job_id(_job_id),
          position_id(_position_id)
    {}
    string lastName;
    string firstName;
    int age;
    int job_id;
    int position_id;
};

struct Job{
    Job():name("invalid job"),id(-1){}
    Job(const string& _name, int _id):name(_name),id(_id){}
    string name;
    int id;

};

struct Position{
    Position():name("invalid position"),id(-1){}
    Position(const string& _name, int _id):name(_name),id(_id){}
    string name;
    int id;
};

bool compareByName(const Person& person1, const Person& person2){
    if(person1.lastName==person2.lastName){
        return person1.firstName<person2.firstName;
    }
    return person1.lastName<person2.lastName;
}

bool compareByAge(const Person & p1, const Person & p2)
{
    return p1.age > p2.age;
}

class PersonsList{
public:

    void addPerson(const Person& person){
        persons.push_back(person);
    }
    void addPosition(const Position& position){
        positionsMap[position.id]=position;
    }
    void addJob(const Job& job){
        jobsMap[job.id]=job;
    }

    void print(){
        for(int i=0;i<(int)persons.size();i++){

            Person& person=persons[i];

            Job& job=jobsMap[person.job_id];
            Position& position=positionsMap[person.position_id];

            cout << setfill (' ') << std::setw (15) << person.lastName;
            cout << setfill (' ') << std::setw (10) << person.firstName;
            cout << setfill (' ') << std::setw (5) << person.age << " years";
            cout << setfill (' ') << std::setw (20) << job.name;
            cout << setfill (' ') << std::setw (20) << position.name;
            cout << endl;
        }
    }

    
    
    void sortByName(){
        stable_sort(persons.begin(),persons.end(),compareByName);
    }

    void sortByAge(){
        // ================================================= TODO
        // programmer also want to change something else, not only this fucntion
        stable_sort(persons.begin(), persons.end(), compareByAge);
    }

    void sortByJob(){
        // ================================================= TODO
        auto JM = jobsMap;
        stable_sort(persons.begin(), persons.end(), [&JM](const Person & p1, const Person & p2){
            return JM[p1.job_id].name < JM[p2.job_id].name;
        });
    }

    
private:
    std::vector<Person> persons;

    std::map<int,Job> jobsMap;
    std::map<int,Position> positionsMap;
};

int main()
{
    PersonsList list;

    Job google("Google",1);
    Job microsoft("Microsoft",2);
    Job hp("Aewlett-Packard",3);

    list.addJob(google);
    list.addJob(microsoft);
    list.addJob(hp);

    Position junior("Junior developer",1);
    Position senior("Senior developer",2);
    Position manager("Manager",3);

    list.addPosition(junior);
    list.addPosition(senior);
    list.addPosition(manager);

    list.addPerson(Person("Ivanov","Ivan",21,google.id,junior.id));
    list.addPerson(Person("Sidorov","Nikolay",28,google.id,senior.id));
    list.addPerson(Person("Ivanov","Maxim",28,google.id,manager.id));

    list.addPerson(Person("Volkova","Katerina",22,microsoft.id,junior.id));
    list.addPerson(Person("Demidov","Vitaly",35,microsoft.id,manager.id));

    list.addPerson(Person("Bodrov","Boris",40,hp.id,senior.id));

    list.sortByName();
    cout<<"Sorted by name:"<<endl;
    list.print();

    cout<<endl;

    list.sortByAge();
    cout<<"Sorted by age:"<<endl;
    list.print();

    cout<<endl;

    list.sortByJob();
    cout<<"Sorted by job:"<<endl;
    list.print();

    return 0;
}