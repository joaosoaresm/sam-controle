#include <stdio.h>
#include <string.h>
#include "servicos.h"
#include "equipamentos.h" // Inclui os equipamentos e, por consequência, a função de validação de cliente se estiver partilhada ou podes declará-la abaixo:

// Declaração do protótipo caso o compilador não encontre no equipamentos.h
int clienteExiste(char *cpfBuscado);
void salvarServico(Servico s) {
    FILE *arquivo = fopen("dados/servicos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s %d %s %s %.2f\n", s.cpfCliente, s.numeroSerieEquipamento, s.descricao, s.observacoes, s.precoFinal);
        fclose(arquivo);
    }
}

// 1. Registo de Serviço pelo Atendente (vinculado ao CPF e à máquina)
void menuServicos() {
    int opcao;
    Servico s;

    do {
        printf("\n===============================\n");
        printf("      MODULO DE SERVICOS       \n");
        printf("===============================\n");
        printf("1. Registar Ficha de Servico\n");
        printf("2. Consultar Servicos por Equipamento (Nro Serie)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("----------------------------------------\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Entrada invalida!\n");
            while (getchar() != '\n');
            continue;
        }

        switch(opcao) {
            case 1:
                {
                    printf("\n--- NOVO REGISTO DE SERVICO ---\n");
                    printf("CPF do Cliente Proprietario: ");
                    scanf("%s", s.cpfCliente);

                    // Valida se o cliente existe
                    if (!clienteExiste(s.cpfCliente)) {
                        printf("\n[ERRO] Cliente com o CPF '%s' nao encontrado!\n", s.cpfCliente);
                        break;
                    }

                    // Mostra as máquinas deste cliente para ajudar o atendente a escolher o Nro de Série
                    FILE *arqEq = fopen("dados/equipamentos.txt", "r");
                    if (arqEq == NULL) {
                        printf("\n[ERRO] Nao existem equipamentos registados no sistema.\n");
                        break;
                    }

                    char cpfLido[20], tipoLido[30], marcaLido[30], modeloLido[40], linha[256];
                    int serieLido, encontradas = 0;

                    printf("\n--- Maquinas do Cliente (CPF: %s) ---\n", s.cpfCliente);
                    while (fgets(linha, sizeof(linha), arqEq) != NULL) {
                        if (sscanf(linha, "%s %d %s %s %s", cpfLido, &serieLido, tipoLido, marcaLido, modeloLido) >= 5) {
                            if (strcmp(cpfLido, s.cpfCliente) == 0) {
                                printf("-> Nro Serie: [%d] | Tipo: %s | Marca: %s | Modelo: %s\n", serieLido, tipoLido, marcaLido, modeloLido);
                                encontradas++;
                            }
                        }
                    }
                    fclose(arqEq);

                    if (encontradas == 0) {
                        printf("[AVISO] Este cliente nao possui maquinas registadas. Cadastre uma maquina primeiro.\n");
                        break;
                    }

                    printf("\nDigite o Numero de Serie da maquina para o servico: ");
                    scanf("%d", &s.numeroSerieEquipamento);

                    printf("Descricao do Servico (ex: Troca_de_correia): ");
                    scanf("%s", s.descricao);
                    printf("Observacoes Tecnicas (ex: Sem_gasolina): ");
                    scanf("%s", s.observacoes);
                    printf("Preco Final (R$): ");
                    scanf("%f", &s.precoFinal);

                    salvarServico(s);
                    printf("\n[SUCESSO] Ficha de servico registada para a maquina [%d]!\n", s.numeroSerieEquipamento);
                }
                break;

            case 2:
                {
                    int serieBusca;
                    printf("\n--- CONSULTAR SERVICOS POR NUMERO DE SERIE ---\n");
                    printf("Digite o Numero de Serie do equipamento: ");
                    scanf("%d", &serieBusca);

                    FILE *arquivo = fopen("dados/servicos.txt", "r");
                    if (arquivo == NULL) {
                        printf("\n[INFO] Nenhum servico registado no sistema.\n");
                        break;
                    }

                    char linha[256];
                    Servico sLido;
                    int count = 0;

                    printf("\n--- HISTORICO DE SERVICOS DA MAQUINA [%d] ---\n", serieBusca);
                    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                        if (sscanf(linha, "%s %d %s %s %f", sLido.cpfCliente, &sLido.numeroSerieEquipamento, sLido.descricao, sLido.observacoes, &sLido.precoFinal) >= 5) {
                            if (sLido.numeroSerieEquipamento == serieBusca) {
                                printf("Servico: %s | Obs: %s | Preco: R$ %.2f\n", sLido.descricao, sLido.observacoes, sLido.precoFinal);
                                count++;
                            }
                        }
                    }
                    fclose(arquivo);

                    if (count == 0) {
                        printf("[INFO] Nenhum historico de servico encontrado para este equipamento.\n");
                    }
                }
                break;

            case 0:
                printf("\nA retornar...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
}

// 2. Portal do Cliente: Consulta exclusiva das suas máquinas e serviços informando o CPF
void portalClienteServicos() {
    char cpfCliente[20];
    printf("\n===========================================\n");
    printf("     PORTAL DE CONSULTA DO CLIENTE         \n");
    printf("===========================================\n");
    printf("Digite o seu CPF para ver as suas maquinas: ");
    scanf("%s", cpfCliente);

    if (!clienteExiste(cpfCliente)) {
        printf("\n[ERRO] CPF nao encontrado no sistema.\n");
        return;
    }

    FILE *arqEq = fopen("dados/equipamentos.txt", "r");
    if (arqEq == NULL) {
        printf("\n[INFO] Nao existem equipamentos registados.\n");
        return;
    }

    char linha[256], cpfLido[20], tipo[30], marca[30], modelo[40];
    int serie, temEquipamentos = 0;

    printf("\n========================================\n");
    printf("   OS SEUS APARELHOS E SERVICOS (CPF: %s)\n", cpfCliente);
    printf("========================================\n");

    while (fgets(linha, sizeof(linha), arqEq) != NULL) {
        if (sscanf(linha, "%s %d %s %s %s", cpfLido, &serie, tipo, marca, modelo) >= 5) {
            if (strcmp(cpfLido, cpfCliente) == 0) {
                temEquipamentos = 1;
                printf("\n[Maquina #%d] %s %s %s\n", serie, marca, modelo, tipo);
                
                // Procura os serviços desta máquina específica
                FILE *arqServ = fopen("dados/servicos.txt", "r");
                if (arqServ != NULL) {
                    char linhaServ[256];
                    Servico serv;
                    int temServico = 0;

                    while (fgets(linhaServ, sizeof(linhaServ), arqServ) != NULL) {
                        if (sscanf(linhaServ, "%s %d %s %s %f", serv.cpfCliente, &serv.numeroSerieEquipamento, serv.descricao, serv.observacoes, &serv.precoFinal) >= 5) {
                            if (serv.numeroSerieEquipamento == serie) {
                                printf("   -> Servico: %s | Obs: %s | Preco: R$ %.2f\n", serv.descricao, serv.observacoes, serv.precoFinal);
                                temServico = 1;
                            }
                        }
                    }
                    fclose(arqServ);
                    if (!temServico) {
                        printf("   -> Nenhum servico registado para este aparelho.\n");
                    }
                }
            }
        }
    }
    fclose(arqEq);

    if (!temEquipamentos) {
        printf("[INFO] Nao existem equipamentos associados a este CPF.\n");
    }
    printf("----------------------------------------\n");
}