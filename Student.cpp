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



Student& Student::operator=(const Student& stud)
{
	if (this == &stud)
	{
		return *this;
	}

	SetGroup(stud.group);
	SetName(stud.name);
	SetGPA(stud.gpa);
}



std::istream& operator>>(std::istream& is, Student& student)
{
	getline(is, student.group, ',');
	is.ignore(1);
	getline(is, student.name, ',');
	is >> student.gpa;
	return is;
}


std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << "Group: " << student.group << "\tName: " << student.name << "\tGPA: " << student.gpa;
	return os;
}



