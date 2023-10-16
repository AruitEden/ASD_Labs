#include "Warrior.h"

const std::string& Warrior::getName() const
{
	return name;
}

void Warrior::setName(const std::string name)
{
	this->name = name;
}

int Warrior::getPower() const
{
	return power;
}

void Warrior::setPower(const int power)
{
	this->power = power;
}

Warrior::Warrior(std::string name, int power)
{
	setName(name);
	setPower(power);
}

std::ostream& operator<<(std::ostream& out, const Warrior &warrior)
{
	out << "Name: " << warrior.getName() << "\tPower: " << warrior.getPower() << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Warrior& warrior)
{
	getline(in, warrior.name, ',');
	in >> warrior.power;
	in.ignore(1);
	return in;
}

bool operator==(const Warrior& warrior1, const Warrior& warrior2)
{
	return (warrior1.getName() == warrior2.getName() && warrior1.getPower() == warrior2.getPower());
}

bool operator!=(const Warrior& warrior1, const Warrior& warrior2)
{
	return !(warrior1 == warrior2);
}

bool operator>(const Warrior& warrior1, const Warrior& warrior2)
{
	return warrior1.getPower() > warrior2.getPower();
}

bool operator>=(const Warrior& warrior1, const Warrior& warrior2)
{
	return warrior1.getPower() >= warrior2.getPower();
}

bool operator<(const Warrior& warrior1, const Warrior& warrior2)
{
	return warrior1.getPower() < warrior2.getPower();
}

bool operator<=(const Warrior& warrior1, const Warrior& warrior2)
{
	return warrior1.getPower() <= warrior2.getPower();
}
