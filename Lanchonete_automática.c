#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
int estoque [5] ={10, 10, 10, 10, 10}; // Vetor utilizado para contabilizar o estoque dos produtos.
float total_compra = 0;
float compra1, compra2, compra3, compra4, compra5 = 0;

// Função principal.
int main() { 

    setlocale(LC_ALL,"Portuguese");
    char enter;
    float valor_total = 0;
    printf("_______________Bem vindo!!!______________\n");
    printf("______Lanchonete do Ericklys e Breno_______\n");
    printf("Aperte a tecla ENTER para visualizar o cardápio!");
    scanf("%c", &enter);
    MenuProdutos();
}

// Função para limpar a tela. 
void LimparTela() {
    system("cls");
    }

// Função responsável por mostrar os produtos do cardápio. 
int MenuProdutos () {

    LimparTela();
    printf("___________________Cardápio_______________________\n");
    printf("|  1 - Cajuína 200ml______________________R$3,00  |\n");
    printf("|  2 - Coca Cola 200ml_____________________R$3,00  |\n");
    printf("|  3 - Bolacha Richester___________________R$2,50  |\n");
    printf("|  4 - Tapioca_____________________________R$7,00  |\n");
    printf("|  5 - Cuscuz______________________________R$7,00  |\n");
    printf("______________________________________________________\n");
    int escolha = LerEscolha();
    ConfirmarCompra(escolha);
}

// Função que processa a entrada do usário, diminui a quantidade comprada do estoque e efetua a conta que o usuário irá pagar.
int ConfirmarCompra(int escolha) {

    LimparTela();
    int quant_compra;
    switch (escolha) {
        case 1:
            printf("Você escolheu cajuína.\nO valor é R$3,00.\n");
            printf("Informe a quantidade que deseja comprar:\n");
            scanf("%d", &quant_compra);
            if (quant_compra <= estoque[0]){
                estoque[0] -= quant_compra;
                compra1 = (3.00 * quant_compra);
                total_compra += compra1;
                printf("Você comprou %d Cajuína.\n", quant_compra);
                CompraNovamente();
            }
            else{
                printf("Infelizmente não temos essa quantidade em estoque.\n");
                printf("No momento temos %d disponível para compra\n", estoque[0]);
                CompraNovamente();
            }
            break;
        case 2:
            printf("Você escoheu Coca Cola.\nO valor da unidade é R$3,00.\n");
            printf("Informe a quantidade que deseja comprar:\n");
            scanf("%d", &quant_compra);
            if (quant_compra <= estoque[1]){
                estoque[1] -= quant_compra;
                compra2 = (3.00 * quant_compra);
                total_compra += compra2;
                printf("Você comprou %d Coca Cola\n", quant_compra);
                CompraNovamente();
                
            }
            else{
                printf("Infelizmente não temos essa quantidade em estoque.\n");
                printf("No momento temos %d disponível para compra\n", estoque[1]);
                CompraNovamente();
           }
           break;
        case 3:
            printf("Você escolheu Bolacha Richester.\nO valor da unidade é R$2,50.\n");
            printf("Informe a quantidade que deseja comprar:\n");
            scanf("%d", &quant_compra);
            if (quant_compra <= estoque[2]){
                estoque[2] -= quant_compra;
                compra3 = (2.50 * quant_compra);
                char nome3 = "Bolacha Richester";
                printf("Você comprou %d pacote de Bolacha Richester.\n", quant_compra);
                CompraNovamente();
                
            }
            else{
                printf("Infelizmente não temos essa quantidade em estoque.\n");
                printf("No momento temos %d disponível para compra.\n", estoque[2]);
                CompraNovamente();
            }
            break;
        case 4:
            printf("Você escolheu Tapioca.\nO valor da unidade é R$7,00.\n");
            printf("Informe a quantidade que deseja comprar:\n");
            scanf("%d", &quant_compra);
            if (quant_compra <= estoque[3]){
                estoque[3] -= quant_compra;
                compra4 = (7.00 * quant_compra);
                total_compra += compra4;
                printf("Você comprou %d Tapioca.\n", quant_compra);
                CompraNovamente();
            }
            else{
                printf("Infelizmente não temos essa quantidade em estoque.\n");
                printf("No momento temos %d disponivel para compra.\n", estoque[3]);
                CompraNovamente();
            }
            break;
        case 5:
            printf("Você escolheu Cuscuz.\nO valor da unidade é R$7,00.\n");
            printf("Informe a quantidade que deseja comprar:\n");
            scanf("%d", &quant_compra);
            if (quant_compra <= estoque[4]){
                estoque[4] -= quant_compra;
                compra5 = (7.00 * quant_compra);
                total_compra += compra5;
                printf("Você comprou %d Cuscuz.\n", quant_compra);
                CompraNovamente();
            }
            else{
                printf("Infelizmente não temos essa quantidade em estoque.\n");
                printf("No momento temos %d disponível para compra.\n", estoque[4]);
                CompraNovamente();
            }
            break;  
    }
}

// Função para receber uma nova entrada caso o usário queira comprar novamente.
int CompraNovamente() {

    int outra_compra;
    printf("Deseja comprar mais alguma coisa? (1 para sim / 0 para não)\n");
    fflush(stdin);
    scanf("%d", &outra_compra);
    if(outra_compra == 1){
        MenuProdutos();
    }
    else if(outra_compra == 0){
        LimparTela();
        printf("Compras finalizadas!!!\nObrigado por comprar conosco.\n");
        printf("\n");   
        printf("Valor total do pedidos é de R$%.2f.", total_compra);
        exit(0);
    }
    else{
        LimparTela();
        printf("Valor informado é inválido!\n");
        CompraNovamente();
    }    
}

// Função responsável para verificar se a entrada do usuário é válida.
int LerEscolha() {

    int cod;
    printf("Informe o código referente ao produto que deseja comprar:\n");
    fflush(stdin);
    scanf("%d", &cod);
    if(cod >= 1 && cod <= 5){
        return cod;
    }
    else{ 
        printf("Código inválido!\n");
        LerEscolha();
    }    
}
