# Joguinho!

## A fazer
* [x] Efetivar ataque dos inimigos
* [ ] Persistência de objetos (salvar e carregar jogo)
* [ ] Persistência de objetos (salvar e carregar ranking)
* [x] Mostrar vida na tela (parcial)
* [x] Obstáculos


## Requisitos do jogo

| Conceito | Situação | Implementação |
|---|---|---|
| Apresentar menu de opções aos usuários do Jogo | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe Menu e seu respectivo objeto. |
| Permitir um ou dois jogadores aos usuários do Jogo, sendo que no último caso seria para que os dois joguem de maneira concomitante. | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe Jogador, cujos objetos são agregados em `Game`, podendo ser um ou dois efetivamente. |
| Disponibilizar ao menos duas fases que podem ser jogadas sequencialmente ou selecionadas. | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *City* e *Cemitery*, cujos objetos são agregados em `Game`, podendo ser um ou dois efetivamente. |
| Ter três tipos distintos de inimigos (o que pode incluir Chefão, vide abaixo). | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Clothed_Zombie*, *Ghost*, *Hell_Demon*, *Sylathus* e *Zombie*, os quais são instanciados através das classes de fase |
| Ter a cada fase ao menos dois tipos de inimigos com número aleatório de instâncias, podendo ser  várias instâncias e sendo pelo menos 5 instâncias por tipo. | A fazer | --- |
| Ter inimigo Chefão na última fase | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Sylathus*, instanciada em *Cemitery* (segunda fase). |
| Ter três tipos de obstáculos | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *Black_Hole*, *Fire* e *Wall*. |
| Ter em cada fase ao menos dois tipos de obstáculos com número aleatório de instâncias (i.e., objetos) sendo pelo menos 5 instâncias por tipo. | Requisito previsto inicialmente e realizado. | --- |
| Ter representação gráfica de cada instância | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe abstrata *Entity*, que possui um método virtual puro chamado *draw*, responsável por desenhar a entidade na tela |
| Ter em cada fase um cenário de jogo com os obstáculos. | Requisito previsto inicialmente e realizado. | --- |
| Gerenciar colisões entre jogador e inimigos | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *CollisionManager* e *Phase*. |
| Gerenciar colisões entre jogador e obstáculos | Requisito previsto inicialmente e realizado. | Requisito cumprido via classe *CollisionManager* e *Phase*. |
| Permitir cadastrar/salvar dados do usuário, manter pontuação durante jogo, salvar pontuação e gerar lista de pontuação (ranking). | A fazer | --- |
| Permitir pausar o jogo | Requisito previsto inicialmente e realizado. | Requisito cumprido via função *update* dentro da classe *Game* |
| Permitir salvar jogada | A fazer | --- |

## Conceitos elementares

| Conceito | Uso | Onde |
|---|---|---|
| Classes, objetos | Sim | Todos .hpp e .cpp |
| Atributos (privados), variáveis e constantes | Sim | Todos .hpp e .cpp |
| Métodos (com e sem retorno) | Sim |  Todos .hpp e .cpp |
| Métodos (com retorno *const* e parâmetro *const*) | A fazer | --- |
| Construtores (com e sem parâmetros) e destrutores | Sim | Todos .hpp e .cpp |
| Classe Principal | Sim | `main.cpp` e `Game.hpp/cpp` |
| Divisão em .h e .cpp | A fazer | --- |

## Conceitos de relações

| Conceito | Uso | Onde |
|---|---|---|
| Associação direcional | Sim | --- |
| Associação bidirecional | Não | --- |
| Agregação via associação | ? | --- |
| Agregação propriamente dita | ? | --- |
| Herança elementar | Sim | --- |
| Herança em diversos níveis | Sim | --- |
| Herança múltipla | Sim | *Animatable* e *Character* |

## Conceitos ponteiros, generalizações e exceções

| Conceito | Uso | Onde |
|---|---|---|
| Operador `this` | Sim | --- |
| Alocação de memória `new` & `delete` | Sim | `LinkedList.hpp` |
| *Templates* | Sim | `LinkedList.hpp` |
| Uso de tratamento de exceções | Sim | `AnimManager.hpp/cpp` |

## Conceitos de sobrecarga

| Conceito | Uso | Onde |
|---|---|---|
| Construtoras e métodos | Sim | --- |
| Operadores (2 tipos ao menos) | A fazer | `LinkedList.hpp` |

## Conceitos de sobrecarga de persistência de objetos
 
| Conceito | Uso | Onde |
|---|---|---|
| Persistência de objetos | A fazer | --- |
| Persistência de relacionamento de objetos | A fazer | --- |

## Conceitos de virtualidade

| Conceito | Uso | Onde |
|---|---|---|
| Métodos virtuais | Sim | --- |
| Polimorfismo | Sim | --- |
| Métodos virtuais puros | Sim | --- |
| Coesão e desacoplamento | Supostamente | --- |

## Conceitos de operadores estáticos

| Conceito | Uso | Onde |
|---|---|---|
| *Namespace* criada pelos autores | A fazer (?) | --- |
| Classes aninhadas | Sim | `LinkedList.hpp` |
| Atributos estáticos e métodos estáticos | A fazer | --- |
| Uso extensivo de constante parâmetro, retorno, método | A fazer | --- |

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
## Conceitos de biblioteca gráfica/visual
| Conceito | Uso | Onde |
|---|---|---|
| Ensino médio | ? | --- |
| Ensino superior | ? | --- |

## Conceitos de engenharia de software
| Conceito | Uso | Onde |
|---|---|---|
| Compreensão, melhoria e rastreabilidade de cumprimento de requisitos | Sim | --- |
| Diagrama de classes em UML | Sim | --- |
| Uso efetivo de padrões de projeto | Sim | CharacterState |
| Testes a luz da tabela de requisitos e do diagrama de classes | ? | --- |

## Conceitos de engenharia de software
| Conceito | Uso | Onde |
|---|---|---|
| Versionamento | Sim | git |
| Reuniões com o professor | Sim | ? |
| Reuniões com o monitor | Não | --- |
| Revisão do trabalho escrito de outra equipe e vice-versa | A fazer | --- |