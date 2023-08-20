#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
struct Person
{
	string m_Name;//ÐÕÃû
	int m_Sex;//1ÄÐ 2Å®
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void addPerson(Addressbooks* abs);
void showPerson(Addressbooks* abs);
void deletePerson(Addressbooks* abs);
void searchPerson(Addressbooks* abs);
void modifyPerson(Addressbooks* abs);
void cleanPerson(Addressbooks* abs);