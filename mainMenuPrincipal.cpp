/*------------------------------------------------------------------------------|
|      			Sistema Virtual de um Supermercado			|
|										|
|    Desenvolvedor: André Escarião, Graduando em engenharia Elétrica - UFCG	|
|	 									|
|    Compilador: Falcon C++		  					|			      						    								|
|				   						|
|------------------------------------------------------------------------------*/

#include <fstream>
#include <locale>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

#include "Cadastro.cpp"
#include "Estoque.cpp"
#include "Sistema.cpp"

//CHAVE DE ACESSO DO GERENTE
#define chave "gerente"

//Objetos globais para acessar no menu
Cadastro pessoa;
Estoque estoque;
Sistema sistema;

void bemvindo(Cadastro, Sistema, Estoque);  		  //Função de abertura do programa
void menuPrincipal(Cadastro, Sistema, Estoque);      //Função menu principal
void cadastro(Cadastro, Sistema, Estoque);           //função para cadastro
void menuCliente(Cadastro, Sistema, Estoque);	 //Função menu Cliente
void menuGerente(Cadastro, Sistema, Estoque);			 //Função menu gerente
void sair();                      	 //Função para saida do programa


//Função principal
int main()
{
	setlocale(LC_ALL, "");
	bemvindo(pessoa, sistema, estoque);

	return 0;
}


//ABERTURA DO PROGRAMA
void bemvindo(Cadastro, Sistema, Estoque)
{
	cout << "************************************************************************************************************************";
	cout << "*                                                                                                                      *";
	cout << "*                                                                                                                      *";
	cout << "*                                          Sistema Virtual de um Supermercado                                          *";
	cout << "*                                                                                                                      *";
	cout << "*                                                                                                                      *";
	cout << "************************************************************************************************************************" << endl;
	system("pause");
	menuPrincipal(pessoa, sistema, estoque);
}

//MENU PRINCIPAL
void menuPrincipal(Cadastro, Sistema, Estoque)
{

	int op;
	string CPF, cpf;

	system("cls");

	cout << "Menu Principal: " << endl;
	cout << "{1} -> Entrar " << endl;
	cout << "{2} -> Cadastro " << endl;
	cout << "{3} -> Sair " << endl;
	cin >> op;

	switch(op)
	{
		//Opção 01: Fazer login no sistema
	case 1:
	{

		int num;

		system("cls");

		cout << "Login: " << endl;
		cout << "{1} -> Cliente" << endl;
		cout << "{2} -> Gerente" << endl;
		cin >> num;

		system("cls");

		//Loga como Cliente
		if(num == 1)
		{

			int ch;
			string usu;

			cout << "Menu de Login: " << endl;
			cout << "Digite o nome de Usuário: " << endl;
			cin >> usu;
			cout << "Digite a Chave de acesso:" << endl;
			cin >> ch;

			//Verifica se o login está no sistema
			if(pessoa.verifica(ch) == usu)
			{
				//Abre menu do cliente
				menuCliente(pessoa, sistema, estoque);

			}
			else
			{
				system("cls");
				cout << "Login não cadastrado!" << endl;
				system("pause");

				//Volta para menu principal
				menuPrincipal(pessoa, sistema, estoque);
			}




		}




		//Loga como Gerente
		else if(num == 2)
		{
			string chaveGerente;


			cout << "Digite a chave de acesso: ";
			cin >> chaveGerente;

			try
			{

				//Verifica chave do gerente
				if(chave == chaveGerente)
				{
					//Abre menu do gerente
					menuGerente(pessoa, sistema, estoque);

				}
				else
				{

					throw 1;

				}

			}
			catch (int erro)
			{

				if(erro == 1)
				{
					system("cls");
					cout << "Chave de acesso incorreta!" << endl << endl;
					system("pause");

					//Volta para menu principal
					menuPrincipal(pessoa, sistema, estoque);

				}

			}
		}
		break;
	}
	//Opção 02: Fazer Cadastro no sistema
	case 2:
	{
		system("cls");

		//Chama menu de cadastro
		cadastro(pessoa, sistema, estoque);

		break;
	}
	case 3:
	{
		system("cls");
		//Finaliza o programa
		sair();
		break;
	}
	default:
	{
		system("cls");
		printf("Opcao Invalida");
		system("pause");
		//Volta para menu principal
		menuPrincipal(pessoa, sistema, estoque);
	}
	}


}


