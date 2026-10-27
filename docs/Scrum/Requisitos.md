# Requisitos do Sistema

## Identificação do Projeto

- **Projeto:** SAM Controle
- **Organização fictícia:** oficina de manutenção de equipamentos (motosserras, roçadeiras, sopradores e similares), fictícia e baseada na oficina Samaquinas e Motores
- **Tipo de sistema:** sistema de gestão de clientes, equipamentos e fichas de serviço
- **Linguagem de programação:** C
- **Interface:** terminal/console
- **Objetivo:** organizar o cadastro de clientes, o registro dos equipamentos e das fichas de serviço da oficina, mantendo o histórico de manutenção de cada equipamento acessível e substituindo as anotações em papel.

## Escopo do Sistema

O sistema cobre o login com controle de acesso por nível de usuário, o cadastro e a gestão de usuários (somente administrador), o cadastro, a consulta, a alteração e a exclusão de clientes, o cadastro de equipamentos vinculados aos clientes, o registro de fichas de serviço (quantidade, descrição e preço final) e a consulta do histórico de serviços por cliente e por equipamento.

O sistema não cobre, nesta versão: controle de estoque de peças, geração de relatórios, pedidos de compra a fornecedores e armazenamento em banco de dados. A migração para um banco de dados está prevista como evolução futura.

Principais restrições técnicas: o sistema é desenvolvido em linguagem C, com programação estruturada, e armazena seus dados em arquivos de texto (`.txt`).

## Problema Identificado

Na oficina, o histórico de manutenção dos equipamentos era anotado em papel. Isso dificultava localizar o que já tinha sido feito em cada equipamento, aumentava o risco de perda de informações e obrigava os funcionários a depender da memória ou de registros dispersos para atender o cliente e diagnosticar o problema. O sistema deve centralizar clientes, equipamentos e serviços em um só lugar, de forma organizada e consultável.

## Hierarquia de Usuários

### Administrador

  Proprietário ou responsável pela oficina. Possui todas as permissões do atendente e, além delas, pode registrar e consultar usuários do sistema (opção "Gerenciar Usuários"). Essa opção não é exibida para usuários de nível atendente.

### Atendente

Funcionário que opera o sistema no dia a dia. Pode gerenciar clientes (cadastrar, consultar, alterar e excluir), cadastrar os equipamentos dos clientes e registrar e consultar fichas de serviço. Não tem acesso ao gerenciamento de usuários.

### Cliente

Dono do equipamento. Quando o portal do cliente estiver disponível, poderá consultar apenas o histórico de fichas de serviço finalizadas dos seus próprios equipamentos.

## Requisitos Funcionais

**RF05: Gerenciar Usuários** O sistema deve permitir o login com usuário e senha, identificando o nível de acesso (administrador ou atendente). Somente o administrador pode cadastrar novos usuários (nome, login único, senha e nível de acesso) e consultar os já cadastrados, sem exibir a senha.

**RF01: Cadastro de Clientes** O sistema deve permitir que o atendente realize o cadastro de novos clientes informando nome, CPF e número de telefone (dados obrigatórios), além de possibilitar a consulta, alteração e exclusão desses cadastros.

**RF02: Cadastro de Equipamentos** O sistema deve permitir o cadastro de equipamentos vinculados a um cliente, registrando o tipo (ex.: motosserra, roçadeira, soprador), a marca e o modelo.

**RF03: Registro de Ficha de Serviço** O sistema deve permitir o registro de uma ficha de serviço para um equipamento previamente cadastrado, contendo a descrição do serviço solicitado, observações e o preço final.

**RF04: Consulta e Histórico de Clientes e Equipamentos** O sistema deve permitir que o atendente localize clientes por nome ou telefone e consulte os equipamentos vinculados a eles. Também deverá permitir a consulta do histórico de serviços de cada equipamento, incluindo serviços realizados, orçamentos e preços, utilizando como filtros o número de identificação, tipo, marca ou modelo do equipamento.

## Requisitos Não Funcionais

**RNF01:** Segurança. O sistema deve implementar controle de acesso baseado em papéis (RBAC), garantindo que os clientes autenticados visualizem exclusivamente o histórico de fichas de serviço finalizadas de seus próprios equipamentos.

**RNF02:** Usabilidade. O sistema deve apresentar uma interface organizada e intuitiva, permitindo que novas tarefas de cadastro e consulta sejam executadas com o menor número de passos possível e curva de aprendizado rápida.

**RNF03:** Desempenho. O tempo de resposta do sistema para operações de cadastro, alteração e carregamento de consultas nos arquivos de dados não deve ultrapassar 3 segundos em condições normais de uso.

**RNF04:** Integridade dos dados. O sistema deve assegurar a consistência entre clientes, equipamentos e fichas de serviço, impedindo exclusões acidentais que deixem registros órfãos ou inconsistentes.

## Regras de Negócio

- **RN01:** Não pode haver dois clientes com o mesmo CPF. O sistema deve verificar a duplicidade antes de concluir o cadastro.
- **RN02:** O CPF informado deve ser válido antes de o cliente ser cadastrado ou localizado.
- **RN03:** Todo equipamento deve estar vinculado a um cliente já cadastrado, e o número de série é gerado automaticamente pelo sistema.
- **RN04:** Uma ficha de serviço só pode ser registrada para um equipamento previamente cadastrado.
- **RN05:** Somente usuários com nível de administrador podem registrar novos usuários.
- **RN06:** Não pode haver dois usuários com o mesmo login.
- **RN07:** Um cliente só pode consultar as fichas de serviço finalizadas dos seus próprios equipamentos.
- **RN08:** O acesso às funcionalidades depende do login e do nível de acesso do usuário.
- **RN09:** Os dados do sistema são gravados em arquivos de texto (`.txt`), mantendo clientes, equipamentos e fichas de serviço relacionados entre si.
