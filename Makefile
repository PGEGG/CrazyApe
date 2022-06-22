compile:
	g++ \
	"Animal.cpp" "Banana.cpp" "Coconut.cpp" "Gamecontroller.cpp" \
	"Gui.cpp" "Heart.cpp" "Item.cpp" "Main.cpp" \
	"Player.cpp" "Scorpion.cpp" "Tiger.cpp" "Tree.cpp" \
	"-IC:\\SFML-2.5.1\\include" "-LC:\\SFML-2.5.1\\lib" \
	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system \
	"-o" "CrazyApe.exe"