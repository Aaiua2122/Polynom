build:
	g++ main.cpp polynomial.cpp -o program.exe

run: build
	.\program.exe

format:
	clang-format -i --style=Google main.cpp polynomial.cpp polynomial.h

clean:
	cmd /c del program.exe