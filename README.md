# projeto-final
projeto final LAB1

1.Descrição do Projeto
O campeonato mundial de Moto GP necessita de um programa que permita a gestão
mais eficiente dos testes que serão realizados para a próxima temporada, pois a
expansão cada vez maior no uso de recursos tecnológicos tem proporcionado um
aumento substancial na evolução dos pilotos. Por isso, você foi contratado para
elaborar um programa que deverá atender a todos os aspectos relacionados a esta
situação, tratando as seguintes informações:
• Piloto, deverá conter os dados abaixo:
  - Código de identificação único (valor único entre 0 e 100), no momento do
    cadastro serão apresentados 3 números simultaneamente para que seja
    escolhido um número dentre os apresentados para o piloto.
  - Nome completo;
  - Sigla da Equipe (três letras maiúsculas);
  - Data de nascimento no formato dd/mm/aaaa
  - Sexo (m-masculino ou f-feminino);
  - País de origem (nome do país);
• Equipe, deverá conter os dados abaixo:
  - Nome da equipe (ex: Red Bull KTM Factory Racing);
  - Sigla (ex: KTM), máximo 3 letras;
  - País de origem (nome do país);
• Circuito, deverá conter os dados abaixo:
  - Código sequencial único gerado automaticamente com base no último
    circuito registrado no arquivo
  - Nome do circuito (pista)
  - País do circuito (nome do país)
  - Tamanho do circuito em quilômetros (valor real)
  - Menor Tempo do Circuito (tempo recorde em minutos, segundos,
    milisegundos). Este valor deverá ser atualizado sempre que um piloto
    realizar uma volta melhor do que a anteriormente cadastrada.
  - Identificação do piloto que obteve o menor tempo do circuito;
• Melhor Volta: identifica a melhor volta de um piloto em uma data em um circuito:
  - Identificação do piloto
  - Identificação do circuito
  - Equipe do Piloto;
  - Data da volta com dia, mês e ano fornecida pelo usuário, devendo ser
    validada para o tratamento de anos bissextos. A menor data a ser
    cadastrada deve ser 04/06/2017, obrigatoriamente deverá ser domingo e
    não maior que a data atual.
  - Tempo da melhor volta em minutos, segundos e milissegundos;
 Obs.: Só deverá existir um único registro para um piloto em um circuito em uma data.
Um piloto poderá realizar várias melhores voltas em um circuito desde que sejam em
dias diferentes.

  Para a padronização dos nomes dos países, existirá um arquivo texto de nome
“paises.txt”, que deverá conter os nomes dos 10 possíveis países relacionados ao
campeonato, assim como, as siglas (duas letras) de cada país, EX: BR, FR, UK. No
cadastramento/alteração de um piloto ou Circuito só poderão ser utilizados os países
previamente cadastrados neste arquivo.

2.Implementação das Funcionalidades
2.1 Gerenciamento e controle dos dados cadastrais
Dados Cadastrais dos Pilotos
• Inclusão de um novo piloto, tomando-se o devido cuidado de não permitir o
  recadastramento de um piloto(código) já existente;
• Alteração/complementação dos dados cadastrais dos pilotos existentes,
  tomando-se o devido cuidado de não permitir o recadastramento de um
  piloto já existente;
• Exclusão de um piloto do cadastro: só será permitida se o piloto não tiver
  realizado nenhuma volta. O usuário deverá confirmar a exclusão.
Dados Cadastrais das Equipes
• Inclusão de uma nova equipe, tomando-se o devido cuidado de não permitir
  o recadastramento de uma equipe já existente (mesma sigla);
• Exclusão de uma equipes: só será permitida se a equipe não tiver nenhum
  piloto cadastrado. O usuário deverá confirmar a exclusão.
  Dados Cadastrais dos Circuitos
• Inclusão de um novo circuito, tomando-se o devido cuidado de não permitir o
  recadastramento de um circuito já existente;
• Alteração dos dados cadastrais dos circuitos existentes, tomando-se o
  devido cuidado de não permitir o recadastramento de um circuito já
  existente;
Dados Cadastrais das Voltas
• Inclusão da melhor volta em um circuito de um piloto fornecido pelo usuário;
• Alteração dos dados cadastrais da volta rápida de um piloto em um circuito e
  em uma data, quando esta volta já existir cadastrada e necessitar de alguma
  correção ou mudança;
• Exclusão da volta rápida de um piloto em um circuito após confirmação do
  usuário;
2.2 Relatórios
• (R1). Consulta simples sobre todos os arquivos existentes através da sua
  chave única ou apresentar todos os dados cadastrados;
• (R2). Pesquisar os pilotos registrados em seu programa pelo nome. Esta
  pesquisa ocorrerá por qualquer parte do nome do piloto. No caso de
  existirem vários pilotos que satisfaçam a esta parte do nome, deverá ser
  mostrada uma tabela ordenada, alfabeticamente, com os dados cadastrados
  para cada piloto (mostrar todos seus dados cadastrais de forma tabelar com
  uma única linha de cabeçalho, devendo as colunas serem identificadas por
  extenso).
