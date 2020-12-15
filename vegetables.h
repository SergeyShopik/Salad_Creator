#pragma once
#include "mainHeader.h"

std::shared_ptr<Base> ptr(char);

class Vegetables
{
public:
    std::vector<std::shared_ptr<Base>> vegs;

    Vegetables() = default;
    ~Vegetables() = default;

    void read(std::istream&);
    void print(std::ostream&);
    void sortCalories();
    void sortPrice();
    void sortCook();

    void findVegCalorie(double min, double max);

};

std::shared_ptr<Base> ptr(char choise)
{
    switch (choise)
    {
    case 'c':
    {
        return std::make_shared<Cucumber>();
        break;
    }
    case 't':
    {
        return std::make_shared<Tomato>();
        break;
    }
    case 'l':
    {
        return std::make_shared<Lettuce>();
        break;
    }
    default:
    {
        return nullptr;
    }
    }
}

void Vegetables::read(std::istream& file)
{
    while (!file.eof())
    {
        char symbol;
        file >> symbol;
        vegs.push_back(ptr(symbol));
        std::string str;
        getline(file, str);
        std::istringstream ss(str);
        vegs.back()->read(ss);
    }
}

void Vegetables::print(std::ostream& out)
{
    std::copy(vegs.begin(), vegs.end(), std::ostream_iterator<std::shared_ptr<Base>>(out, "\n"));
}

void Vegetables::sortCalories()
{
    std::sort(vegs.begin(), vegs.end(), [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getCalories() > b->getCalories(); });
}

void Vegetables::sortPrice()
{
    std::sort(vegs.begin(), vegs.end(), [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getPrice() > b->getPrice(); });
}

void Vegetables::sortCook()
{
    std::sort(vegs.begin(), vegs.end(), [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getCook() > b->getCook(); });
}

//----------------------------------------------------------------------------------------------
void Vegetables::findVegCalorie(double min, double max)
{
    std::sort(vegs.begin(), vegs.end(), [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getCalories () < b->getCalories(); });
    //this->sortCalories();
    auto tempBegin = std::find_if(vegs.begin(), vegs.end(),
        [min](std::shared_ptr<Base> a) { return a->getCalories() >= min; });
    auto tempEnd = std::find_if(vegs.begin(), vegs.end(),
        [max](std::shared_ptr<Base> a) { return a->getCalories() >= max; });

    if (tempBegin == vegs.end())
    {
        std::cerr << "No such vegetable\n";
        return;
    }
    else
    {
        cout << "Vegs in the calories range are:\n";
        std::copy(tempBegin, tempEnd, std::ostream_iterator<std::shared_ptr<Base>>(cout, ", "));
    }
}