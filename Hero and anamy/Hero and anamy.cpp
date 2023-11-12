
#include <iostream>
using namespace std;

class Hero {
public:
    virtual void display() = 0;
   
};

class Enemy {
public:
    virtual void display() = 0;

};

class GameFactory {
public:
    virtual Hero* createHero() = 0;
    virtual Enemy* createEnemy() = 0;


};

class Knight : public Hero {
public:
    void display() override {
        cout << "Knight" << endl;
    }
};

class Archer : public Hero {
public:
    void display() override {
        cout << "Archer " << endl;
    }
};

class Goblin : public Enemy {
public:
    void display() override {
        cout << "Goblin " << endl;
    }

};

class Witch : public Enemy {
public:
    void display() override {
        cout << "Whitch " << endl;
    }

};
class FantasyGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        return new Knight();
    }

    Enemy* createEnemy() override {
        return new Goblin(); 
    }
};


class SciFiGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        return new Archer(); 
    }

    Enemy* createEnemy() override {
        return new Witch(); 
    }
};


int main()
{
    GameFactory* fantasyFactory = new FantasyGameFactory();
    Hero* fantasyHero = fantasyFactory->createHero();
    Enemy* fantasyEnemy = fantasyFactory->createEnemy();

    std::cout << "Fantasy World:" << std::endl;
    fantasyHero->display();
    fantasyEnemy->display();

    delete fantasyHero;
    delete fantasyEnemy;
    delete fantasyFactory;

    // Використання науково-фантастичної фабрики
    GameFactory* sciFiFactory = new SciFiGameFactory();
    Hero* sciFiHero = sciFiFactory->createHero();
    Enemy* sciFiEnemy = sciFiFactory->createEnemy();

    std::cout << "\nSci-Fi World:" << std::endl;
    sciFiHero->display();
    sciFiEnemy->display();

    delete sciFiHero;
    delete sciFiEnemy;
    delete sciFiFactory;

    return 0;
}
