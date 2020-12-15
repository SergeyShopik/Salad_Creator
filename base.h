#pragma once
#include"mainHeader.h"

class Base
{
public:
	Base() = default;
	virtual ~Base() = default;

	void setOrigin(string n) { origin = n; }
	void setCalories(double c) { calories = c; }
	void setCook(bool cook) { cookingNeeded = cook; }
	void setPrice(double p) { price = p; }

	string getOrigin() { return origin; }
	double getCalories() { return calories; }
	bool getCook() { return cookingNeeded; }
	double getPrice() { return price; }

	virtual std::istream& read(std::istream& in)
	{
		in >> origin >> calories >> cookingNeeded >> price;
		return in;
	}
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Origin: " << origin << " Calories: " << calories << " Cooking needed: " << cookingNeeded
			<< " Price: " << price;
		return out;
	}

private:
	string origin;
	double calories;
	bool cookingNeeded;
	double price;
};

std::ostream& operator<<(std::ostream& out, std::shared_ptr<Base> s1)
{
	s1->print(out);
	return out;
}