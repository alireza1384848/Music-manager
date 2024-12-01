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
void Music::print()
{
	/// print arr
	std::cout << "id:" << Id << "  Name:" << name << "  Publish time:" << Pub_year<<endl;
	if (Text.size() < 20)
		std::cout << "Text:" << Text<<endl;
	else
		std::cout << "Text:" << Text.substr(0, 20)<<endl;


}
