# Projekt 3 - Rotacje 2D

## Budowanie programu i testów

W celu zbudowania programu należy użyć poniższych komend

```bash
    git submodule update --init --recursive
		cd build && cmake ..
    make
```

Następnie z poziomu build można uruchomić program

```bash
    ./Rotation3D_run
```

i wywołać testy przechodząc do folderu test

```bash
    cd test
    ./Rotation3D_tst
```

Przy wywołaniu make,dokumentacja doxygen utworzy się automatycznie w folderze "doc_doxygen".
W celu obejrzenia jej należy przejść do folderu i otworzyć plik index w przeglądarce.

W razie problemów proszę o kontakt <259370@student.pwr.edu.pl>

# Przygotowanie

Jeżeli chodzi o przygotowanie (wykorzystanie szablonów w zadaniu nr.3) nie jest ono wykonalne natychmiastowo przez różnice w strukturze szablonów i zastosowanych wcześniej rozwiązań.
Koncepcyjnie wszystko będzie działać,ale należałoby dokonać kilku modyfikacji.W ramach potwierdzenia skalowalności na 2D w testach również oprócz głównie używanych obiektów o rozmiarze 3
znajdują się także o rozmiarze 2 lub więcej.
