#include <ctime>
#include <cstdlib>
#include <iostream>
 
using std::cout;
 
/*ИЕРАРХИЯ КЛАССОВ*/
class Grand{
    int hold;
public:
    Grand(int h=0):hold(h){}
    virtual void Speak() const { cout << "I'm a grang class!\n";}
    virtual int Value() const { return hold; }
    virtual ~Grand(){}
 
};

class Superb: public Grand{
public:
    Superb(int h = 0):Grand(h){}
    void Speak()       const { cout << "I'm a superb class!!\n"; }
    virtual void Say() const{  cout << "I hold the superb value of " <<  Value() << '\n';    }
 
};

class Magnificent: public Superb{
    char ch;
public:
    Magnificent(int h = 0, char c = 'A'):Superb(h),ch(c){}
    void Speak() const { cout << "I'm a magnificent class!!!\n"; }
    void Say()   const { cout << "I hold the character ch " << ch << " and the integer " << Value() << '\n'; }
};
/*КОНЕЦ ИЕРАРХИИ КЛАССОВ*/
 
Grand* GetOne(); //прототип функции, возвращающей адрес объекта случайного типа
 
int main(){
    srand(std::time(0));
 
    Grand  *pg;     //В pg будет записываться адрес объекта случайного типа
    Superb *ps;     //ps будет использован для вызова метода Say
 
    for (auto i=0; i<5; i++){
        pg = GetOne();
        pg->Speak();
        if (pg != dynamic_cast<Superb *> (pg))
        {
            std::cout << "\n";
        }
        if (ps = dynamic_cast<Superb *>(pg))
        {
            ps->Say() ; //Проверка на успешность (безопасность) и выполнения метода Say
            cout << "\n";
        }
    }
}
 
/*генерация объекта случайного типа*/
Grand* GetOne(){
  Grand *p;
   switch (rand()%3){
    case 0: p = new Grand  (rand()  % 100);     break;
    case 1: p = new Superb (rand () % 100);  break;
    case 2: p = new Magnificent (rand() % 100, 'A' + rand() % 26); break;
   }
  return p; //возврат указателя на объект типа Grand
}
