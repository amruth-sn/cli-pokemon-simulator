# Game Controls:

m ID x y<br>
"move": command Trainer ID to move to location (x, y).<br><br>
  
c ID1 ID2<br>
  "move towards a Pokemon Center”: command Trainer ID1 to start heading to Pokemon Center ID2.<br><br>
  
g ID1 ID2<br>
  “move towards a Pokemon Gym”: command Trainer ID1 to start heading towards Pokemon Gym ID2.<br><br>
  
s ID<br>
  "stop": command Trainer ID to stop doing whatever it is doing.<br><br>
  
p ID potion_amount<br>
  “buy potions”: command Trainer ID to buy potion_amount of potions at a Pokemon Center.<br><br>
  
b ID battle_amount<br>
  “complete battle_amount battles at a Pokemon Gym”: command Trainer ID to complete battle_amount of battles at a Pokemon Gym.<br><br>
  
a<br>
  "advance": advance one-time step by updating each object once.<br><br>
  
r<br>
  "run": advance one-time step and update each object, and repeat until either the update function returns true for at least one of the objects, or 5 time steps have been done.<br><br>
  
q<br>
  "quit": terminate the program<br><br>
  
n TYPE ID X Y<br>
  create a new object with the specified TYPE, ID number, (X, Y) location.<br>
  TYPE is a one letter abbreviation for the type of object:<br>
    ● c – PokemonCenter<br>
    ● g – PokemonGYM<br>
    ● t – Trainer<br>
    ● w – WildPokemon<br><br><br>
    
