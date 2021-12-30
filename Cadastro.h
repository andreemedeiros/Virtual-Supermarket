#ifndef Cadastro_H
#define Cadastro_H

//Constante definida para limite de cadastros no sistema(Chave de acesso do cliente)
#define x 999


//Struct para Endereço da pessoa
struct Dados
{
	//Dados da pessoa
	string usuario;
	string nome;
	string cpf;
	//Endereço da pessoa
	string cep;
	string rua;
	string bairro;
	int numero;
	string complemento;
};

class Cadastro
{
	//Auxiliar para numero da pessoa no cadastro
	int chaveCliente;
	//Enredeço da pessoa
	Dados end[x];
public:
	//Construtor default vazio
	Cadastro();
	void setChaveCliente(int);
	//Método para Cadastrar os dados
	void cadastrar(string, string, string, string, string, int, string, string);
	//Método imprime dados da pessoa e seu endereço
	void imprime(int)const;
	//Método verifica se usuário ta cadastrado
	string verifica(int);
	

};
#endif