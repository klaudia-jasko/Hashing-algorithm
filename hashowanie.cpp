#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;


class HashTable1 {
private:
	string* t;
	int capacity;
	int ht_size;
public:
	HashTable1(int c);	//konstruktor tworz�cy pust� tablic� o pojemno�ci c
	int hashF(string s);	//funkcja haszuj�ca dla ci�gu s
	bool insert(string s);	//wstawienie ci�gu s, zwraca true je�li wstawienie nie wywo�a�o kolizji, fals je�li kolozja nast�pi�a
	int search(string s);	//wyszukanie ci�gu s, zwraca indeks lub -1 je�li 
	friend ostream& operator<<(ostream& out, HashTable1& ht);
}; 


int main()
{
	//#define DEBUG 1;
	HashTable1* haszowanie = new HashTable1(5);
	haszowanie->insert("ala");
	haszowanie->insert("ala");
	haszowanie->insert("ala");
	haszowanie->insert("ala");
	haszowanie->insert("ala");
	haszowanie->insert("ala");
	//if (1 ==  DEBUG) { cout << 5; };
}

HashTable1::HashTable1(int c)
{
	capacity = c;
	t = new string[c];
	for (int i = 0; i < c; i++)
	{
		t[i] = " ";
	}
	this->ht_size = 0;
}

int HashTable1::hashF(string s)
{
	int h = 0;
	for (int i = 0; i < s.length(); i++)
	{
		h += s[i] + i;
	}
	return h%capacity;
}

bool HashTable1::insert(string s)
{
	int index = hashF(s);
	if (t[index] == " ")
	{
		t[index] = s;
		ht_size++;
		return true;
	}
	else
	{
	for(int i=0; i<capacity; i++)
	{
			index++;
			if (t[index] == " ")
			{
				t[index] = s;
				ht_size++;
				break;
			}
			if (index == capacity)
			{
				index = 0;
			}
			
			if (ht_size == capacity)
			{
				cout << "tablica jest pelna";
				break;
			}
		}
	return false;
	}
	
}
