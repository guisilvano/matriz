#include<iostream>

using namespace std;

int somaIntervalo (int n1, int n2, int soma)
{

	while (n1 < n2){
		
		soma = n1+n2;

		return somaIntervalo (n1, n2, soma);
	}


}

int main (int argc, char *argv[])
{

	int num1, num2;
	int soma;

	cin >> num1 >> num2; 

	soma = somaIntervalo (num1, num2, 0);

	cout << "\n" << soma;

	return 0;

}
