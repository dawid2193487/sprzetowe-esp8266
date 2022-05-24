# ESP8266

## Początkowa konfiguracja

### Windows
Aby skompilować projekt potrzebne będzie środowisko MSYS2, można je pobrać tutaj: https://www.msys2.org/

Po zainstalowaniu, z terminala MinGW należy wykonać komendę

```bash
$ make install-arduino-cli
```

aby zainstalować Arduino CLI. 

## Komendy make

`make install-arduino-cli` - zainstaluj Arduino CLi do folderu ./bin/

`make install-deps` - instaluje biblioteki (tak jakbyś to robił przez Board Manager w Arduino IDE)

`make build` - kompiluje projekt

`make flash` - kompiluje i flashuje projekt. Komenda zakłada że ESP8266 jest dostępne na COM3.