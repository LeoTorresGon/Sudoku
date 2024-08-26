#include <stdio.h>

int menuPrincipal(){
    int opcao, ver = 1;
    while(ver){
        printf("1 - Novo jogo\n2 - Carregar jogo\n3 - Sair\n");
        scanf("%d", &opcao);
        int a = 1;
        switch(opcao){
            case 1:
                int malha[9][9]; // = Gerar matriz inicial
                while(a != 4){
                //    imprimirMalha(malha);
                //    a = menuJogo(&malha);
                }
                break;
            case 2:
                malha[9][9]; // = Carregar arquivos de jogo predefinido
                while(a != 4){
                //    imprimirMalha(malha);
                //    a = menuJogo(&malha);
                }
                break;
            case 3:
                ver = 0;
                break;
            default:
                printf("Invalido\n");
        }
    }
    
}

int menuJogo(int malha[][9]){
    int opcao;
    scanf("%d", &opcao);
    printf("1 - Adicionar jogada\n2 - Remover jogada\n3 - Verificar\n4 - Voltar");
    switch (opcao)
    {
    case 1:
        printf("Digite a linha, coluna e valor a adicionar.");
        int linha, coluna, valor;
        scanf("%d %d %d", &linha, &coluna, &valor);
        adicionarJogada(malha, linha, coluna, valor);
        break;
    case 2:
        printf("Digite a linha, coluna do valor a remover.");
        int linha, coluna;
        scanf("%d %d", &linha, &coluna);
        adicionarJogada(malha, linha, coluna, 0);
        break;
    case 3:
        //return verificar(); // verificar retornar 4 se estiver certo
        break;
    case 4:
        printf("Certeza que quer sair? Voce perdera seu progresso. Digite 1 para confirmar.");
        int confirmacao;
        scanf("%d", &confirmacao);
        if (confirmacao == 1){
            return 4;
        }
        break;
    default:
        printf("Opcao invalida");
    }

}

void mostrarTempos(){

}

void imprimirMalha(int malha[][9]){
    printf("-------------------------------------\n");
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (malha[i][j] == 0)
                printf("| - ");
            else if (malha[i][j] > 9){
                printf("| %d ", malha[i][j]/10);
            }
            else
                printf("| %d ", malha[i][j]);
        }
        printf("|\n-------------------------------------\n");
    }

}

int adicionarJogada(int malha[][9],int linha, int coluna, int valor){
    if(malha[linha][coluna] <= 9)
        malha[linha][coluna] = valor;
    else
        printf("Nao e possivel remover uma dica.");
}

int verificar(int malha[][9]){
    // Contar quantos números por linha, coluna e subgrid.
    int c[9] = {0};
    // linhas
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (malha[i][j] == 0){
                printf("Jogo nao esta completo - ");
                return 0;   // O jogo não está completo
            }
            c[malha[i][j]-1]++;
        }
        if(c[i] != i+1)
            return 0;
    }
    // Colunas
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (malha[i][j] == 0){
                printf("Jogo nao esta completo - ");
                return 0;   // O jogo não está completo
            }
            c[malha[j][i]-1]++;
        }
        if(c[i] != i+10)
            return 0;
    }
    // Subgrids
    int x = -3, y = 0;
    for (int k = 0; k < 9; k++){
        // Percorrer de 0 a 2, 3 a 5 e 6 a 8 (Subgrids). y para linha, x para coluna
        if (k % 3 == 0){
            x += 3;
            y = 0;
        } else
            y += 3;
        printf("%d %d |\n", x, y);
        for(int i = y; i < y + 3; i++){
            for (int j = x; j < x + 3; j++){
                c[malha[i][j]-1]++;
            }
        }
        if(c[k] != k+19)
            return 0;
    }
    return 4;
}

int main(){
    //menuPrincipal();
    int a[9][9] ={
        5,3,4,6,7,8,9,1,2,
        6,7,2,1,9,5,3,4,8,
        1,9,8,3,4,2,5,6,7,
        8,5,9,7,6,0,0,2,3,
        4,2,6,0,5,3,7,9,1,
        7,1,3,9,2,4,0,5,6,
        9,6,1,0,3,7,2,8,4,
        2,8,7,4,1,9,6,3,5,
        3,4,5,2,8,6,1,7,9
    };
    //printf("%d\n", verificar(a));
    imprimirMalha(a);
}