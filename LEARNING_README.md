# Learning Read Me

## Context
This is not a standard README page.  

This page is intended to track and showcase my learning throughout the development of this project.

---

## Intentions
I started this project to solve a problem I was personally struggling with while also learning C++ and developing real-world skills.

Before starting this project, I had very minimal experience with C/C++.

---

## Order
The order of topics listed here is based on when I learned them.

Whenever I learn something new that is used in this project, I add it to this file.

This is mainly a way for me to:
- Track my progress
- Reinforce what I’ve learned
- Practice explaining concepts in a way someone else could understand

---

# Learning Entries

---

## 1. Creating / Reading / Writing Files (.txt)

### Why I needed this
One of the primary features of this project is allowing users to store shortcuts in text files.

For example:
- System shortcuts
- Neovim shortcuts
- IntelliJ shortcuts
- Other application-specific shortcuts

To make this possible, I needed a way to create files, read files, and write data to files directly from the command line.

### What I learned

#### `fstream` library
```cpp
#include <fstream>
```

- This library allows you to work with files in C++.
- To use the `fstream` library in this project, I also need to include `iostream`.
- `fstream` is closely related to:
  - `ofstream` → creates and writes to files
  - `ifstream` → reads from files

```cpp
#include <iostream>
#include <fstream>
```

- You need both because while `fstream` allows you to read and write files, `iostream` is needed to get input from the user.
- You also need `iostream` to display output back to the user in the CLI.

#### Syntax (Create, Open, Reference Text Files)

```cpp
ofstream MyFile("filename.txt");

ofstream MyFile("folder/filename.txt");

ofstream MyFile("filename.txt", ios::app);
```

- The three lines above showcase three different use cases.

- By default, if `"filename.txt"` already exists in the current directory, `ofstream` will wipe its contents.

- The first line showcases creating a new text file and getting a reference to it (`MyFile`).

- The second line showcases how you can create files in a specific directory.

- The third line showcases how you can reference a file that already exists **without wiping its contents**.

  - `app` is a constant in the input/output stream namespace that acts as a flag meaning `"append"`.

---

# Future Entry Template

Use this structure for future learning entries. It doesn't need to be followed perfectly—it's mainly here to keep things somewhat consistent.

---

## [Topic Name]

### Why I needed this
Explain what feature, problem, or requirement made you learn this.

### What I learned

#### [Concept / Subtopic Name]

```cpp
// Optional code example
```

- Explain what this does
- Explain how it works
- Add extra notes/details if needed

#### [Another Concept / Subtopic]

```cpp
// Optional code example
```

- Add notes here

### Additional Notes (Optional)
Anything extra worth documenting that doesn't fit cleanly into the sections above.
