## Rock Paper Scissors — C (simple, extensible)
A small, portable Rock Paper Scissors game written in C for practice :).

### Features
- Human vs. Computer play
- Simple, readable C source for easy modification (I hope its readable at least x3)
- Optional prebuilt executable (app) included

### Prerequisites
- C compiler (GCC, clang, or MSVC)
- POSIX-compatible terminal or Windows command prompt / PowerShell

### Building
- Unix / macOS:
  ```
  gcc main.c -o app
  ./app
  ```
- Windows (Command Prompt or PowerShell):
  ```
  gcc main.c -o app.exe
  .\app.exe
  ```

Or, alternatively - just run the prebuilt app in the project_one folder.
  
### Todo: 
- Swap AI: replace the computer move generator to implement random, weighted, or pattern-based AI.
- Persist scores: write/read a small file (e.g., scores.txt) to keep total wins/losses.
- Modularize: separate gameplay logic into rps.h / rps.c with main.c for interfacing with the terminal.
- Add CLI flags: number of rounds, verbose mode, player names.

### Troubleshooting
- “gcc: command not found” — install GCC or use another C compiler (like musl).

### Contact / Attribution
Contact Amilie @ amiliedev@proton.me

---
