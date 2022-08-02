#include <iostream>
#include <string>
enum class proffesion
    {
        worker,
        manager,
        director
    };
class Emploe
{
private:
    std::string name;
    proffesion prof;
public:
    Emploe() {}
    Emploe(const std::string & s, proffesion pf) : name(s), prof(pf)  {}
    bool operator<(const Emploe & e)
    {
        return (this->prof < e.prof);
    }
    void Show() const
    {
        std::cout << "Name: " << name << ", ";
        if(prof == proffesion::worker)
        {
            std::cout << "Worker!";
        }
        else if (prof == proffesion::manager)
        {
             std::cout << "Manager!";
        }
        else
        {
            std::cout << "Director!";
        }
    }
};

const int SIZE = 10;
void BubbleSort(Emploe * arr, int size);
void Show(int * arr, int size);
int main(){
   //int arr[SIZE] = {3, 5, 2, 1, 13, 12, 2, 1, 1, 20};   
    //Show(arr, SIZE);
    //Emploe w1("Harry", proffesion::manager);
    //w1.Show();
    //Emploe W[4] = { ("Harry", proffesion::manager), ("Bob", proffesion::director), ("Tanos", proffesion::manager), ("Anton", proffesion::worker)};
    Emploe W[4];
    W[0] = Emploe("Harry", proffesion::manager);
    W[1] = Emploe("Bob", proffesion::director);
    W[2] = Emploe("Tanos", proffesion::manager);
    W[3] = Emploe("Anton", proffesion::worker);
    BubbleSort(W, 4);
    for(int i = 0; i < 4; i++)
    {
        W[i].Show();
        std::cout << std::endl;
    }
    return 0;
}

void BubbleSort(Emploe * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > i; j--)
        {
            if(arr[j] < arr[j - 1])
               {
                   Emploe temp = arr[j];
                   arr[j] = arr[j - 1];
                   arr[j - 1] = temp;
                   // or swap
               }
        }
    }
}
