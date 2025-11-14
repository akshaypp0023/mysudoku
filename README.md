🧩 Terminal Sudoku Game (C++ + ncurses)

A simple **Sudoku game** built using **C++** and **ncurses** for keyboard-controlled terminal gameplay.  
You can move with arrow keys, insert numbers, highlight cells, and check if your Sudoku solution is correct.

---

🎮 Features

- 9×9 Sudoku board
- Randomly generated starting numbers
- Fixed cells shown in **yellow**
- Player-inserted numbers shown in **cyan**
- Cursor highlight using **reverse video**
- `c` key → Check if Sudoku is completed and correct  
  ✔ Green = correct  
  ✖ Red = wrong
- Arrow keys to move
- `1–9` to enter values
- `q` to quit

---

🛠 Requirements

Make sure ncurses is installed:

```bash
sudo apt install libncurses5-dev libncursesw5-dev
