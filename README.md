# Data Structure And Algorythms
Professor: Erick Toshio Yamamoto

Sprint 02

## Problema:
Um sistema que:

Gerencia vários carregamentos
Controla energia
Aplica cobrança dinâmica
Simula comunicação com plataforma
# EXPLICAÇÃO DA LÓGICA
O nosso código em C é um sistema gerenciador de uma estação de recarga para veículos elétricos que opera com múltiplas vagas. Ele coleta dados do usuário, monitora o tempo real através do sistema operacional e aplica regras dinâmicas de carregamento e tarifação, gerenciando o status de até 3 sessões simultâneas.

## Estruturas de Dados e Controle de Tempo
O sistema utiliza a biblioteca <time.h> e encapsula as informações de data em uma estrutura personalizada (struct DataCompleta). Essa estrutura permite capturar o dia atual da semana (diamatriz), dia, mês, ano e o nome do dia em texto. Essa validação de tempo real é o motor para as regras dinâmicas de cobrança do sistema.

As variáveis de controle das sessões (quantidade de sessões ativas, bateria, tempo e tarifa de cada uma das 3 vagas) são globais, garantindo que o estado das vagas persista enquanto o programa estiver rodando.

Sistema de Menu e Navegação
A arquitetura do fluxo principal abandonou saltos estruturais e utiliza um laço do-while robusto. O menu principal é redesenhado a cada iteração, exibindo o cabeçalho dinâmico com a data atual e o número de sessões ativas.

A navegação para os submenus e o retorno ao menu principal são isolados em funções dedicadas (como voltar_ao_menu()), utilizando pausas visuais com a função Sleep() da biblioteca <windows.h> para melhorar a experiência do usuário.

## Lógica das Opções do Menu
Opção 1: Registrar Nova Sessão
Gerenciamento de Vagas: O sistema verifica sequencialmente qual das 3 vagas está desocupada. Se o limite máximo for atingido, a entrada é bloqueada.
Regras de Consumo (Bateria): Solicita o valor da bateria. Se a capacidade for superior a 60 kWh, o sistema aplica um multiplicador de tempo maior (4.88 minutos por kWh), simulando uma potência reduzida para não sobrecarregar a rede. Para baterias até 60 kWh, utiliza o padrão rápido de 22kW (2.44 minutos por kWh).
Regras de Tarifação Dinâmica: Consulta a struct de tempo. Se o diamatriz corresponder ao fim de semana (Domingo ou Sábado), a tarifa aplicada é de R$ 0.85 por kWh. Nos dias úteis, o valor cai para R$ 0.50 por kWh.
Conversão de Tempo: Se a estimativa de carga ultrapassar 60 minutos, o sistema converte e exibe o formato formatado em horas e minutos.

Opção 2: Sessões Conectadas
Exibe um painel de monitoramento. O sistema itera pelas variáveis de estado das 3 vagas, imprimindo no console quais estão "DESOCUPADAS" e detalhando os dados (bateria e tarifa projetada) das que possuem carros conectados. O painel prende a tela em um laço de leitura até o usuário digitar 1 para retornar.

Opção 3: Retirar Sessões
Permite liberar uma vaga específica. O sistema exibe o status atual de todas as vagas e pede ao usuário que selecione qual deseja desconectar (1, 2 ou 3). Se a vaga escolhida já estiver vazia, o sistema alerta o erro. Se estiver ocupada, as variáveis de controle daquela vaga específica são resetadas a zero e a contagem global de sessões diminui.

Opção 4: Regras de Tarifação
Exibe de forma descritiva as regras de cobrança do sistema (diferença entre dias de semana e fins de semana), avalia o dia atual e imprime qual das tarifas está vigorando no momento para o usuário.

Opção 5: Regras de Consumo de Energia
Exibe o manual de boas práticas do totem, explicando a limitação de velocidade de carregamento (potência reduzida) para veículos com baterias acima de 60 kWh como medida de segurança energética da estação.

Opção 6: Sair
Interrompe o laço do-while do menu principal, exibe uma mensagem de encerramento contendo o slogan corporativo da GoodWe e finaliza a execução com return 0.

MEMBROS
Guilherme Figueira Velloso - RM 568827

José Augusto Ribeiro Freire Manfrinato - RM 571151

Lais da Silva Dias - RM 569943

João Augusto Poloniato Telles - RM 571443

Thiago Soalheiro Diamantino - RM 569316

Kauan Damasceno de Lima - RM 573727
