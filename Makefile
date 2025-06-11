# Kompilator C++
CXX = g++

# Flagi kompilatora: standard C++17, ostrzeżenia, ścieżka do plików nagłówkowych
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Flagi linkera
LDFLAGS =

# Nazwa biblioteki
LIBNAME = numlib
STATIC_LIB = lib$(LIBNAME).a

# Pliki źródłowe i obiektowe
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Pliki wykonywalne przykładów i testów
EXAMPLE_SRCS = $(wildcard examples/*.cpp)
EXAMPLES = $(EXAMPLE_SRCS:.cpp=)

TEST_SRCS = $(wildcard tests/*.cpp)
TESTS = $(TEST_SRCS:.cpp=)

# Domyślny cel: zbuduj bibliotekę i przykłady
all: $(STATIC_LIB) $(EXAMPLES)

# Cel do budowania biblioteki statycznej
$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

# Ogólna reguła do kompilacji plików .cpp na .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cel do budowania przykładów
$(EXAMPLES): %: examples/%.cpp $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< -L. -l$(LIBNAME) $(LDFLAGS)

# Cel do budowania i uruchamiania testów
tests: $(TESTS)
	@echo "--- Running all tests ---"
	@for test in $(TESTS); do ./$$test; done
	@echo "--- All tests finished ---"
	
# Reguła do budowania pojedynczego testu
$(TESTS): %: tests/%.cpp $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< -L. -l$(LIBNAME) $(LDFLAGS)

# Cel do czyszczenia
clean:
	rm -f src/*.o $(STATIC_LIB) $(EXAMPLES) $(TESTS)

.PHONY: all tests clean