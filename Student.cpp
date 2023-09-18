#include "Student.h"

std::string Student::GetGroup()
{
	return group;
}

void Student::SetGroup(std::string group)
{
	this->group = group;
}



std::string Student::GetName()
{
	return name;
}

void Student::SetName(std::string name)
{
	this->name = name;
}



int Student::GetGPA()
{
	return gpa;
}

void Student::SetGPA(int gpa)
{
	this->gpa = gpa;
}




Student::Student()
{
	group = "";
	name = "";
	gpa = 0;
}

Student::Student(std::string group, std::string name, int gpa)
{
	this->group = group;
	this->name = name;
	this->gpa = gpa;
}