• (R3). Relacionar todos os pilotos que realizaram voltas em um circuito
  específico fornecido pelo usuário, indicando todos os dados relacionados
  com a sua volta rápida realizada neste circuito. O usuário poderá também
  definir, além do circuito, uma data válida e completa para fazer esta
  consulta.
• (R4). Consultar todos os circuitos cadastrados por qualquer parte de seu
  nome que será fornecido pelo usuário ou por seu código (chave), onde todos
  os dados de cadastro dos circuitos deverão ser mostrados de maneira
  tabelar, com somente uma linha de cabeçalho. Esta consulta só poderá ser
  realizada usando recursos de alocação dinâmica (ver esclarecimentos no
  tópico PESQUISA-1 a seguir). Junto com os dados do circuito deverá ser
  apresentado o nome completo do piloto que obteve o menor tempo do
  circuito;
• (R5). Apresentar todos os pilotos de uma equipe em um período de data
  (de... até...) completa (dia/mês/ano) fornecido pelo usuário, onde será
  mostrado somente o nome e código do piloto, a data em que o piloto realizou
  volta por tal equipe e o nome do circuito onde isto ocorreu. A apresentação
  deverá estar em ordem alfabética de piloto.
• (R6). Pesquisar todos os pilotos, equipes e circuitos que realizaram um
  tempo de volta menor ou igual ao fornecido pelo usuário (minutos, segundos
  e milissegundos).
• (R7). Exibir todos os Pilotos, Equipes ou Circuitos que não estão
  cadastrados em nenhuma Melhor Volta.

PESQUISA-1: Pesquisa dos dados dos Circuitos cadastrados pelo nome. Esta
pesquisa ocorrerá por qualquer parte do nome do circuito que será fornecido pelo
usuário. No caso de existir vários circuitos que satisfaçam a esta pesquisa, deverá
ser apresentada uma tabela ordenada alfabeticamente pelo nome do circuito com
os dados dos mesmos, recuperados somente por meio de um processo de
alocação dinâmica.

PESQUISA-2: Tendo como filtro inicial a equipe. No relatório sintético (R8)
deverão conter os seguintes dados em forma de tabela:
  Idade do piloto (será calculada com base na data de nascimento do piloto e data
    do sistema, podendo ser ordenado de forma crescente/decrescente), número de
    melhores voltas do piloto (podendo ser ordenado de forma
    crescente/decrescente), nome do piloto por ordem alfabética (podendo ser
    ordenado de A-Z ou Z-A). Após a exibição do relatório sintético o usuário poderá
    selecionar dentre um dos resultados (pilotos) para exibição do relatório analítico
  (R9) contendo: todas as melhores voltas do piloto, o circuito e data, quantidade de
    dias faltavam para o aniversário do piloto naquele ano (inclusive considerando se
    no ano fevereiro tem 29 dias), ou se já havia sido comemorada a data natalícia do
    piloto no respectivo ano. Os parâmetros do último relatório sintético (R8) emitido
    deverão sempre ser armazenados em um arquivo (r8.txt) para que o relatório seja
    exibido de forma imediata no menu principal pela opção “Exibir último relatório
    sintético”.

Navegação
2.3. Principais características do programa
• Para a alteração ou exclusão de uma informação existente, o usuário poderá
  fornecer parte da mesma, sendo então apresentadas as informações que
  satisfaçam a esta seleção;
  
• Todas as pesquisas realizadas não devem ser sensitivas a maiúsculas e
  minúsculas, no entanto, os dados digitados pelo usuário devem ser mantidos
  na sua forma original, ou seja, não podem ser alterados;
  
• O programa principal deverá conter apenas a apresentação de um menu de
  opções para a escolha do usuário e a chamada das funções
  correspondentes para manipulação;
  
• Todos os dados para as funções deverão ser passados como parâmetros,
  não sendo permitido o uso de variáveis globais;
  
• Os dados deverão ser armazenados em arquivos sequenciais para
  possibilitar a reutilização posterior dos mesmos. As manipulações dos dados
  necessários em memória deverão ser realizadas usando-se alocação
  dinâmica na pesquisa identificada como PESQUISA 1, ou seja, a
  memória necessária para manipulação dos dados desta pesquisa
  (consulta), esclarecida anteriormente, deverá acontecer somente
  através da alocação dinâmica, caso contrário não será considerada
  como implementada;
  
• Os dados deverão ser armazenados em arquivos binários, devendo existir
  pelo menos 3 arquivos: uma para guardar os dados cadastrais dos Pilotos,
  outro para guardar os dados cadastrais dos Circuitos e outro para o registro
  das Voltas dos pilotos em circuitos específicos e existentes (já cadastrados).
  A manipulação dos dados nestes arquivos de dados só acontecerá por
  registros (blocos de dados).
  
• Validações, completude na implementação dos formulários e qualidade
  visual (entradas e saídas, tabelas) serão seguramente consideradas.
