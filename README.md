# ultimate-tic-tac-toe-engine

### Running the Engine:
1. goto project directory
2. `$ cmake .`
3. `$ make`
4. `$ ultsimrunner -1 'bin/bot1' -2 'bin/bot2'`

### All Options:
```
usage: ultsimrunner --bot1exe=string --bot2exe=string [options] ...
options:
  -1, --bot1exe        first bot executable (string)
  -2, --bot2exe        first bot executable (string)
  -s, --suppress       suppress bots error stream
  -n, --numgames       number of games (int [=1])
  -v, --verbose        show more details
  -t, --timebank       set timebank in milliseconds (int [=40000])
  -m, --timepermove    set timepermove in milliseconds (int [=2000])
  -a, --alternate      alternate players, switch players every game
  -?, --help           print this message
```