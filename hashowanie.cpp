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
	HashTable1(int c);	//konstruktor tworz¹cy pust¹ tablicê o pojemnoœci c
	int hashF(string s);	//funkcja haszuj¹ca dla ci¹gu s
	bool insert(string s);	//wstawienie ci¹gu s, zwraca true jeœli wstawienie nie wywo³a³o kolizji, fals jeœli kolozja nast¹pi³a
	int search(string s);	//wyszukanie ci¹gu s, zwraca indeks lub -1 jeœli 
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