//Menu para classe Cadastro
void cadastro(Cadastro, Sistema, Estoque)
{
	//Manipulação de arquivo
	ofstream arquivoS;
	arquivoS.open("Cadastro.txt", ios::app | ios::app);

	//Parâmetros para cadastro
	string cpf, nome, cep, rua, bairro, complemento, usuario;
	int chaveCliente, numero;

	//Recebe os dados da pessoa
	cout << "Preencha os dados abaixo: " << endl << endl;
	cout << "Usuário: " << endl;
	arquivoS << "Usuário: ";
	cin >> usuario;
	cout << "Chave de Acesso(3 dígitos): " << endl;
	cin >> chaveCliente;


	try
	{

		if(chaveCliente <100 || chaveCliente >=1000)
		{

			throw 1;


		}
		else
		{
			arquivoS << usuario << endl;
			arquivoS << chaveCliente << endl;

			cout << "CPF: " << endl;
			cin >> cpf;
			arquivoS << cpf << endl;
			cout << "Nome: " << endl;
			cin.ignore();
			getline(cin, nome);
			arquivoS << nome << endl;
			cout << "CEP: " << endl;
			cin >> cep;
			arquivoS << cep << endl;
			cout << "Rua: " << endl;
			cin.ignore();
			getline(cin, rua);
			arquivoS << rua << endl;
			cout << "Bairro: " << endl;
			cin.ignore();
			getline(cin, bairro);
			arquivoS << bairro << endl;
			cout << "Número: " << endl;
			cin >> numero;
			arquivoS << numero << endl;
			cout << "Complemento: " << endl;
			cin.ignore();
			getline(cin, complemento);
			arquivoS << complemento << endl;

			//Cadastra a chave da pessoa

			pessoa.setChaveCliente(chaveCliente);

			//Cadastra os dados da pessoa

			pessoa.cadastrar(cpf, nome, cep, rua, bairro, numero, complemento, usuario);


			arquivoS.close();

			system("pause");
			system("cls");

			//Imprime os dados da pessoa
			pessoa.imprime(chaveCliente);

			system("pause");
			system("cls");

			//Retorna ao menu principal
			menuPrincipal(pessoa, sistema, estoque);
		}
	}
	catch(int erro)
	{

		if(erro == 1)
		{



			system("cls");

			cout << "             Senha Ivalida!   " << endl << endl
				 << "Cadastre uma senha com 3 dígitos "
				 << "a senha não pode iniciar com 0" << endl << endl;

			system("pause");
			system("cls");

			//Retorna ao menu principal
			menuPrincipal(pessoa, sistema, estoque);
		}

	}



}



//Menu do cliente (Classe Controle de vendas)
void menuCliente(Cadastro, Sistema, Estoque)
{
	system("cls");

	int op;
	system("cls");
	cout << endl << " ---SUPERMERCADO ONLINE---: " << endl;
	cout << endl << "{1} -> Imprimir Lista de produtos" << endl;
	cout << endl << "{2} -> Realizar Compra" << endl;
	cout << endl << "{3} -> Voltar" << endl;
	cin >> op;

	switch(op)
	{
		//Opção 01: Exibe Lista de produtos em estoque (CLIENTE)
	case 1:
	{
		system("cls");

		//Método imprime
		sistema.imprimeListaProdutos(estoque);

		system("pause");
		menuCliente(pessoa, sistema, estoque);
		break;
	}
	//Opção 02: Cadastra nova Venda (CLIENTE)
	case 2:
	{

		system("cls");

		char con;
		int cod, quant;


		do
		{

			cout << "Adicionar ao carrinho..." << endl;
			cout << "Código: " << endl;
			cin >> cod;
			cout << "Quantidade: " << endl;
			cin >> quant;

			//Altera a quantidade em estoque
			estoque.setQuantidade(cod, quant);

			//Adicionar a nota fiscal
			sistema.gerarNota(estoque, cod, quant);

			cout << endl << "Adicionar outro produto ao carrinho:(s/n)?" << endl;
			cin >> con;
			system("cls");

		}
		while(con != 'n');

		cout << "Finalizando compra... " << endl << endl;

		//Imprime nota fiscal
		sistema.imprimeNota();

		system("pause");
		menuCliente(pessoa, sistema, estoque);
		break;

	}
	//Opção 05: Voltar
	case 3:
	{
		system("cls");
		system("pause");
		menuPrincipal(pessoa, sistema, estoque);
		break;
	}
	default:
	{
		system("cls");
		cout << "Opcao Invalida";
		system("pause");
		menuCliente(pessoa, sistema, estoque);
	}
	}


}



void menuGerente(Cadastro, Sistema, Estoque)
{

	system("cls");
	int op;

	cout << endl << "Controle de produtos: " << endl;
	cout << endl << "{1} -> Cadastro de produtos" << endl;
	cout << endl << "{2} -> Listar Produtos" << endl;
	cout << endl << "{3} -> Voltar" << endl;
	cin >> op;

	switch(op)
	{
		//Opção 1: Cadastro de produto
	case 1:
	{

		system("cls");

		char cond;
		do
		{

			string nome;
			int codigo, quantidade;
			float valor;


			cout << "Informe o codigo do produto: " << endl;
			cin >> codigo;


			cout << "Informe o nome do produto: " << endl;
			cin >> nome;
			cout << "Informe o valor do produto: " << endl;
			cin >> valor;
			cout << "Informe a quantidade:" << endl;
			cin >> quantidade;

			//Informa o código do produto
			estoque.setCodigo(codigo);
			//Cadastra os dados do produto
			estoque.setCadastrar(nome, valor, quantidade);

			cout << endl << "Deseja cadastrar outro produto:(s/n)?";
			cin >> cond;

		}

		while(cond != 'n');

		menuGerente(pessoa, sistema, estoque);

		break;

	}
	//Opção 02: Exibe a lista de Produtos
	case 2:
	{
		system("cls");

		//Método imprime
		estoque.imprime();

		system("pause");
		menuGerente(pessoa, sistema, estoque);
		break;
	}
	//Opção 03: Voltar
	case 3:
	{
		system("cls");
		menuPrincipal(pessoa, sistema, estoque);
		break;
	}
	default:
	{
		system("cls");
		cout << "Opcao Invalida";
		menuGerente(pessoa, sistema, estoque);
	}

	}

}

//Menu de saida do programa
void sair()
{
	system("cls");
	cout << "Obrigado por utilizr nosso sistema! " << endl << endl;
	system("pause");
	exit (0);
}
