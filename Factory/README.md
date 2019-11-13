# Heroes of Might and Magic
Turn-based strategy. Two factions: : Heaven (Орден Порядка), Dungeon (Лига Теней). 

## Game mode
### 1) Demonstration
### 2) Run Game
### 3) Run Tests


## Demonstration
Two armies of approximately the same strength are generated and fight in automatic mode.

## Run Tests
Run all tests.

## Run Game
At the beginning of the game, a faction is selected. Each faction corresponds to a certain hero (Heven - Duncan, Dungeon - Ylaya). After choosing a faction, you need to recruit an army from the available units and set their position on the playing field.
Each unit has attributes: Power, Protection, UnitsOfLife, Initiative, Speed, StockShots, MagicPoints.
You can also create a squad of units, with all units from the same squad occupy the same position and always move together.
When an army is formed, an enemy army with about the same strength is generated. After that, armies fight in automatic mode and actions are displayed in the console (or written to a file).




### Architecture
#### Generating patterns
When choosing a faction, a specific factory (Heaven Factory or Dungeon Factory) is created, each of which has a unique set of units. The playing field is implemented using the Singleton pattern.
#### Structural patterns
The linker for the implementation teams. The decorator is obvious why.
#### Behavioural patterns
Strategy (the hero makes his move depending on the specific implementation). Command.

### Classes
In the Unit interface, there are virtual methods that return unit metrics. From it and from the StandAloneUnit class, the UnitBase class is inherited, in which the values of the current indicators are stored and initialized. Each specific unit inherits UnitBase, and stores the maximum values of indicators.
There is also a separate class UnitInfo which stores data about the unit and its position.

The Squad class is an implementation of the linker pattern. Inherited from Unit and CompositeUnit (because this unit needs methods that are inherent only in the squad, such as remove killed units and return existing ones-separation of interfaces).

Hero interface: virtual methods: list of available units, adding new units/squads, removing killed units, checking for the presence of the hero's army. Also, the MakeStep function makes a game step according to a given strategy.
The Hero Base class implements these functions (specific heroes implement the GetName function).

Unit Factory interface: virtual methods: faction name, hero and unit creation, list of available units. In specific factories, these methods are implemented.

Singleton BattleField: check whether a given position is free, the ability to take and release a position.

The Position, Direction, Exceptions classes are obvious.

Logger: responsible for output to the console / writing to a file + its derived classes FileLogger, ConsoleLogger.

Strategy interface: there is only a virtual method MakeStep, which is implemented in different ways in SimpleStrategy and Strategy1.

Command: pattern Command; implementation in Attack Command and MoveCommand.

Decorator pattern the Decorator (for the Unit). In a specific implementation of DoubleHealthUnitDecorator damage to the unit is reduced by 2 times.

In Namespace Hero Generator, an army of a certain force is actually generated.
In Game Client Code.


1) Heaven
-крестьяне     [Peasant]     (Pw:1 , Pr:1 , L:3 , I:8 , S:4 , Sh:- , M:- )

-лучники     [Archer]     (Pw:4 , Pr:3 , L:7 , I:9 , S:4 , Sh:10 , M:- )

-мечники     [Footman]     (Pw:4 , Pr:8 , L:16 , I:8 , S:4 , Sh:- , M:- )

-грифоны     [Griffin]     (Pw:7 , Pr:5 , L:30 , I:15 , S:7 , Sh:- , M:- )

-монахи     [Priest]     (Pw:12 , Pr:12 , L:54 , I:10 , S:5 , Sh:7 , M:- )

-рыцари     [Cavalier]     (Pw:23 , Pr:21 , L:90 , I:11 , S:7 , Sh:- , M:- )

-ангелы     [Angel]        (Pw:27 , Pr:27 , L:180 , I:11 , S:6 , Sh:- , M:- )

2) Dungeon
-лазутчики         [Scout]        (Pw:3 , Pr:3 , L:10 , I:10 , S:5 , Sh:5 , M:- )

-бестии         [Blood Maiden]    (Pw:4 , Pr:2 , L:16 , I:14 , S:7 , Sh:- , M:- )

-минотавры         [Minotaur]    (Pw:5 , Pr:2 , L:31 , I:8 , S:5 , Sh:- , M:- )

-наездники на ящерах     [Dark Raiden]    (Pw:9 , Pr:7 , L:40 , I:11 , S:6 , Sh:- , M:- )

-гидры             [Hydra]        (Pw:15 , Pr:12 , L:80 , I:7 , S:5 , Sh:- , M:- )

-сумеречный ведьмы     [Shadow witch]    (Pw:18 , Pr:18 , L:80 , I:10 , S:4 , Sh:4 , M:11 )

-сумеречные драконы     [Shadow dragon]    (Pw:25 , Pr:24 , L:200 , I:10 , S:9 , Sh:- , M:- )

### running
'cmake' and 'make'

