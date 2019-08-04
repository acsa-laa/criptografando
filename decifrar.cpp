#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	int cifra;
	int constante = 0;
	int contador = 0;
	string str;
	char aux;
	char vazio = ' ';
	char *point;
	char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string arquivo = argv[1];
	ifstream obj(arquivo);
	if (obj.is_open() == 0)
	{
	  ofstream obj;
	  obj.open(arquivo);
	}

	while(!obj.eof()) {
		getline(obj, str);
		for (int l = 0; l < str.size(); l++)
		{
			for (int i = 0; i < 26; i++)
			{
				if (str[l] == letras[i])
				{	
					constante = 1;
					if (contador == 2 || contador == 5)
					{
						contador += 1;
					}
					else if(contador > 7)
					{
						contador = 0;
					}
					aux = (argv[2][contador]);
					point = &(aux);
					cifra = i - atoi(point);
					if (cifra < 0)
					{
						cifra = cifra + 26;
					}
					if (cifra > 26)
					{
						cifra = cifra - 26;
					}

					cout << letras[cifra];
				}
			}
			if (constante != 1)
			{
				cout << str[l];
				contador--;
			}
		constante = 0;
		contador++;
		}
			
		
	}

	
	return 0;
}