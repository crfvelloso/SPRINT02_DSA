#include <stdio.h>
#include <windows.h>
#include <time.h>

int opcao = 0;
int sessoes = 0;
int umses = 0;
float umbat;
float umtempo;
float umtempoh;
float umtarifa;
int doisses = 0;
float doisbat;
float doistempo;
float doistempoh;
float doistarifa;
int tresses = 0;
float tresbat;
float trestempo;
float trestempoh;
float trestarifa;


int main(){
    char *dias_semana[] = {"Domingo", "Segunda-feira", "Terça-feira", 
    "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};
    time_t segundos;
    time(&segundos); 
    struct tm *tempo_atual = localtime(&segundos);
    int diamatriz = tempo_atual->tm_wday;
    int dia = tempo_atual->tm_mday;
    int mes = tempo_atual->tm_mon + 1;   
    int ano = tempo_atual->tm_year + 1900;
    
        printf("=========================================\n");
        printf("          - INICIO DO SISTEMA -           \n");
        printf("=========================================\n");
        printf("Seja bem vindo, administrador.\n");
        printf("Carregando opcoes");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
    do{
        fflush(stdin);
        printf("=========================================\n");
        printf("           - %s -\n", dias_semana[tempo_atual->tm_wday]);
        printf("             - %d/%d/%d -\n", dia, mes, ano);
        printf("        - NUMERO DE SESSOES -    \n");
        printf("                - %d -            \n", sessoes);
        printf("=========================================\n");
        printf("\n              - MENU -           \n");
        printf("1 - REGISTRAR NOVA SESSAO\n");
        printf("2 - RETIRAR SESSAO\n");
        printf("3 - REGRAS DE TARIFACAO\n");
        printf("4 - REGRAS DE CONSUMO DE ENERGIA\n");
        printf("5 - SAIR\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("- OPCAO SELECIONADA: 1\n");
            if (umses == 0){
                printf("- ADICIONANDO PRIMEIRA SESSAO.\n");
                printf("\n- INSIRA O VALOR DA BATERIA: ");
                scanf("%f", &umbat);
                //Calculo do tempo
                umtempo = 2.44 * umbat;
                if (umtempo < 60){
                    printf("Tempo para a carga: %.2f minutos.\n", umtempo);
                }else{
                    umtempoh = umtempo / 60;
                    int umhint = (int)umtempoh;
                    float umminr = (umtempoh - umhint) * 60;
                    printf("Tempo para a carga: %d horas e %.2f minutos.\n", umhint, umminr);
                }
                //Calculo da tarifa
                if (diamatriz >= 1 && diamatriz <= 4){
                    umtarifa = umbat * 0.50;
                    printf("VALOR TARIFA = 0.50\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",umtarifa);
                }else{
                    umtarifa = umbat * 0.85;
                    printf("VALOR TARIFA = 0.85\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",umtarifa);
                }
                umses += 1;
                sessoes += 1;
                printf("\nSessao adicionada com sucesso!\n");
            }else if (doisses == 0){
                printf("- ADICIONANDO SEGUNDA SESSAO.\n");
                printf("\n- INSIRA O VALOR DA BATERIA: ");
                scanf("%f", &doisbat);
                //Calculo do tempo
                doistempo = 2.44 * doisbat;
                if (doistempo < 60){
                    printf("Tempo para a carga: %.2f minutos.\n", doistempo);
                }else{
                    doistempoh = doistempo / 60;
                    int doishint = (int)doistempoh;
                    float doisminr = (doistempoh - doishint) * 60;
                    printf("Tempo para a carga: %d horas e %.2f minutos.\n", doishint, doisminr);
                }
                //Calculo da tarifa
                if (diamatriz >= 1 && diamatriz <= 4){
                    doistarifa = doisbat * 0.50;
                    printf("VALOR TARIFA = 0.50\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",doistarifa);
                }else{
                    doistarifa = doisbat * 0.85;
                    printf("VALOR TARIFA = 0.85\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",doistarifa);
                }
                doisses += 1;
                sessoes += 1;
                printf("\nSessao adicionada com sucesso!\n");
            }else if (tresses == 0){
                printf("- ADICIONANDO TERCEIRA SESSAO.\n");
                printf("\n- INSIRA O VALOR DA BATERIA: ");
                scanf("%f", &tresbat);
                //Calculo do tempo
                trestempo = 2.44 * tresbat;
                if (trestempo < 60){
                    printf("Tempo para a carga: %.2f minutos.\n", trestempo);
                }else{
                    trestempoh = trestempo / 60;
                    int treshint = (int)trestempoh;
                    float tresminr = (trestempoh - treshint) * 60;
                    printf("Tempo para a carga: %d horas e %.2f minutos.\n", treshint, tresminr);
                }
                //Calculo da tarifa
                if (diamatriz >= 1 && diamatriz <= 4){
                    trestarifa = tresbat * 0.50;
                    printf("VALOR TARIFA = 0.50\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",trestarifa);
                }else{
                    trestarifa = tresbat * 0.85;
                    printf("VALOR TARIFA = 0.85\n");
                    printf("Valor a ser cobrado pela carga: %.2f\n",trestarifa);
                }
                tresses += 1;
                sessoes += 1;
            printf("\nSessao adicionada com sucesso!\n");
            }else{
                printf("Numero maximo de sessoes atingido!\n");
                printf("Retire alguma sessao antes de prosseguir!\n");
            }
            printf("Voltando ao menu principal");
            Sleep(1500);
            printf(".");
            Sleep(1500);
            printf(".");
            Sleep(1500);
            printf(".\n");
        }else if (opcao == 2){
            int doismenu = 0;
            printf("OPCAO SELECIONADA: 2\\n");
            printf("Informacoes das sessoes conectadas:\n");
            if (umses == 0){
                printf("\n - VAGA 1 -\n");
                printf("DESOCUPADA\n");
            }else{
                printf("\n- VAGA 1 -\n");
                printf("Bateria do carro: %.1f\n", umbat);
                printf("Tarifa cobrada: %.2f\n", umtarifa);
            }
            if (doisses == 0){
                printf("\n - VAGA 2 -\n");
                printf("DESOCUPADA\n");
            }else{
                printf("\n- VAGA 2 -\n");
                printf("Bateria do carro: %.1f\n", doisbat);
                printf("Tarifa cobrada: %.2f\n", doistarifa);
            }
            if (tresses == 0){
                printf("\n - VAGA 3 -\n");
                printf("DESOCUPADA\n");
            }else {
                printf("\n- VAGA 3 -\n");
                printf("Bateria do carro: %.1f\n", tresbat);
                printf("Tarifa cobrada: %.2f\n", trestarifa);
            }
            do{
                printf("\n\n QUAL SESSAO GOSTARIA DE RETIRAR?\n");
                printf("1 - VAGA 1\n");
                printf("2 - VAGA 2\n");
                printf("3 - VAGA 3\n");
                printf("4 - SAIR\n");
                int doisopcao = 0;
                scanf("%d", &doisopcao);
                if (doisopcao == 1 && umses == 0){
                    printf("A vaga 1 ja esta vazia!");
                    Sleep(1500);
                }else if (doisopcao == 1 && umses == 1){
                    printf("Vaga 1 retirada com sucesso!");
                    Sleep(1500);
                    umses = 0;
                    sessoes -= 1;
                }else if (doisopcao == 2 && doisses == 0){
                    printf("A vaga 2 ja esta vazia!");
                    Sleep(1500);
                }else if (doisopcao == 2 && doisses == 1){
                    printf("Vaga 2 retirada com sucesso!");
                    Sleep(1500);
                    doisses = 0;
                    sessoes -= 1;
                }else if (doisopcao == 3 && tresses == 0){
                    printf("A vaga 3 ja esta vazia!");
                    Sleep(1500);
                }else if (doisopcao == 3 && tresses == 1){
                    printf("Vaga 3 retirada com sucesso!");
                    Sleep(1500);
                    tresses = 0;
                    sessoes -= 1;
                }else{
                    doismenu = 1;
                    printf("Voltando ao menu principal");
                    Sleep(1500);
                    printf(".");
                    Sleep(1500);
                    printf(".");
                    Sleep(1500);
                    printf(".\n");
                }

            }while (doismenu == 0);
        }else{

        }
        }while (opcao != 5);
    return 0;
}