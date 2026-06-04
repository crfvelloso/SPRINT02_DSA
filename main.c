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

struct DataCompleta {
    int diamatriz;
    int dia;
    int mes;
    int ano;
    char *nome_dia;
};

struct DataCompleta obterDataCompleta() {
    static char *dias_semana[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};
    time_t segundos;
    struct DataCompleta resultado;

    time(&segundos); 
    struct tm *tempo_atual = localtime(&segundos);

    resultado.diamatriz = tempo_atual->tm_wday;
    resultado.dia = tempo_atual->tm_mday;
    resultado.mes = tempo_atual->tm_mon + 1;   
    resultado.ano = tempo_atual->tm_year + 1900;
    resultado.nome_dia = dias_semana[resultado.diamatriz];

    return resultado;
}

void registrar_nova_sessao(){
    struct DataCompleta hoje = obterDataCompleta();
    printf("- OPCAO SELECIONADA: 1\n");
    printf("\n=========================================\n");
    printf("        - REGISTRAR NOVA SESSAO -        \n");
    printf("=========================================\n");
    if (umses == 0){
        printf("- ADICIONANDO PRIMEIRA SESSAO.\n");
        printf("\n- INSIRA O VALOR DA BATERIA: ");
        scanf("%f", &umbat);
        
        if (umbat > 60) {
            umtempo = 4.88 * umbat; 
        } else {
            umtempo = 2.44 * umbat;
        }

        if (umtempo < 60){
            printf("Tempo para a carga: %.2f minutos.\n", umtempo);
        }else{
            umtempoh = umtempo / 60;
            int umhint = (int)umtempoh;
            float umminr = (umtempoh - umhint) * 60;
            printf("Tempo para a carga: %d horas e %.2f minutos.\n", umhint, umminr);
        }
        
        if (hoje.diamatriz >= 1 && hoje.diamatriz <= 4){
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
        
        if (doisbat > 60) {
            doistempo = 4.88 * doisbat;
        } else {
            doistempo = 2.44 * doisbat;
        }

        if (doistempo < 60){
            printf("Tempo para a carga: %.2f minutos.\n", doistempo);
        }else{
            doistempoh = doistempo / 60;
            int doishint = (int)doistempoh;
            float doisminr = (doistempoh - doishint) * 60;
            printf("Tempo para a carga: %d horas e %.2f minutos.\n", doishint, doisminr);
        }
        
        if (hoje.diamatriz >= 1 && hoje.diamatriz <= 4){
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
        
        if (tresbat > 60) {
            trestempo = 4.88 * tresbat;
        } else {
            trestempo = 2.44 * tresbat;
        }

        if (trestempo < 60){
            printf("Tempo para a carga: %.2f minutos.\n", trestempo);
        }else{
            trestempoh = trestempo / 60;
            int treshint = (int)trestempoh;
            float tresminr = (trestempoh - treshint) * 60;
            printf("Tempo para a carga: %d horas e %.2f minutos.\n", treshint, tresminr);
        }
        
        if (hoje.diamatriz >= 1 && hoje.diamatriz <= 4){
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
}

void voltar_ao_menu(){
    printf("Voltando ao menu principal");
    Sleep(1500);
    printf(".");
    Sleep(1500);
    printf(".");
    Sleep(1500);
    printf(".\n");
}

void sessoes_conectadas() {
    int voltar = 0;
    
    do {
        printf("- OPCAO SELECIONADA: 2\n");
        printf("\n=========================================\n");
        printf("       - INFORMACOES DAS SESSOES -        \n");
        printf("=========================================\n");

        if (umses == 0) {
            printf("\n - VAGA 1 -\n");
            printf("DESOCUPADA\n");
        } else {
            printf("\n - VAGA 1 -\n");
            printf("Bateria do carro: %.1f\n", umbat);
            printf("Tarifa cobrada: %.2f\n", umtarifa);
        }

        if (doisses == 0) {
            printf("\n - VAGA 2 -\n");
            printf("DESOCUPADA\n");
        } else {
            printf("\n - VAGA 2 -\n");
            printf("Bateria do carro: %.1f\n", doisbat);
            printf("Tarifa cobrada: %.2f\n", doistarifa);
        }

        if (tresses == 0) {
            printf("\n - VAGA 3 -\n");
            printf("DESOCUPADA\n");
        } else {
            printf("\n - VAGA 3 -\n");
            printf("Bateria do carro: %.1f\n", tresbat);
            printf("Tarifa cobrada: %.2f\n", trestarifa);
        }

        printf("\n=========================================\n");
        printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL: ");
        scanf("%d", &voltar);

        if (voltar != 1) {
            printf("Opcao invalida. Tente novamente.\n");
            Sleep(1000);
        }

    } while (voltar != 1);
}

void retirar_sessoes(){
    int doismenu = 0;
    printf("- OPCAO SELECIONADA: 3\n");
    printf("\n=========================================\n");
    printf("           - RETIRAR SESSOES -           \n");
    printf("=========================================\n");
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
        }
    }while (doismenu != 1);
}

void regras_de_tarifacao() {
    struct DataCompleta hoje = obterDataCompleta();
    int voltar = 0;
    float tarifa_hoje;

    if (hoje.diamatriz == 0 || hoje.diamatriz == 6) {
        tarifa_hoje = 0.85;
    } else {
        tarifa_hoje = 0.50;
    }

    do {
        printf("- OPCAO SELECIONADA: 4\n");
        printf("\n=========================================\n");
        printf("         - REGRAS DE TARIFACAO -         \n");
        printf("=========================================\n");
        printf("Dias de semana: R$ 0.50 por kWh\n");
        printf("Fim de semana: R$ 0.85 por kWh\n\n");
        printf("=========================================\n");
        printf("Hoje e %s\n", hoje.nome_dia);
        printf("Tarifa cobrada: %.2f\n", tarifa_hoje);
        printf("=========================================\n");
        
        printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL: ");
        scanf("%d", &voltar);

        if (voltar != 1) {
            printf("Opcao invalida. Tente novamente.\n");
            Sleep(1000);
        }

    } while (voltar != 1);
}

void regras_de_consumo_de_energia() {
    int voltar = 0;

    do {
        printf("- OPCAO SELECIONADA: 5\n");
        printf("\n=========================================\n");
        printf("     - REGRAS DE CONSUMO DE ENERGIA -    \n");
        printf("=========================================\n");
        printf("Baterias ate 60 kWh:\n");
        printf("- Utiliza a potencia convencional de 22 kWh.\n\n");
        printf("Baterias acima de 60 kWh:\n");
        printf("- Utiliza potencia mais lenta para\n");
        printf("  nao sobrecarregar o sistema.\n");
        printf("=========================================\n");
        
        printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL: ");
        scanf("%d", &voltar);

        if (voltar != 1) {
            printf("Opcao invalida. Tente novamente.\n");
            Sleep(1000);
        }

    } while (voltar != 1);
}

int main(){
    struct DataCompleta hoje = obterDataCompleta();
    
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
        printf("           - %s -\n", hoje.nome_dia);
        printf("             - %d/%d/%d -\n", hoje.dia, hoje.mes, hoje.ano);
        printf("        - NUMERO DE SESSOES -    \n");
        printf("                - %d -            \n", sessoes);
        printf("=========================================\n");
        printf("\n              - MENU -           \n");
        printf("1 - REGISTRAR NOVA SESSAO\n");
        printf("2 - SESSOES CONECTADAS\n");
        printf("3 - RETIRAR SESSOES\n");
        printf("4 - REGRAS DE TARIFACAO\n");
        printf("5 - REGRAS DE CONSUMO DE ENERGIA\n");
        printf("6 - SAIR\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            registrar_nova_sessao();
            voltar_ao_menu();
        }else if (opcao == 2){
            sessoes_conectadas();
            voltar_ao_menu();
        }else if (opcao == 3){
            retirar_sessoes();
            voltar_ao_menu();
        }else if (opcao == 4){
            regras_de_tarifacao();
            voltar_ao_menu();
        }else if (opcao == 5){
            regras_de_consumo_de_energia();
            voltar_ao_menu();
        }
    }while (opcao != 6);
    printf("\n=========================================\n");
    printf("      Encerrando o sistema... Ate logo!  \n");
    printf("=========================================\n");
    printf("       GoodWe: Smart Energy Innovator    \n");
    printf("=========================================\n");
    return 0;
}