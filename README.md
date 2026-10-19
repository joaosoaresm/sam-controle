# SAM Controle
 
Sistema desktop (console) em linguagem C para **gestão de clientes, equipamentos e serviços** da oficina **SAMáquinas e Motores**, em São José dos Campos.
 
Projeto Integrado Multidisciplinar (PIM II) do curso de Análise e Desenvolvimento de Sistemas da UNIP. Equipe **DevTime**.
 
---
 
## O problema
 
Na oficina, o histórico de manutenção de cada máquina (motosserras, roçadeiras, sopradores…) era anotado em papel. Isso tornava lenta a consulta do que já foi feito em um equipamento e trazia risco de perder os registros.
 
O **SAM Controle** centraliza essas informações. Ele liga cada **cliente** (CPF) aos seus **equipamentos** (número de série) e cada equipamento ao seu **histórico de serviços**.
 
## Funcionalidades
 
Menu principal:
 
```
1. Gerenciar Usuarios
2. Gerenciar Clientes
3. Gerenciar Equipamentos
4. Gerenciar Servicos
0. Sair
```
 
| Módulo | Funcionalidades | Acesso |
|---|---|---|
| Usuários | Login, cadastro de novos usuários e encerramento de sessão | Cadastro somente para Administrador |
| Clientes | Consultar, cadastrar e excluir cliente por CPF (não aceita CPF repetido) | Exige login |
| Equipamentos | Cadastrar máquina vinculada ao CPF do cliente, com número de série gerado automaticamente, e listar as máquinas de um cliente | Exige login |
| Serviços | Registrar ficha de serviço (descrição, observações e preço) para uma máquina e consultar o histórico pelo número de série | — |
 
Perfis de usuário: **1 – Administrador** e **2 – Atendente**.
 
## Estrutura do projeto
 
O sistema é **modularizado**: cada módulo tem um arquivo `.c` (implementação) e um `.h` (cabeçalho com as declarações).
 
```
SamControle/
├── main.c              # menu principal e variável de sessão (perfil logado)
├── usuarios.c / .h     # login, cadastro de usuários e logout
├── clientes.c / .h     # cadastro, consulta e exclusão de clientes
├── equipamentos.c / .h # cadastro e consulta de máquinas, nº de série
├── servicos.c / .h     # fichas de serviço e histórico por máquina
├── login.c / .h        # reservados (ainda vazios)
├── sam_controle.exe    # executável compilado para Windows
└── dados/              # arquivos onde as informações ficam salvas
    ├── usuarios.txt      login senha perfil
    ├── clientes.txt      nome telefone cpf
    ├── equipamentos.txt  cpf nroSerie tipo marca modelo
    └── servicos.txt      cpf nroSerie descricao observacoes preco
```
 
### Modelo de dados
 
```
Cliente (cpf) 1 ──── 0..* Equipamento (numeroSerie) 1 ──── 0..* Servico
```
 
## Como compilar e executar
 
**Requisitos:** Windows com um compilador C (MinGW/GCC, Dev-C++ ou Code::Blocks). O `main.c` inclui `windows.h`.
 
```bash
cd SamControle
gcc *.c -o sam_controle.exe
sam_controle.exe
```
 
Também é possível executar diretamente o `sam_controle.exe` já incluído na pasta.
 
> Execute o programa **de dentro da pasta `SamControle`**, pois os dados são lidos e gravados em `dados/`, um caminho relativo a ela.
 
**Acesso inicial:** usuário `admin`, senha `1234` (Administrador).
 
### Roteiro rápido de uso
 
1. `1` Usuários → `1` Login → `admin` / `1234` → `0` voltar
2. `2` Clientes → `2` Cadastrar → `Joao` `12999990000` `12345678900`
3. `3` Equipamentos → `1` Cadastrar → CPF `12345678900`, `Motosserra` `Stihl` `MS170`
4. `4` Serviços → `1` Registrar → CPF, nº de série `1`, `Troca_de_corrente` `Afiada` `150`
5. `4` Serviços → `2` Consultar → nº de série `1` → mostra o histórico da máquina
> Digite os campos de texto **sem espaços** (use `_` no lugar), pois as colunas dos arquivos `.txt` são separadas por espaço.
 
## Próximos passos
 
- Exigir login também no módulo de Serviços
- Adicionar ao menu a consulta do cliente pelo CPF (função `portalClienteServicos()`, já implementada)
- Tratar entradas não numéricas nos menus
- Criar um `.gitignore` e retirar do versionamento o executável e os arquivos de dados
- Persistência em **MySQL** (Connector/C), como previsto na modelagem de banco do PIM
- Senhas com hash e bloqueio após tentativas inválidas (LGPD / ISO 27001)
- Controle de estoque de peças e relatórios para o proprietário
## Equipe
 
Projeto desenvolvido com a metodologia **Scrum**.
 
| Papel | Integrante |
|---|---|
| Product Owner (PO) | Samuel de Oliveira Júnior |
| Scrum Master | Geovana Ferreira Mira |
 
**Dev Team**
 
- Ana Júlia Tenório Pedroso
- Diogo Issao Andrade Okuda
- Gustavo Paiva de Oliveira
- João Vitor Soares de Moraes
