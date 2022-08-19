
#include <iostream>
#include <string>


namespace SingeltonPattern
{
	class MySingelton
	{
	protected:
		MySingelton() : DataName("NAME"), x(0), y(0) { std::cout << "Hello from Constuctor MySingelton\n"; }
	private:
		static MySingelton* Data;
	private:
		std::string DataName;
		int x;
		int y;
	public:
		static MySingelton* Init()
		{
			if (Data == nullptr)
			{
				Data = new MySingelton();
			}
			return Data;
		}

		std::string& GetName()
		{
			return DataName;
		}

		int& Get_X()
		{
			return x;
		}
		
		int& Get_Y()
		{
			return y;
		}

		void SetName(const std::string& name)
		{
			DataName = name;
		}

		void Set_X(const int& x)
		{
			this->x = x;
		}

		void Set_Y(const int& y)
		{
			this->y = y;
		}
	};

	MySingelton* MySingelton::Data = nullptr;

}

int main() {

	SingeltonPattern::MySingelton * s1 = SingeltonPattern::MySingelton::Init();
	std::cout << "S1 object:\n";
	std::cout << "Name: " << s1->GetName() << std::endl;
	std::cout << "X: " << s1->Get_X() << std::endl;
	std::cout << "Y: " << s1->Get_Y() << std::endl;

	s1->SetName("Anton");
	s1->Set_Y(399);
	s1->Set_X(100);

	std::cout << "Name: " << s1->GetName() << std::endl;
	std::cout << "X: " << s1->Get_X() << std::endl;
	std::cout << "Y: " << s1->Get_Y() << std::endl;


	SingeltonPattern::MySingelton* s2 = SingeltonPattern::MySingelton::Init();
	std::cout << "S2 object:\n";
	std::cout << "Name: " << s2->GetName() << std::endl;
	std::cout << "X: " << s2->Get_X() << std::endl;
	std::cout << "Y: " << s2->Get_Y() << std::endl;

	s1->SetName("Bogdan");
	s1->Set_Y(14);
	s1->Set_X(3);

	std::cout << "Name: " << s2->GetName() << std::endl;
	std::cout << "X: " << s2->Get_X() << std::endl;
	std::cout << "Y: " << s2->Get_Y() << std::endl;
	return 0;
}