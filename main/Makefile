GCC = g++

OBJS = main.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Trainer.o Model.o GameCommand.o View.o WildPokemon.o

OUT = pokemon.out

default: main

main: $(OBJS)
	$(GCC) $(OBJS) -o $(OUT)

Point2D.o: Point2D.cpp Point2D.h
	$(GCC) -c Point2D.cpp -o Point2D.o

Vector2D.o: Vector2D.cpp Vector2D.h
	$(GCC) -c Vector2D.cpp -o Vector2D.o

GameObject.o: GameObject.cpp GameObject.h
	$(GCC) -c GameObject.cpp -o GameObject.o

Building.o: Building.cpp Building.h
	$(GCC) -c Building.cpp -o Building.o

PokemonCenter.o: PokemonCenter.cpp PokemonCenter.h
	$(GCC) -c PokemonCenter.cpp -o PokemonCenter.o

PokemonGym.o: PokemonGym.cpp PokemonGym.h
	$(GCC) -c PokemonGym.cpp -o PokemonGym.o

Trainer.o: Trainer.cpp Trainer.h
	$(GCC) -c Trainer.cpp -o Trainer.o

Model.o: Model.cpp Model.h
	$(GCC) -c Model.cpp -o Model.o

GameCommand.o: GameCommand.cpp GameCommand.h
	$(GCC) -c GameCommand.cpp -o GameCommand.o

View.o: View.cpp View.h
	$(GCC) -c View.cpp -o View.o

WildPokemon.o: WildPokemon.cpp WildPokemon.h
	$(GCC) -c WildPokemon.cpp -o WildPokemon.o

clean: 
	rm main Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Trainer.o Model.o GameCommand.o View.o WildPokemon.o
