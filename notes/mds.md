# Métodos de Desenvolvimento de Software - Anotações

Minhas anotações sobre a matéria Métodos de Desenvolvimento de Software.

## Terça 08/09

História de usuário X Casos de uso -> estariamos ainda escrevendo requisitos

Nosso processo é fundamentalmente ágil mas usamos artefatos do RUP

## Quinta 10/09

Problemas das metodologias tradicionais:
 - Predição: Tentar prever escopo, estimativas, comportamento para simulação;
 - Pouca interação com o cliente:
 	* Foi resolvido com o RUP?
 	-> No final de uma iteração deseja-se ter uma versão do produto.
 - Burocráticos?
	-> Rigidez das fases, assemelhando à manufatura;
 - Código fonte é mais um artefato.
	-> Desapegar do código :(
	-> Pode ser mudado radicalmente de uma semana para outra

Uma das mudanças mais notáveis na forma de pensar desenvolvimento de soft nos ultimos 15 anos Acordo Ágil

O Acordo Ágil:
 - O porquê - Abraçar mudanças
 - Manifesto Ágil - 4 Valores
 - O que - 12 Princípios
 - Como - Métodos Ágeis

Time-to-market: Tempo ideal para conseguir lançar um produto no mercado. Concorrência!

O Manifesto Ágil: Manifesto para o desenvolvimento ágil de software

Encontrar balanço entre Software em funcionamento e documentação abrangente

## Terça 15/09

- Por que poucos valores no manifesto ágil?
- Qual o papel das pessoas nesses 4 valores?

**Princípio do manifesto ágil:**

**Objetivo:** satisfazer o cliente entregando com frequência, sistemas com algum valor de negócio, "rodando em produção".

- Entregar **versões funcionais** em **prazos curtos e frequente**;

- **Mudanças** são um aspecto intrínseco da vida do software (pode ser requisitos, processos etc);

- Software evolui para **atender ao negócio** (união dos mundos), esse é o motivo principal para o software evoluir;

- Troca de informações através de conversas diretas.

**Príncipios por trás do manifesto ágil**

- Nossa maior prioridade é satisfazer o cliente, através da entrega adiantada e contínua de software de valor. **entrega contínua**

- Aceitar mudanças de requisitos mesmo no fim do desenvolvimento. Processos ágeis se adequam a mudanças, para que o cliente possa tirar vantagens competitivas.

- Entregar software funcionando com frequência, na escala de semanas até meses, com preferência aos períodos mais curtos.

O que é software funcionando? Como garantir que o produto desenvolvido faz o que precisa ser feito? Com testes!

- Pessoas relacionadas à negócios e desenvolvedores devem trabalhar em conjunto e diariamente, durante todo o curso do projeto. """ Este diariamente não é no sentidido literal, o recado importante é que o usuário deve estar junto com a equipde de desenvolvimento, com isso ele abraça mais o time, o projeto e proporciona a colaboração."""

- Construir projetos ao redor de indivíduos motivados. Dando a eles o ambiente e suporte necessário, e **confiar** que farão seu trabalho. É necessário instigar a confiança e dar liberadade para o membro do time errar, mas que erre a partir de uma discussão e um entendimento feito com o time. 

O que desmotiva num desenvolvimento de software?

- O método mais eficiente e eficaz de transmitir informações para, e por dentro de um time de desenvolvimento, é através de uma conversa **cara a cara** (papo reto). Dar feedbacks e reconhecer erros a partir de conversas francas e procurar melhorar.

É necessário criar uma relação de companherismo e profissionalismo em prol de um objetivo em comum.

- **Software funcional** é a medida primário de progresso. O que da mais satisfação para o cliente é um software funcional para utilizar.

- Processos ágeis promovem um ambiente sustentável. Os patrocinadores, desenvolvedores e usuários devem ser capazes de manter indefinidamente, passos constantes.

- Contínua atenção à excelência técnica e bom design, aumenta a agilidade.

- Simplicidade: a arte de maximizar a quantidade de trabalho que não precisou ser feito

- As melhores arquiteturas, requisitos e designs emergem de times auto-organizáveis

- Em intervalos regulares, o time reflete em como ficar mais efetivo, então, se ajustam e otimizam seu comportamento de acordo

Qual o tempo para entregar uma funcionalidade? 1 semana, devido ao tempo de uma sprint.

O que acontece se uma funcionalidade foi implementada no início de uma sprint? É necessário aguardar ate o final da mesma.

Estamos delimitados pelo ciclo da sprint.

Métodos Ágeis propõem o achatamento da curva de custo de mudanças em relação ao tempo.

## Quinta 17/09

O processo empírico:

- Visibilidade;
- Inspeção;
- Adaptação -> Palavra que mais define a Metodologia Ágil, deve-se abraçar as mudanças e desapegar do código fonte.

RUP não é flexivel, não da pra adaptar muito para suas necessidades.

A visibilidade significa que aspectos do processo que afeta suas saídas deve, ser percebidas por aqueles que controlam o processo

Uma funcionalidade **"pronta"**, significa:
- Claramente projetada e codificada;
- Refatorada;
- Suite de testes automatizados (unitário, funcional,...);
- Testes de aceitação;
- Disponibilizada para uso em abiente de operação/produção.

Pronto para metodos ágeis é rodando na mão do usuário.

![Extreme Programming](http://www.extremeprogramming.org/)
![XP Project](http://www.extremeprogramming.org/map/project.html)

Engenheiro de Software que deve dizer as condições de limite e as melhores soluções para cada caso.

## Terça 29/09

**Extreme Programming XP**

### Origens

- Kent Back
	- Extreme Programming eXplained
- Don Wells
	- Extreme Programming Perspectives
- Destaque no OOPSLA 2000 (Splash: Conferência importante de programação)
- O Case da Chrysler

### Características

- Para pequenos grupos
- Para quem gosta de programar

### Valores

- Simplicidade -> Fazer um código simples e ir refatorando, como uma arquitetura robusta que suporta o desenvolvimento que está por vir
- Feedback -> Comentar issue, etc
- Respeito -> Não precisa ter amizade, mas respeito sempre
- Comunicação -> Parear, ter contato humano
- Coragem

### As quatro variáveis

O XP considera **quatro** as variáveis que estão presentes no desenvolvimento de um projeto (BECK, 2000):

- Prioridade
- Qualidade
- Custo
- Tempo

### Interação entre as quatro variáveis

- As variáveis **custo e tempo** normalmente são decisão do **cliente**, pois é dele a decisão sobre quando precisa do sistema implementado e qual o valor que está disposto a pagar por isto.
- A variável qualidade não deve ser sacrificada/negociada!
- Portanto, escopo aberto!
	- Isto deve ficar claro desde o início do projeto, tanto para o cliente quanto para o time.

### Papéis no XP

#### Coach
- Garante as regras do jogo (XP)
- Normalmente o mais eXPeriente do grupo
- Identifica quem é bom no que
- Eventualmente compõe o pareamento
- Não desenha a arquitetura, apenas chama atenção para oportunidades de melhora
- Seu papel diminui à medida em que o time fica mais maduro

### Tracker
- Realiza medições no projeto
	- Velocidade
	- % cobertura de testes
	- n. de testes funcionais definidos e funcionando
	- n. de classes, métodos, LOC
	- ...
- Mantém o histórico de progresso
- Promove a discussão com o time de desenvolvimento

### Time Desenv.
- Planeja, escreve e executa testes automatizados
- Integra o código-fonte ao respositório
- Modifica o projeto e a implementação de forma incremental, baseado na funcionalidade escolhida pelo cliente

## Quinta 01/10

### As 12 Práticas do XP
❌
1. ✅ Planejamento
2. ✅ Fases Pequenas (Releases Curtas)
3. ± Metáfora (Arquitetural)
4. ❓ Projeto (Design) Simples
5. ✅ Testes
6. ❓ Refatoração
7. ✅ Programação em Pares
8. ✅ Propriedade Coletiva co Código
9. ± Integração Contínua
10. ✅ Semana de 40 horas
11. ✅ Cliente junto aos desenvolvedores
12. ✅ Padronização do código

O **projeto** acaba no último dia de aula, e o **produto** depende do time. É possível continuar o produto após a disciplina.

## Terça 13/10

[ESEM](https://www.youtube.com/channel/UC58L7oO99Sawi2c_d6XYyGQ/videos)

Cibse
- [Geral](http://cibse2020.ppgia.pucpr.br/index.php/en-us/)
- [Inscrição](https://pucpr.co1.qualtrics.com/jfe/form/SV_agELhKOd0wg6QZf)

### Programação em pares (Prática do XP)

- Erro de um detectado imediatamente pelo outro (grande economia de tempo)
- Maior diversidade de ideias, técnicas e algoritmos
- Enquanto um escreve, o outro pensa em contra-exemplos, problemas de eficiência, etc
- Vergonha de escrever código feio (gambiarra) na frente do seu par
- Pareamento de acordo com especialidades
- Experimentos controlados mostraram que a qualidade do código produzido aumenta sem perda de velocidade (Laurie Williams)

Programando sozinho:
- Ficamos em um estado de hiperfoco
- Programação é uma atividade intensa congnitiva

### Propriedade Coletiva de Código

- Modelo tradicional: só autor de uma função pode modificá-la
- XP: o código pertence a todos
- Se alguém identifica uma oportunidade para simplificar, consertar ou melhorar código escrito por outra pessoa, que o faça
- Mas rode os testes!

### Refatoração

- Uma [pequena] modificação no sistema que não altera o seu comportamento funcional
- Mas que melhora alguma característica da qualidade interna:
	- Simplicidade
	- Flexibilidade
	- Legibilidade
	- Compreensão
	- Desempenho
