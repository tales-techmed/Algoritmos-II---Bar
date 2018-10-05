#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

typedef struct Produto{
    char nome[30];
    float preco;
    int quantidade;
};

void alteraCardapio(char nome[][30], float preco[], int quantidade[], int linhas, int linha){
    cout << "Digite o novo nome da bebida " << nome[linha] <<": ";
    cin.getline(nome[linha],sizeof(nome[linha]));
    cout << "Digite o preco: ";
    scanf("%f",&preco[linha]);
    cout << "Digite a quantidade: ";
    scanf("%d",&quantidade[linha]);
    cin.ignore();
}

void criaCardapio(char nome[][30], float preco[], int quantidade[], int linhas){
    cin.ignore();
    for(int i=0; i<linhas; i++){
        cout << "Digite o nome da bebida" << i <<": ";
        cin.getline(nome[i],sizeof(nome[i]));
        cout << "Digite o preco: ";
        scanf("%f",&preco[i]);
        cout << "Digite a quantidade: ";
        scanf("%d",&quantidade[i]);
        cin.ignore();
    }
}

void incluirProduto(Produto *p){
    cin.ignore();
    cout << "Digite o nome da bebida: ";
    cin.getline(p->nome,sizeof(p->nome));
    cout << "Digite o preco: ";
    scanf("%f",&p->preco);
    cout << "Digite a quantidade: ";
    scanf("%d",&p->quantidade);
    cin.ignore();
}

void mostraCardapio(char nome[][30], float preco[], int quantidade[], int linhas){
    cout << "Cardapio"<<endl;
    for(int i=0; i<linhas; i++){
        cout << i << " " << nome[i] << " - " << preco[i] << " - " <<
            quantidade[i]<<endl;
    }
}
void mostraCardapioProdutos(Produto p[], int linhas){
    cout << "Cardapio"<<endl;
    for(int i=0; i<linhas; i++){
        cout << i << " " << p[i].nome << " - "
        << p[i].preco << " - " <<
        p[i].quantidade<<endl;
    }
}

int menuPrincipal(){
    cout<< "Menu Principal" << endl;
    cout<< "0 - Sair" << endl;
    cout<< "1 - Cadastrar cardapio" << endl;
    cout<< "2 - Alterar cardapio" << endl;
    cout<< "3 - Mostrar cardapio" << endl;
    cout<< "4 - Vender bebida" << endl;
    cout<< "5 - Fechar comanda" << endl;
    cout<< "6 - Incluir Produto" << endl;
    cout<< "Sua opcao:" << endl;
    int opc=0;
    scanf("%d",&opc);
    return opc;
}

void venda(float comanda[], float preco[], int quantidade[],
           int cod_comanda, int cod_bebida, int qtd){
    if(quantidade[cod_bebida] >= qtd){
        quantidade[cod_bebida] -= qtd;
        comanda[cod_comanda] += qtd*preco[cod_bebida];
        cout << "Venda realizada... " << endl;
        cout << "Comanda " << cod_comanda << "  Valor R$ " <<
             comanda[cod_comanda] << endl;
    }
    else
        cout << "Quantidade insuficiente " << endl;
}

void fecharComanda(float comanda[], int cod_comanda){
    cout << "O valor da comanda "<< cod_comanda<< " e R$"<<comanda[cod_comanda]<< endl;
    comanda[cod_comanda] = 0;
}

int main(){
    char nome[5][30];
    float preco[5];
    int quantidade[5];
    float comanda[100];
    Produto produtos[20];
    int iproduto=0;
    int cod_produto, cod_comanda, qtd_produto;
    Produto p;
    for(int i=0; i<100; i++)
        comanda[i]=0;
    int opc = menuPrincipal();
    while(opc!=0){
        switch (opc){
            case 1:     criaCardapio(nome,preco,quantidade,5);
            break;
            case 2: cout << "Codigo do produto para ser alterado:";
                    scanf("%d",&cod_produto);
                    alteraCardapio(nome,preco,quantidade,5,cod_produto);
            break;
            case 3: //mostraCardapio(nome,preco,quantidade,5);
                    mostraCardapioProdutos(produtos, iproduto);
            break;
            case 4: cout << "Numero da comanda:";
                    scanf("%d",&cod_comanda);
                    cout << "Codigo o produto:";
                    scanf("%d",&cod_produto);
                    cout << "Quantidade:";
                    scanf("%d",&qtd_produto);
                    venda(comanda, preco, quantidade, cod_comanda, cod_produto, qtd_produto);
            break;
            case 5: cout << "Fechar conta" << endl<<
                        "Numero da comanda:";
                    scanf("%d",&cod_comanda);
                    fecharComanda(comanda, cod_comanda);
            break;
            case 6 : incluirProduto(&p);
                produtos[iproduto++] = p;
                cout << p.nome << " " << p.preco << " "<< p.quantidade << endl;
            break;
        }
        opc = menuPrincipal();
    }
}


