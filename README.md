# SAM Controle

Sistema desktop de console em linguagem C para gestão de clientes, equipamentos e serviços da oficina SAMáquinas e Motores, desenvolvido como Projeto Integrado Multidisciplinar (PIM II) do curso de Análise e Desenvolvimento de Sistemas da UNIP.

## Como executar

1. Compile dentro da pasta `SamControle` (Windows, com MinGW/GCC, Dev-C++ ou Code::Blocks):
   ```bash
   cd SamControle
   gcc *.c -o sam_controle.exe
   ```
   Também é possível usar o `sam_controle.exe` já incluído na pasta.
2. Execute **de dentro da pasta `SamControle`**, pois os dados ficam em `dados/`:
   ```bash
   sam_controle.exe
   ```
3. Acesse o menu `1. Gerenciar Usuarios` e faça login com o usuário `admin`, senha `1234` (Administrador).
4. Use os menus numerados para gerenciar usuários, clientes, equipamentos e serviços. Digite os campos de texto sem espaços (use `_`).

## Documentação

| Documento | Conteúdo |
|---|---|
| [01-requisitos.md](./docs/scrum/01-requisitos.md) | Fonte oficial dos requisitos (RF, RNF, RN) |
| [02-product-backlog.md](./docs/scrum/02-product-backlog.md) | Backlog do produto, ligado aos requisitos e às sprints |
| [03-user-stories.md](./docs/scrum/03-user-stories.md) | User stories detalhando cada item do backlog |
| [04-definition-of-done.md](./docs/scrum/04-definition-of-done.md) | Definition of Done da equipe |
| [sprints/](./docs/scrum/sprints/) | Um documento por Sprint (objetivo, tarefas, review, retrospectiva) |

Documentação acadêmica completa (Word/PDF) em [`docs/manual-pim-II/`](./docs/manual-pim-II/).

### Integrantes do grupo

| Papel | Nome | RA |
|---|---|---|
| P.O | Samuel de Oliveira Júnior | R318JE0 |
| S.M | Geovana Ferreira Mira | R314685 |
| Dev | Ana Júlia Tenório Pedroso | R277933 |
| Dev | Diogo Issao Andrade Okuda | H967GH9 |
| Dev | Gustavo Paiva de Oliveira | R240IE4 |
| Dev | João Vitor Soares de Moraes | R344290 |
