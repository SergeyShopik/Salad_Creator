#pragma once
#include"mainHeader.h"

class Salad
{
private:
    std::vector<std::shared_ptr<Base>> salad;
    double calories = 0;
public:
    Salad() = default;
    ~Salad() = default;
    double getCalories() const { return calories; }
    void createByCalories(double, Vegetables&);
    void print(std::ostream&);
    void findVegCalorie(double min, double max);
    void sortCalories();
};

//find vegetables in given calories range
void Salad::findVegCalorie(double min, double max)
{
    //std::sort(salad.begin(), salad.end(), [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getCalories () < b->getCalories(); });
    this->sortCalories();
    auto tempBegin = std::find_if(salad.begin(), salad.end(), 
        [min](std::shared_ptr<Base> a) { return a->getCalories() >= min; });
    auto tempEnd = std::find_if(salad.begin(), salad.end(), 
        [max](std::shared_ptr<Base> a) { return a->getCalories() >= max; });

    if (tempBegin == salad.end())
    {
        std::cerr << "No such vegetable\n";
        return;
    }
    else
    {
        cout << "Vegs in the calories range are: ";
        std::copy(tempBegin, tempEnd, std::ostream_iterator<std::shared_ptr<Base>>(std::cout, ", "));
    }
}

void Salad::createByCalories(double calSum, Vegetables& s)
{
    bool flag = true;
    Salad result;
    result.sortCalories();

    while (calSum > 0 && flag)
    {
        std::for_each(s.vegs.begin(), s.vegs.end(), [&calSum, &flag, &result, &s](std::shared_ptr<Base> vegs)
            {
                if (vegs->getCalories() <= calSum)
                {
                    calSum -= vegs->getCalories();
                    result.calories += vegs->getCalories();
                    result.salad.push_back(vegs);
                }
                else if (calSum < s.vegs.back()->getCalories())
                {
                    flag = false;
                }
            });
    }
    *this = result;
}

void Salad::print(std::ostream& out)
{
    std::copy(salad.begin(), salad.end(), std::ostream_iterator<std::shared_ptr<Base>>(out, "\n"));
}

void Salad::sortCalories()
{
    std::sort(salad.begin(), salad.end(),
        [](std::shared_ptr<Base> a, std::shared_ptr<Base> b) { return a->getCalories() < b->getCalories(); });
}
