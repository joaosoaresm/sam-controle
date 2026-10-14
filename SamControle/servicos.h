#ifndef SERVICOS_H
#define SERVICOS_H

typedef struct {
    char cpfCliente[20];      // Vínculo com o cliente
    int numeroSerieEquipamento; // ID da máquina associada
    char descricao[100];      // Descrição do serviço solicitado
    char observacoes[100];    // Observações técnicas
    float precoFinal;         // Preço da manutenção/serviço
} Servico;

// Funções principais do módulo de serviços
void menuServicos();          // Menu do atendente (Registar e gerir)
void portalClienteServicos(); // Menu para o cliente consultar os seus aparelhos e serviços

#endif