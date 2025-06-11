# MetodyNumeryczne_lib

Prosta biblioteka numeryczna w C++ stworzona w ramach laboratorium z "Metod numerycznych". Biblioteka implementuje podstawowe algorytmy numeryczne.

## Zakres funkcjonalny

Biblioteka zawiera funkcje z następujących kategorii:
*   Rozwiązywanie układów równań liniowych (metoda eliminacji Gaussa).
*   Interpolacja (wielomian Lagrange'a).
*   Aproksymacja (metoda najmniejszych kwadratów).
*   Całkowanie numeryczne (metody prostokątów, trapezów, Simpsona).
*   Rozwiązywanie równań różniczkowych (metody Eulera i RK4).
*   Rozwiązywanie równań nieliniowych (metody bisekcji, Newtona, siecznych).

## Struktura projektu

MetodyNumeryczne_lib/
├── include/ # Pliki nagłówkowe (.h)
├── src/ # Pliki źródłowe (.cpp)
├── tests/ # Testy jednostkowe
├── examples/ # Przykłady użycia
├── Makefile # Plik budujący projekt
└── README.md # Ta dokumentacja

## Jak zbudować i uruchomić

### Wymagania
*   Kompilator C++ (np. g++)
*   Program `make`

### Budowa
1.  **Zbudowanie biblioteki i przykładów:**
    ```bash
    make
    ```
    Spowoduje to utworzenie biblioteki statycznej `libnumlib.a` oraz plików wykonywalnych w katalogu głównym.

2.  **Uruchomienie przykładów:**
    ```bash
    ./example_nonlinear
    ./example_lineq
    # itd.
    ```

3.  **Zbudowanie i uruchomienie testów:**
    ```bash
    make tests
    ```

4.  **Czyszczenie:**
    Aby usunąć wszystkie skompilowane pliki, użyj polecenia:
    ```bash
    make clean
    ```

## Przykłady użycia

W katalogu `examples/` znajduje się kilka plików demonstrujących użycie biblioteki. Można je zbudować poleceniem `make`.

*   `example_nonlinear`: Pokazuje, jak znaleźć miejsca zerowe funkcji `cos(x) - x` za pomocą metod bisekcji i Newtona.
*   `example_lineq`: Demonstruje rozwiązywanie układu równań liniowych 3x3.
*   `example_interpolation`: Używa interpolacji Lagrange'a do oszacowania wartości funkcji na podstawie kilku znanych punktów (węzłów).
*   `example_integration`: Oblicza całkę z `sin(x)` trzema różnymi metodami i porównuje wyniki z wartością dokładną.
*   `example_approximation`: Znajduje wielomian najlepiej aproksymujący bardziej złożoną funkcję na zadanym przedziale.
*   `example_diffeq`: Rozwiązuje równanie różniczkowe modelujące wzrost populacji (równanie logistyczne) za pomocą metody RK4.

## API Biblioteki

(Szczegółowy opis funkcji, ich parametrów i wartości zwracanych znajduje się w plikach nagłówkowych w katalogu `include/`.)
