#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 

class ListaSequencial {
    private:
        int elementos[MAX_SIZE]; // Vetor de elementos da lista
        int tamanho; // Tamanho atual da lista
    
    public:
        ListaSequencial() {
            tamanho = 0;
        }
    
        bool estaVazia() {
            return tamanho == 0;
        }
    
        bool estaCheia() {
            return tamanho == MAX_SIZE;
        }
    
        int obterTamanho() {
            return tamanho;
        }
    
        int obterElemento(int posicao) {
            if(posicao < 0 || posicao >= tamanho) {
                cerr << "Erro: posicao invalida!" << endl;
                exit(1);
            }
            return elementos[posicao];
        }
    
        void modificarElemento(int posicao, int valor) {
            if(posicao < 0 || posicao >= tamanho) {
                cerr << "Erro: posicao invalida!" << endl;
                exit(1);
            }
            elementos[posicao] = valor;
        }
    
        void inserirElemento(int posicao, int valor) {
            if(posicao < 0 || posicao > tamanho || estaCheia()) {
                cerr << "Erro: posicao invalida ou lista cheia!" << endl;
                exit(1);
            }
            // Desloca os elementos para a direita a partir da posicao de inserção
            for(int i = tamanho; i > posicao; i--) {
                elementos[i] = elementos[i - 1];
            }
            // Insere o novo elemento na posicao indicada
            elementos[posicao] = valor;
            tamanho++;
        }
    
        void retirarElemento(int posicao) {
            if(posicao < 0 || posicao >= tamanho) {
                cerr << "Erro: posicao invalida!" << endl;
                exit(1);
            }
            // Desloca os elementos para a esquerda a partir da posicao de remocao
            for(int i = posicao; i < tamanho - 1; i++) {
                elementos[i] = elementos[i + 1];
            }
            tamanho--;
        }
};

int main() {
    ListaSequencial lista; // Criação da lista vazia

    if(lista.estaVazia()) {
        cout << "A lista esta vazia." << endl; // Verificar se a lista esta vazia
    } else {
        cout << "A lista nao esta vazia." << endl;
    }
    
    lista.inserirElemento(0, 10); // Inserir um elemento na posicao 0
    lista.inserirElemento(1, 20); // Inserir um elemento na posicao 1

    if(lista.estaCheia()) {
        cout << "A lista esta cheia." << endl; // Verificar se a lista esta cheia
    } else {
        cout << "A lista nao esta cheia." << endl;
    }

    cout << "lista modificada na posicao 1" << endl;

    lista.modificarElemento(1, 30); // Modificar o valor
    
    cout << "Elementos da lista antes da remocao: ";
    for(int i = 0; i < lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;
    
    lista.retirarElemento(0); // Retirar o elemento da posicao 0
    
    cout << "Elementos da lista depois da remocao: ";
    for(int i = 0; i < lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;
    
    return 0;
}
