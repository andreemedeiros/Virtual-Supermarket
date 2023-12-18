#include "Sistema.h"

//Construtor que cadastra nova venda
Sistema::Sistema(): Estoque()
{
	//Constroe a lista padrão
	for(int j=0;j<100;j++){
		lista[j].nome = "Vazio";
		lista[j].quantidade = 0;
	}
	valorCompra = 0;
}

//Método Imprime Lista de produtos da prateleira
void Sistema::imprimeListaProdutos(Estoque estoque){
	
	cout <<"Lista de produtos na prateleira:"<<endl<<endl;

	for (int i=0;i<x;i++){
		if(estoque.getNome(i) == "Vazio"){
		}else{
	cout << "" << estoque.getNome(i) << " (Código: " << i << " )" << endl;
	cout << "Quantidade em estoque: " << estoque.getQuantidade(i) << endl;
	cout << "Preço: " << estoque.getValor(i) << endl << endl;
	}
	}	
}

//Método para gerar nota fiscal
void Sistema::gerarNota(Estoque estoque, int codigo, int quantidade){
	//Passa nome para nota fiscal
	lista[codigo].nome = estoque.getNome(codigo);
	//Passa quantidade para nota fiscal
	lista[codigo].quantidade = quantidade;
	//Passa valor para nota fiscal
	lista[codigo].valor = estoque.getValor(codigo);
}

//Método para imprimir lista dos produtos vendido
void Sistema::imprimeNota(){
	
	cout << "NOTA FISCAL: "<<endl<<endl;
	
	for(int i=0;i<100;i++){
		if(lista[i].nome =="Vazio"){
			
		}else{
		//imprime produtos comprados
		cout << lista[i].nome <<" - "<<lista[i].quantidade<<" unidade(s)"<<endl;
		
		
		//Atualiza valor da compra
		for(int j=0;j < lista[i].quantidade; j++){
		valorCompra = valorCompra + lista[i].valor;
		}
		
		
		
		
	}
	}
	
	cout << endl << "Valor total da compra: " << valorCompra <<" R$" << endl << endl;
	
}