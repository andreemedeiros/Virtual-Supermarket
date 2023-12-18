#include "Estoque.h"

//Construtor default vazio
Estoque::Estoque(){
	
	for(int i = 0; i < x; i++)
	{
		codigo = i;
		prod[codigo].nome = "Vazio";
		prod[codigo].quantidade = 0;
		prod[codigo].valor = 0.0;
	}
}

//Métodos para atribuir e receber faturamento
void Estoque::setFaturamento(float faturamento){
	this->faturamento = faturamento;
}
float Estoque::getFaturamento(void){
	return faturamento;
}


//Atribui e recebe código
void Estoque::setCodigo(int codigo)
{
	this->codigo = codigo;
}
int Estoque::getCodigo(void)
{
	return codigo;
}

//Método para receber nome
string Estoque::getNome(int cod){
	return prod[cod].nome;
}

//Métodos para receber e atribuir quantidade
void Estoque::setQuantidade(int cod, int quantidadeCompra){
	prod[cod].quantidade = prod[cod].quantidade - quantidadeCompra;
}
int Estoque::getQuantidade(int cod){
	return prod[cod].quantidade;
}

//Método para receber valor;
float Estoque::getValor(int cod){
	return prod[cod].valor;
}

//Cadastra produto (nome,quantidade,valor)
void Estoque::setCadastrar(string nome, float valor, int quantidade)
{
	prod[codigo].nome = nome;
	prod[codigo].valor = valor;
	prod[codigo].quantidade = quantidade;
	
}

//Imprime a lista de produtos em estoque
void Estoque::imprime()
{
	
	cout << "Lista de produtos em estoque: "<<endl;
	
	for (int i=0;i<x;i++){
		if(prod[i].nome == "Vazio"){
			
		}else{
	cout << "Codigo do produto:" << i << endl;
	cout << "Nome: " << prod[i].nome << endl;
	cout << "Valor: " << prod[i].valor << endl;
	cout << "Quantidade em estoque: " << prod[i].quantidade << endl << endl;
		}
	}
}