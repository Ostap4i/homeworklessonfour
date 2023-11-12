
#include <iostream>
using namespace std;


class AbstractProductA {
public:
	virtual void display() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
	void display() {
		cout << "Concrete product A1" << endl;
	}
};

class ConcreteProductA2 : public AbstractProductA {
public:
	void display() {
		cout << "Concrete product A2" << endl;
	}

};


class AbstractProductB {
public:
	virtual void display() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
	void display() {
		cout << "Concrete product B1" << endl;
	}
};

class ConcreteProductB2 : public AbstractProductA {
public:
	void display() {
		cout << "Concrete product B2" << endl;
	}

};

class  AbstractFactory {
public:
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA* createProductA() override {
		return new ConcreteProductA1();
	}

	AbstractProductB* createProductB() override {
		return new ConcreteProductB1();
	}
};

class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA* createProductA() override {
		return new ConcreteProductA2();
	}

	AbstractProductB* createProductB()  {
		return new ConcreteProductB2();
	}
};





int main()
{
	AbstractFactory* factory1 = new ConcreteFactory1();
	AbstractProductA* productA1 = factory1->createProductA();
	AbstractProductB* productB1 = factory1->createProductB();

	productA1->display();
	productB1->display();

	delete factory1;
	delete productA1;
	delete productB1;

	// Використання фабрики 2
	AbstractFactory* factory2 = new ConcreteFactory2();
	AbstractProductA* productA2 = factory2->createProductA();
	AbstractProductB* productB2 = factory2->createProductB();

	productA2->display();
	productB2->display();

	delete factory2;
	delete productA2;
	delete productB2;

	return 0;
}

