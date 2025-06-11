# MetodyNumeryczne_lib

**Autorzy:** Mikołaj Bednarczyk i Jakub Bednarczyk  
**Projekt:** Biblioteka numeryczna w języku C++ stworzona w ramach laboratorium z przedmiotu *Metody Numeryczne*.

---

## Opis

`MetodyNumeryczne_lib` to prosta biblioteka C++ implementująca popularne metody obliczeń numerycznych, obejmująca m.in.:

- rozwiązywanie układów równań liniowych,
- interpolację i aproksymację,
- całkowanie numeryczne,
- metody numeryczne równań różniczkowych,
- rozwiązywanie równań nieliniowych.

Kod podzielony jest na moduły z plikami nagłówkowymi (`include/`) i źródłowymi (`src/`), zawiera testy jednostkowe oraz przykłady użycia.

---

## 📁 Struktura projektu

MetodyNumeryczne_lib/
├── include/ # Pliki nagłówkowe (.h)
├── src/ # Pliki źródłowe (.cpp)
├── tests/ # Testy jednostkowe
├── examples/ # Przykłady użycia
├── CMakeLists.txt # Plik budujący CMake
├── Makefile # Alternatywny plik Make
└── README.md # Dokumentacja

## Jak zbudować projekt

### Wymagania

- Kompilator C++ (np. `g++`, `clang++`, MSVC)
- `make` (dla Makefile) lub `cmake` (dla nowoczesnego budowania)
- Opcjonalnie: Visual Studio 2022 (pełna integracja z CMake)

### Opcja 1: Budowa przez `CMake` (zalecana)

```bash
mkdir build
cd build
cmake ..
cmake --build .

To utworzy bibliotekę libnumlib.a oraz wszystkie przykłady i testy jako osobne pliki wykonywalne.

Zakres funkcjonalny
Moduł	Funkcje
Układy równań	gauss_solve – rozwiązanie układu liniowego metodą eliminacji Gaussa
Interpolacja	obliczRozniceDzielone, wartoscInterpolacjiNewtona
Aproksymacja	approx, compute_system, gauss_solve
Całkowanie	simpson, trapezoidal, rectangle, gaussLegendreIntegration
Równania ODE	eulerCooling, rk4_step, heun_step, midpoint_step
Równania nieliniowe	bisekcja, newton, secant, regula_falsi


Plik	Demonstracja funkcjonalności
example_nonlinear.cpp	Metody bisekcji, siecznych i Newtona dla funkcji nieliniowych
example_lineq.cpp	Rozwiązywanie układów równań liniowych 2x2 i 3x3
example_interpolation.cpp	Interpolacja Newtona na bazie punktów
example_integration.cpp	Porównanie metod prostokątów, trapezów i Simpsona
example_approximation.cpp	Aproksymacja funkcji wielomianem najmniejszych kwadratów
example_diffeq.cpp	Rozwiązywanie równań różniczkowych metodą Eulera i RK4

Uwagi końcowe
    Projekt działa zarówno na Linux, Windows, jak i macOS.
    Kod zgodny z C++17, modularny i dokumentowany.
    Testy i przykłady można rozbudowywać samodzielnie.


