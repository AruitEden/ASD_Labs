#pragma once
#include<string>
#include<iostream>

void interface(char, int(*)(int), int(*)(int), int(*)(std::string));

void PrintHelp();

#include"Interface.inl"