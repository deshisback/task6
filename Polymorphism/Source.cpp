//Реализовать программу демонстрирующую предметную область "Пиццерия"
//
//Заказ - это список из выбранных пользователем пицц.
//
//Пицца - это блюдо, которое выбирает пользователь.Пицца обладает именем(текст), описанием(текст), 
//размером(один из вариантов 25, 30, 35, 40, который выбирает пользователь), ценой(зависит от размера выбранной пиццы и ингредиентов).
//Пользователь может подсолить любую пиццу N - раз или добавить сыра M - раз - это увеличивает цену в зависимости от вида и размера пиццы(формулу придумать на ваше усмотрение)
//
//Заказ - формируется пользователем через консоль, возможность добавить пиццу, распечатать заказ в консоль.
//
//Печать заказа - вывод всего списка выбранных пользователем пицц, с указанием названия, описания, N - соли и M - сыра, размера пиццы и стоимости пиццы с учётом всех параметров
//
//В конце распечатанного заказа вывести итоговую сумму за заказ
//
//(В рамках выполнения задания необходимо продемонстрировать умение использовать Ad - hoc полиморфизм : overloading / overriding)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza
{

public:

	virtual void PrintName() = 0;

	virtual void PrintInfo() = 0;

	virtual void SetSize() = 0;

	virtual double GetCost() = 0;

	virtual void AddCheese(int _CheeseVal) = 0;

	virtual void AddSalt(int _SaltVal) = 0;

	virtual void FinalPrice() = 0;

};

class Pepperoni : public Pizza
{

private:

	string NamePizza;
	string InfoPizza;
	int SizePizza;
	double Cost;
	int SaltVal;
	int CheeseVal;

public:
	
	Pepperoni()
	{
		NamePizza = "Pepperoni";
		InfoPizza = "The classic flavor of smoked slightly spicy sausage and delicious sauce. The perfect choice";
		SizePizza = 0;
		Cost = 0;
		SaltVal = 0;
		CheeseVal = 0;
	}

	Pepperoni(int _CheeseVal, int _SaltVal)
	{
		NamePizza = "Pepperoni";
		InfoPizza = "The classic flavor of smoked slightly spicy sausage and delicious sauce. The perfect choice";
		SizePizza = 0;
		Cost = 0;
		SaltVal = _SaltVal;
		CheeseVal = _CheeseVal;
	}

	void PrintName() override
	{
		cout << "Pizza name: " << NamePizza << endl;
	}

	void PrintInfo() override
	{
		cout << "Info about pizza: "<< endl;
		cout << "Pizza: " << NamePizza << endl;
		cout << "Info: " << InfoPizza << endl;
		cout << "Size: " << SizePizza << endl;
		cout << "Cost: " << Cost << endl;
		cout << "Salt count: " << SaltVal << endl;
		cout << "Cheese count: " << CheeseVal << endl;
	}

	void SetSize() override
	{
		cout << "Choose the size of the pizza" << endl;
		cout << "1. 25" << endl;
		cout << "2. 30" << endl;
		cout << "3. 35" << endl;
		cout << "4. 40" << endl;
		int size;
		bool isRun = true;
		while (isRun)
		{
			cin >> size;

			switch (size)
			{
			case 1:
				SizePizza = 25;
				isRun = false;
				break;
			case 2:
				SizePizza = 30;
				isRun = false;
				break;
			case 3:
				SizePizza = 35;
				isRun = false;
				break;
			case 4:
				SizePizza = 40;
				isRun = false;
				break;
			default:
				cout << "Choose between 1 and 4" << endl;
				break;
			}
		}
	}

	double GetCost() override
	{
		return Cost;
	}

	void AddCheese(int _CheeseVal) override
	{
		CheeseVal = _CheeseVal;
	}

	void AddSalt(int _SaltVal)
	{
		SaltVal = _SaltVal;
	}

