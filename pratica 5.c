#include <stdio.h>
#define FILAS 20
#define POLTRONAS 4

int main() {
    int lugar[FILAS][POLTRONAS] = {0};
    char opcao;
    int ocupacao, escolha, nova_reserva, fila, pol;
    int i, j;

    // (a)
    while(opcao != 'D') {
        printf("\nEscolha uma das opcoes: Fazer Reserva [A], Calcular Ocupacao [B], Mostrar Livres [C] ou Sair [D]");
        scanf(" %c", &opcao);

        switch(opcao) {
            case 'A': // fazer reserva
                do {
                    printf("\nEscolha uma fila de 0 a %d: ", FILAS - 1);
                    scanf("%d", &fila);
                    printf("\nEscolha uma poltrona de 0 a %d: ", POLTRONAS - 1);
                    scanf("%d", &pol);
                    if(!lugar[fila][pol]) {
                        lugar[fila][pol] = 1;
                        printf("\nReserva efetuada em f-%d p-%d! ", fila, pol);
                    } else {
                        printf("\nPoltrona %d da fila %d ocupada! ", pol, fila);
                    }
                    printf("Deseja fazer uma nova reserva? [SIM = 1 e NAO = 0]");
                    scanf("%d", &nova_reserva);
                } while(nova_reserva);
                break;
            case 'B': // (b) total ocupacao
                ocupacao = 0;
                for(i = 0; i < FILAS; i++) {
                    for(j = 0; j < POLTRONAS; j++) {
                        ocupacao += lugar[i][j]; // lugar só guarda 0 ou 1
                    }
                }
                printf("\n%d poltrona(s) ocupada(s)", ocupacao);
                break;
            case 'C': // (e) imprime livres
                for(i = 0; i < FILAS; i++) {
                    for(j = 0; j < POLTRONAS; j++) {
                        if(!lugar[i][j]) {
                            printf("\nAssento f-%d p-%d livre", i, j);
                        }
                    }
                }
                break;
            case 'D': // sair
                printf("\nSaindo do programa...");
                break;
        }
    }

    return 0;
}
