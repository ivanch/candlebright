# Joguinho!

## A fazer
* [ ] Persistência de objetos (salvar e carregar ranking)
* [x] Criar o mapa 1 (cidade)
* [x] Criar o mapa 2 (cemitério)


## Requisitos do jogo

| Conceito | Situação | Implementação |
|---|---|---|
| Apresentar menu de opções aos usuários do Jogo | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Menu* e seu respectivo objeto. |
| Permitir um ou dois jogadores aos usuários do Jogo, sendo que no último caso seria para que os dois joguem de maneira concomitante. | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Jogador*, cujos objetos são agregados em `Game`, podendo ser um ou dois efetivamente. |
| Disponibilizar ao menos duas fases que podem ser jogadas sequencialmente ou selecionadas. | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *City* e *Cemitery*, cujos objetos são agregados em `Game`, podendo ser um ou dois efetivamente. |
| Ter três tipos distintos de inimigos (o que pode incluir Chefão, vide abaixo). | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *Clothed_Zombie*, *Ghost*, *Hell_Demon*, *Sylathus* e *Zombie*, com seus respectivos objetos sendo instanciados em `Game` e em cada Fase. |
| Ter a cada fase ao menos dois tipos de inimigos com número aleatório de instâncias, podendo ser  várias instâncias e sendo pelo menos 5 instâncias por tipo. | Requisito previsto inicialmente e realizado. | Requisito cumprido através das construtoras de *City* e *Cemitery*, que instanciam os inimigos apenas uma vez. As intancias aleatórias foram feitas através da função *update* dentro da classe *Game*. |
| Ter inimigo Chefão na última fase | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Sylathus*, instanciada em *Cemitery* (segunda fase). |
| Ter três tipos de obstáculos | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *Black_Hole*, *Fire* e *Wall*. |
| Ter em cada fase ao menos dois tipos de obstáculos com número aleatório de instâncias (i.e., objetos) sendo pelo menos 5 instâncias por tipo. | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *Fire*, *Wall*, *Platform* e *Black_Hole*, as quais são instanciadas em *City* e *Cemitery*, também sendo instanciadas de forma aleatória na função *update* em *Game*. |
| Ter representação gráfica de cada instância | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe abstrata *Entity*, que possui um método virtual puro chamado *draw*, responsável por desenhar a entidade na tela |
| Ter em cada fase um cenário de jogo com os obstáculos. | Requisito previsto inicialmente e realizado. | Requisito cumprido através da criação de obstáculos dentro da construtora das classes *City* e *Cemitery*. |
| Gerenciar colisões entre jogador e inimigos | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *CollisionManager* e *Phase*. |
| Gerenciar colisões entre jogador e obstáculos | Requisito previsto inicialmente e realizado. | Requisito cumprido através das classes *CollisionManager* e *Phase*. |
| Permitir cadastrar/salvar dados do usuário, manter pontuação durante jogo, salvar pontuação e gerar lista de pontuação (ranking). | A fazer | --- |
| Permitir pausar o jogo | Requisito previsto inicialmente e realizado. | Requisito cumprido via função *update* dentro da classe *Game*. |
| Permitir salvar jogada | Requisito previsto inicialmente e realizado. | Requisito cumprido através da função *saveGame* dentro da classe *Game*. |

## Conceitos elementares

| Conceito | Uso | Onde |
|---|---|---|
| Classes, objetos | Sim | Todos .hpp e .cpp |
| Atributos (privados), variáveis e constantes | Sim | Todos .hpp e .cpp |
| Métodos (com e sem retorno) | Sim |  Todos .hpp e .cpp |
| Métodos (com retorno *const* e parâmetro *const*) | Sim | Todos .hpp e .cpp |
| Construtores (com e sem parâmetros) e destrutores | Sim | Todos .hpp e .cpp |
| Classe Principal | Sim | `main.cpp` e `Game.hpp/cpp` |
| Divisão em .h e .cpp | Sim | Todos .hpp e .cpp |

## Conceitos de relações

| Conceito | Uso | Onde |
|---|---|---|
| Associação direcional | Sim | --- |
| Associação bidirecional | Sim | `Character.hpp` e `CharacterState.hpp` |
| Agregação via associação | Sim | --- |
| Agregação propriamente dita | Sim | --- |
| Herança elementar | Sim | --- |
| Herança em diversos níveis | Sim | --- |
| Herança múltipla | Sim | `Character.hpp` |

