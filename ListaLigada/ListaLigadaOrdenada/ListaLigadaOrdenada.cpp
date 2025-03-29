#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro;
		//2 1
	if(aux->valor >= novo->valor){
		if(novo->valor < aux->valor ){
		
		novo->prox = aux;
		primeiro = novo;
		}
		else{
			cout << "Não pode numeros duplicados";
		}
		
	}else{
		NO* anterior = aux;
		while(aux->prox != NULL){
			if(aux->valor > novo->valor){
				
				novo->prox = aux;
				anterior->prox = novo;
				break;
			}
			else if(aux->valor == novo->valor){
				cout << "Não pode numeros duplicados"  << endl;
				break;
			}
			else{
				anterior = aux;
				aux = aux->prox;
			}
		}
		if(novo->prox == NULL){
			aux->prox = novo;
		}
	}	

}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o elemento: ";
	cin >> numero;

	NO* aux = primeiro;

	if(aux->valor == numero && aux->prox == NULL){

		free(aux);
	}
	else if(aux->valor == numero){
		primeiro = aux->prox;
		free(aux);
	}
	else{
		NO* anterior = aux;
		while(aux->valor <= numero){
			
			if (aux->valor == numero){
				anterior->prox = aux->prox;
				break;
			}
			else{
				anterior = aux;
				aux = aux->prox;
			}
		}
		if(aux->valor == numero){
			free(aux);
		}
		else{
			cout << "Não existe esse numero na lista" << endl;
		}
	}


}

void buscarElemento()
{
	int numero;
	bool achou = false;
	cout << "Digite um numero:";
	cin >> numero;
	NO* aux = primeiro;
	
	while (aux->valor <= numero) {
		if(aux->valor == numero){
			cout << "Encontrado" << endl;
			achou = true;
			break;
		}else{
		aux = aux->prox;
		}
	}
	if(achou == false){
		cout << "Numero nao encontrado" << endl;
	}
}