	void FinalPrice() override
	{
		switch (SizePizza)
		{
		case 25:
			Cost = 400 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 30:
			Cost = 480 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 35:
			Cost = 600 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 40:
			Cost = 750 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		}
	}

};

class Mozzarella : public Pizza
{

private:

	string NamePizza;
	string InfoPizza;
	int SizePizza;
	double Cost;
	int SaltVal;
	int CheeseVal;

public:

	Mozzarella()
	{
		NamePizza = "Mozzarella";
		InfoPizza = "The pulled melted mozzarella cheese gives an incredible look to the pizza, but the flavor will be behind the parmesan";
		SizePizza = 0;
		SaltVal = 0;
		CheeseVal = 0;
	}

	Mozzarella(int _CheeseVal, int _SaltVal)
	{
		NamePizza = "Mozzarella";
		InfoPizza = "The pulled melted mozzarella cheese gives an incredible look to the pizza, but the flavor will be behind the parmesan";
		SizePizza = 0;
		SaltVal = _SaltVal;
		CheeseVal = _CheeseVal;
	}

	void PrintName() override
	{
		cout << "Pizza name: " << NamePizza << endl;
	}

	void PrintInfo() override
	{
		cout << "Info about pizza: " << endl;
		cout << "Pizza: " << NamePizza << endl;
		cout << "Info: " << InfoPizza << endl;
		cout << "Size: " << SizePizza << endl;
		cout << "Cost: " << Cost << endl;
		cout << "Salt count: " << SaltVal << endl;
		cout << "Cheese count: " << CheeseVal << endl;
	}

	void SetSize() override
	{
		cout << "Choose the size of the pizza" << endl;
		cout << "1. 25" << endl;
		cout << "2. 30" << endl;
		cout << "3. 35" << endl;
		cout << "4. 40" << endl;
		int size;
		bool isRun = true;
		while (isRun)
		{
			cin >> size;

			switch (size)
			{
			case 1:
				SizePizza = 25;
				isRun = false;
				break;
			case 2:
				SizePizza = 30;
				isRun = false;
				break;
			case 3:
				SizePizza = 35;
				isRun = false;
				break;
			case 4:
				SizePizza = 40;
				isRun = false;
				break;
			default:
				cout << "Choose between 1 and 4" << endl;
				break;
			}
		}
	}

	double GetCost() override
	{
		return Cost;
	}

	void AddCheese(int _CheeseVal) override
	{
		CheeseVal = _CheeseVal;
	}

	void AddSalt(int _SaltVal)
	{
		SaltVal = _SaltVal;
	}

	void FinalPrice() override
	{
		switch (SizePizza)
		{
		case 25:
			Cost = 350 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 30:
			Cost = 440 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 35:
			Cost = 580 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 40:
			Cost = 700 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		}
	}

};

class DoubleChick : public Pizza
{

private:

	string NamePizza;
	string InfoPizza;
	int SizePizza;
	double Cost;
	int SaltVal;
	int CheeseVal;

public:

	DoubleChick()
	{
		NamePizza = "Double Chick";
		InfoPizza = "Delicate flavor of chicken under melted cheese with crispy sides";
		SizePizza = 0;
		SaltVal = 0;
		CheeseVal = 0;
	}

	DoubleChick(int _CheeseVal, int _SaltVal)
	{
		NamePizza = "DoubleChick";
		InfoPizza = "Delicate flavor of chicken under melted cheese with crispy sides";
		SizePizza = 0;
		SaltVal = _SaltVal;
		CheeseVal = _CheeseVal;
	}

	void PrintName() override
	{
		cout << "Pizza name: " << NamePizza << endl;
	}

	void PrintInfo() override
	{
		cout << "Info about pizza: " << endl;
		cout << "Pizza: " << NamePizza << endl;
		cout << "Info: " << InfoPizza << endl;
		cout << "Size: " << SizePizza << endl;
		cout << "Cost: " << Cost << endl;
		cout << "Salt count: " << SaltVal << endl;
		cout << "Cheese count: " << CheeseVal << endl;
	}