## Conceitos ponteiros, generalizações e exceções

| Conceito | Uso | Onde |
|---|---|---|
| Operador `this` | Sim | `LinkedList.hpp` |
| Alocação de memória `new` & `delete` | Sim | `LinkedList.hpp` |
| *Templates* | Sim | `LinkedList.hpp` |
| Uso de tratamento de exceções | Sim | `AnimManager.hpp/cpp` |

## Conceitos de sobrecarga

| Conceito | Uso | Onde |
|---|---|---|
| Construtoras e métodos | Sim | `Platform.hpp` |
| Operadores (2 tipos ao menos) | A fazer | `LinkedList.hpp` |

## Conceitos de sobrecarga de persistência de objetos
 
| Conceito | Uso | Onde |
|---|---|---|
| Persistência de objetos | Sim | `Game.cpp` |
| Persistência de relacionamento de objetos | Não | --- |

## Conceitos de virtualidade

| Conceito | Uso | Onde |
|---|---|---|
| Métodos virtuais | Sim | `Character.hpp` |
| Polimorfismo | Sim | --- |
| Métodos virtuais puros | Sim | `Entity.hpp` |
| Coesão e desacoplamento | Sim | --- |

## Conceitos de operadores estáticos

| Conceito | Uso | Onde |
|---|---|---|
| *Namespace* criada pelos autores | Sim | `BlackHole.hpp`, `Fire.hpp`, `Obstacle.hpp`, `Platform.hpp`, `Wall.hpp`, `Cemitery.hpp`, `City.hpp` |
| Classes aninhadas | Sim | `LinkedList.hpp` |
| Atributos estáticos e métodos estáticos | Sim | `Player.hpp/cpp` |
| Uso extensivo de constante em parâmetro, retorno, método | Sim | --- |

## Conceitos de STL e String OO

| Conceito | Uso | Onde |
|---|---|---|
| Classe *string* ou equivalente | Sim | --- |
| *Vector* e/ou *List* | Sim | `ObstacleList.hpp` e `ThingsList.hpp` |
| Pilha, fila, bifila, fila de prioridade, conjunto, multi-conjunto, mapa **OU** multi-mapa | Sim | `CharacterList.hpp` |

## Conceitos de programação concorrente
| Conceito | Uso | Onde |
|---|---|---|
| *Threads* no âmbito POO, utilizando *Posix* | Sim | `Thread.hpp/cpp` e `Music.hpp/cpp` |
| *Threads* no âmbito POO, com uso de Mutex, semáforos **OU** troca de mensagens | Não | --- |

## Conceitos de biblioteca gráfica/visual
| Conceito | Uso | Onde |
|---|---|---|
| Funcionalidades elementares | Sim | `Engine.hpp/cpp` |
| Funcionalidades avançadas como tratamento de colisões | Sim | `CollisionManager.hpp/cpp` |
| Programação orientada a evento em algum ambiente gráfico | Não? | --- |
| *RAD - Rapid Application Development* (formulários, botões, etc) | Não | --- |

## Conceitos de biblioteca gráfica/visual com interdisciplinaridades por meio da utilização de conceitos de matemática e/ou física.
| Conceito | Uso | Onde |
|---|---|---|
| Ensino médio | ? | --- |
| Ensino superior | ? | --- |

## Conceitos de engenharia de software
| Conceito | Uso | Onde |
|---|---|---|
| Compreensão, melhoria e rastreabilidade de cumprimento de requisitos | Sim | --- |
| Diagrama de classes em UML | Sim | --- |
| Uso efetivo de padrões de projeto | Sim | `CharacterState.hpp/cpp` |
| Testes a luz da tabela de requisitos e do diagrama de classes | ? | --- |

## Conceitos de engenharia de software
| Conceito | Uso | Onde |
|---|---|---|
| Versionamento | Sim | (Qual?) git |
| Reuniões com o professor | Sim | (Quantas e onde?) Total de 5 reuniões (especificiar os locais). |
| Reuniões com o monitor | Não | --- |
| Revisão do trabalho escrito de outra equipe e vice-versa | A fazer | (Qual?) --- |