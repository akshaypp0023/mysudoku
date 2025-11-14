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
---
📁 Project Structure
mysudoku/
├── main.cpp
├── sudoku.cpp
├── sudoku.h
└── README.md
---
▶️ Build & Run <-- SECTION 1

Compile:
```bash
g++ main.cpp sudoku.cpp -lncurses -o sudoku

---
Run:

```bash
./sudoku
---

🔧 Controls
Key	Function
Arrow Keys	Move
1–9	Insert number
c	Check Sudoku
q	Quit
---
🖼 Screenshot <-- SECTION 2



![Sudoku Screenshot](images/Screenshot1.png)

---

Example structure:

mysudoku/
├── images/
│   └── Screenshot1.png
├── main.cpp
├── sudoku.cpp
├── sudoku.h
└── README.md
---
🚀 Future Improvements

Timer

Mistake highlighting

Difficulty levels
---
👨‍💻 Author

Akshay P P
---
📜 License

This project is open source.
