#ifndef ESTOQUE_H
#define ESTOQUE_H

//Constante definida para limite de produtos no estoque
#define x 100 

//struct para produtos
struct produtos{
	string nome;
    int quantidade;
    float valor;
};

//Classe base
//Fornece um estoque de produtos(nome, codigo, quantidade e valor)
class Estoque
{
	int teste;
	
protected:
	//Faturamento
	float faturamento;
	//Codigo do produto na prateleira
	int codigo;
	//Lista de produtos
	produtos prod[x];
	
public:
	//Construtor default. Inicializa todo o estoque padrão
	Estoque();
	
	//Métodos para atribuir e receber faturamento
	void setFaturamento(float);
	float getFaturamento(void);
	
	//Métodos para atribuir e receber código
	void setCodigo(int);
	int getCodigo(void);
	
	//Métodos para receber nome
	string getNome(int);
	//Métodos para receber e atribuir quantidade
	void setQuantidade(int,int);
	int getQuantidade(int);
	//Método para receber valor;
	float getValor(int);
	
	//Método que Cadastra produto(nome, quantidade e valor)
	void setCadastrar(string, float, int);
	//Método que imprime a lista de produtos em estoque
	void imprime();
};

#endif
