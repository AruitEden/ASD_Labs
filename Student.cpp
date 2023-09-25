#include "Student.h"

const std::string& Student::GetGroup()const
{
	return group;
}

void Student::SetGroup(const std::string group)
{
	this->group = group;
}



const std::string& Student::GetName()const
{
	return name;
}

void Student::SetName(const std::string name)
{
	this->name = name;
}



int Student::GetGPA()const
{
	return gpa;
}

void Student::SetGPA(const int gpa)
{
	this->gpa = gpa;
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
	is.ignore(1);
	return is;
}


std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << "Group: " << student.group << "\tName: " << student.name << "\tGPA: " << student.gpa;
	return os;
}



