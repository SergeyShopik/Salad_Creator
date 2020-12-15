#include"mainHeader.h"

int main()
{
    std::ifstream file("vegetables.txt");

    if (!file)
    {
        std::cerr << "Cannot open file.\n";
        exit(0);
    }

    Vegetables v;
    v.read(file);
    file.close();
    bool menu = true;

    while (menu)
    {
        Salad s;
        int choise;
        cout << "1. Create salad of given calorie rate.\n"
            << "2. Find vegetables within calorie rate.\n"
            << "0. Exit program.\n";
        std::cin >> choise;

        switch (choise)
        {
        case 0:
            menu = false;
            continue;
        case 1:
        {
            double calories;
            std::cout << "\nEnter calorie rate: ";
            std::cin >> calories;
            s.createByCalories(calories, v);
            break;
        }
        case 2:
        {
            cout << "Enter calorie range (min and max):\n";
            double min, max;
            cin >> min >> max;
            v.findVegCalorie(min, max);
        }
        default:
            std::cerr << "Wrong option.\n";
            continue;
        }

        if (s.getCalories() == 0)
        {
            std::cerr << "No available vegetables of given calorie range.\n";
            continue;
        }
        else
        {
            std::cout << "Salad contents are:\n";
            s.print(cout);
        }

        bool flag = true;

        while (flag)
        {
            int choise;
            std::cout << "\nWhat to do with the salad?\n0. Exit\n1. Sort by calories.";
            std::cin >> choise;

            switch (choise)
            {
            case 0:
                flag = false;
                continue;
            case 1:
                s.sortCalories();
                s.print(cout);
                break;
           
            default:
                std::cerr << "Wrong option.\n";
                break;
            }
        }
    }

    system("pause");
    return 0;
}
