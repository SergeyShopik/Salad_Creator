#pragma once
#include"mainHeader.h"

class Tomato : public Base
{
public:
	Tomato() = default;
	~Tomato() override = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> color >> cherry;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << " Color: " << color << " Cherry: " << cherry;
		return out;
	}

private:
	string color;
	bool cherry;
};