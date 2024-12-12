#include<iostream>
#include "Music.h"

int Music::lastid = 0;
Music::Music(string name, string text, int year):suffarr(text)
{
	Id = ++lastid;
	this->name = name;
	this->Pub_year = year;
	this->Text = text;

}
int Music::id()
{
	return Id;
}
string Music::getName()
{
	return name;
}

int Music::year()
{
	return this->Pub_year;
}

int Music::findword(string word)
{
	return suffarr.find(word);
}
int Music::countword(string word)
{
	return suffarr.occurance(word);
}
void Music::print()
{
	/// print arr
	std::cout << "id:" << Id << "  Name:" << name << "  Publish time:" << Pub_year<<endl;
	if (Text.size() < 20)
		std::cout << "Text:" << Text<<endl;
	else
		std::cout << "Text:" << Text.substr(0, 20)<<endl;


}
