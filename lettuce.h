#pragma once
#include"mainHeader.h"

class Lettuce : public Base
{
public:
	Lettuce() = default;
	~Lettuce() = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> type >> humidity;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << " Type: " << type << " Humidity: " << humidity;
		return out;
	}

private:
	string type;
	double humidity;
};