	void SetSize() override
	{
		cout << "Choose the size of the pizza" << endl;
		cout << "1. 25" << endl;
		cout << "2. 30" << endl;
		cout << "3. 35" << endl;
		cout << "4. 40" << endl;
		int size;
		bool isRun = true;
		while (isRun)
		{
			cin >> size;

			switch (size)
			{
			case 1:
				SizePizza = 25;
				isRun = false;
				break;
			case 2:
				SizePizza = 30;
				isRun = false;
				break;
			case 3:
				SizePizza = 35;
				isRun = false;
				break;
			case 4:
				SizePizza = 40;
				isRun = false;
				break;
			default:
				cout << "Choose between 1 and 4" << endl;
				break;
			}
		}
	}

	double GetCost() override
	{
		return Cost;
	}

	void AddCheese(int _CheeseVal) override
	{
		CheeseVal = _CheeseVal;
	}

	void AddSalt(int _SaltVal)
	{
		SaltVal = _SaltVal;
	}

	void FinalPrice() override
	{
		switch (SizePizza)
		{
		case 25:
			Cost = 450 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 30:
			Cost = 560 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 35:
			Cost = 680 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		case 40:
			Cost = 800 + SaltVal * 0.5 + CheeseVal * 10;
			break;
		}
	}

};

class PizzaMenu
{

private:

	vector<Pizza*> OrderList;

public:

	~PizzaMenu()
	{
		while (!OrderList.empty())
		{
			OrderList.pop_back();
		}
	}

	void Menu()
	{
		double IsRun = true;
		int PizzaSelector = 0;
		Pizza* pizza = nullptr;
		cout << "Choose your favorite pizza:" << endl;
		while (IsRun)
		{
			cout << "1. Pepperoni" << endl;
			cout << "2. Mozzarella" << endl;
			cout << "3. DoubleChick" << endl;
			cout << "4. Print order" << endl;
			cout << "5. Place an order" << endl;
			cin >> PizzaSelector;
			switch (PizzaSelector)
			{
			case 1:
				pizza = new Pepperoni;
				AddPizzaInOrder(pizza);
				break;
			case 2:
				pizza = new Mozzarella;
				AddPizzaInOrder(pizza);
				break;
			case 3:
				pizza = new DoubleChick;
				AddPizzaInOrder(pizza);
				break;
			case 4:
				PrintOrder();
				break;
			case 5:
				PrintOrder();
				IsRun = false;
				break;
			default:
				cout << "Wrong input! Please try again";
				break;
			}
		}
	}

	void AddPizzaInOrder(Pizza* pizza)
	{
		pizza->SetSize();
		cout << "Add cheese?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		int selector = 0;
		int count = 0;
		cin >> selector;
		
		switch (selector)
		{
		case 1:
			cout << "How many?";
			cin >> count;
			pizza->AddCheese(count);
			break;
		default:
			break;
		}

		cout << "Add salt?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> selector;

		switch (selector)
		{
		case 1:
			cout << "How many?";
			cin >> count;
			pizza->AddSalt(count);
			break;
		default:
			break;
		}

		pizza->FinalPrice();
		OrderList.push_back(pizza);
		cout << "Add one more?" << endl;
		cout << endl;
		return;
	}

	void PrintOrder()
	{
		if (OrderList.size() == 0)
		{
			cout << "You haven't added any pizzas yet";
		}

		int money = 0;

		for (int i = 0; i < OrderList.size(); i++)
		{
			OrderList[i]->PrintInfo();
			money += OrderList[i]->GetCost();
		}
		cout << endl;
		cout << "Final order price: " << money << endl;
		return;
	}
};

int main()
{
	PizzaMenu menu;
	menu.Menu();

}