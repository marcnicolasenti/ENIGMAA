# Simulador bàsic de la màquina ENIGMA

Aquest projecte que hem fet, simula una maquina que xifra y desxifra un fitxer de text

## Fitxers importants

- `main.cpp`: gestiona el menú i l’execució principal del programa.
- `rotor.h / rotor.cpp`: implementa la lògica d’un rotor (permutació, notch, offset...).
- `enigma.h / enigma.cpp`: connecta els tres rotors i aplica la lògica de xifrat i desxifrat.
- `Rotor1.txt`, `Rotor2.txt`, `Rotor3.txt`: contenen les configuracions dels rotors (permutació i notch).
- `Missatge.txt`: text original a xifrar.
- `xifrat.txt`: missatge xifrat (amb lletres en blocs de 5).
- `desxifrat.txt`: resultat de desxifrar el text xifrat.

## Funcionament

Quan s’executa el programa, mostra un menú amb 4 opcions:

```
1. Xifrar missatge  
2. Desxifrar missatge  
3. Editar rotors  
4. Sortir
```

### Xifrar

1. Esculls l’opció `1`.
2. Introdueixes la finestra inicial (tres lletres com ara `ABC`).
3. El programa llegeix el fitxer `Missatge.txt`, el neteja (majúscules, sense signes) i el passa pels tres rotors.
4. Es genera `xifrat.txt` amb el resultat.

### Desxifrar

1. Esculls l’opció `2`.
2. Has d’introduir **la mateixa finestra** (`ABC`) que vas fer servir per xifrar.
3. El programa carrega el fitxer `xifrat.txt`, aplica la lògica inversa i crea `desxifrat.txt`.

### Editar rotors

Opció `3` del menú. Pots configurar manualment els rotors, posant una permutació de 26 lletres (A-Z) i un notch.

## Cosetes a tenir en compte

- Si xifres i després desxifres sense reiniciar el programa, el missatge pot sortir malament perquè els rotors han avançat.
- Els fitxers `.txt` s’han de col·locar a la mateixa carpeta que l’executable (`x64/Debug`).
- No funcionen bé caràcters amb accents (á, è, ñ, ç...) → millor escriure els textos plans.

## Exemple de funcionament

Missatge original (`Missatge.txt`):

```
Hola som el Marc Nicolas i el Marc Pena
```

Finestra inicial: `ABC`

Resultat xifrat (`xifrat.txt`):

```
KTXFY WKOXK VQMLE TAJWS UEJHV GGFJY F
```

Resultat desxifrat (`desxifrat.txt`):

```
Hola som el Marc Nicolas i el Marc Pena
```

## Objectius apresos

- Ús de fitxers amb `fstream` (lectura i escriptura).
- Separació del codi en `.cpp` i `.h`.
- Validació de dades i control d’errors.
- Com funciona el xifrat per rotors.
- I sobretot... **tenir paciència!** 😅

## Fet per

> Marc Nicolas
> Marc Peña