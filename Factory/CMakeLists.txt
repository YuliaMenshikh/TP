cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Dungeon)
include_directories(Heaven)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Game
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
        Dungeon/ShadowWitch.cpp
        Heaven/DuncanHero.h
        Dungeon/YlayaHero.h
        Hero.h
        HeroBase.h
        Test/test1.cpp
        Exceptions.h
        Squad.h
        Squad.cpp
        Position.h
        BattleField.h
        BattleField.cpp
        Strategy.h
        SimpleStrategy.h
        SimpleStrategy.cpp
        UnitInfo.h
        UnitInfo.cpp
        Direction.h
        HeroBase.cpp
        Game.h
        Game.cpp
        Command.h
        Command.cpp
        Strategy1.h
        Strategy1.cpp
        UnitDecorator.h
        DoubleHealthUnitDecorator.cpp
        DoubleHealthUnitDecorator.h
        UnitDecorator.cpp
        Logger.h
        ConsoleLogger.h
        Logger.cpp
        FileLogger.h
        HeroGenerator.cpp
        HeroGenerator.h)

add_subdirectory(googletest-master) 

include_directories(googletest-master/googletest/include) 
include_directories(googletest-master/googlemock/include)

enable_testing()

target_link_libraries(Game gtest gtest_main)