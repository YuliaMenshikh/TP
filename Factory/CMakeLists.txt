cmake_minimum_required(VERSION 3.12)
project(Factory)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Dungeon)
include_directories(Heaven)

add_executable(Factory
        Dungeon/DungeonFactory.cpp
        Dungeon/DungeonFactory.h
        Heaven/HeavenFactory.cpp
        Heaven/HeavenFactory.h
        main.cpp
        Unit.h
        UnitFactory.h
        Heaven/Peasant.h
        Heaven/Archer.h
        Heaven/Footman.h
        Heaven/Griffin.h
        Heaven/Priest.h
        Heaven/Cavalier.h
        Heaven/Angel.h
        Dungeon/Scout.h
        Dungeon/BloodMaiden.h
        Dungeon/Minotaur.h
        Dungeon/DarkRaiden.h
        Dungeon/Hydra.h
        Dungeon/ShadowWitch.h
        Dungeon/ShadowDragon.h
        Heaven/Angel.cpp
        UnitBase.h
        UnitBase.cpp
        Heaven/Archer.cpp
        Heaven/Cavalier.cpp
        Heaven/Footman.cpp
        Heaven/Griffin.cpp
        Heaven/Peasant.cpp
        Heaven/Priest.cpp
        Dungeon/BloodMaiden.cpp
        Dungeon/DarkRaiden.cpp
        Dungeon/Hydra.cpp
        Dungeon/Minotaur.cpp
        Dungeon/Scout.cpp
        Dungeon/ShadowDragon.cpp
        Dungeon/ShadowWitch.cpp Heaven/DuncanSingleton.h Dungeon/YlayaSingleton.h)
