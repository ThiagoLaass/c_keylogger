# Windows Keylogger in C

This repository contains two keyloggers written in C:

- **Simple Keylogger**: A minimal version for basic functionality.
- **Advanced Keylogger**: A more comprehensive implementation.

Follow the instructions below to set up and run the keyloggers.

---

## Table of Contents

- [Installation Requirements](#installation-requirements)
- [Setup Instructions](#setup-instructions)
  - [Compiling and Running](#compiling-and-running)
  - [Accessing the Logs](#accessing-the-logs)
- [Keyloggers Overview](#keyloggers-overview)
- [Additional Notes](#additional-notes)

---

## Installation Requirements

- **Compiler**: [MinGW](https://www.mingw-w64.org/), a C/C++ compiler.
  - Install using Chocolatey:  
    ```bash
    choco install mingw
    ```
  - Or download from the [official website](https://www.mingw-w64.org/).

---

## Setup Instructions

### Compiling and Running

1. Navigate to the **Advanced Keylogger** directory:
   ```bash
   cd c_keylogger/src/keylogger
   ```
2. Compile the program:
   ```bash
   gcc -o keylogger main.c keylogger.c -luser32
   ```
3. Run the keylogger:
   ```bash
   .\keylogger.exe
   ```

Alternatively, compile and run in a single step:
```bash
gcc -o keylogger main.c keylogger.c -luser32 && .\keylogger.exe
```

### Accessing the Logs

- Keylogs are saved to a file named `keylog.txt` in the same directory as the executable.
- To open the directory in File Explorer:
  ```bash
  explorer.exe .
  ```

---

## Keyloggers Overview

### 1. **Simple Keylogger**
- Location: `c_keylogger/src/simple_keylogger`
- Features: Minimal setup with basic functionality.

### 2. **Advanced Keylogger**
- Location: `c_keylogger/src/keylogger`
- Features: Enhanced functionality and more robust features.

---

## Additional Notes

- Ensure you have **administrative privileges** when running the keylogger to avoid permissions issues.
- Be cautious when using or sharing keyloggers, as they can be classified as malicious software.

---

> **Disclaimer**: This software is intended for educational purposes only. The author is not responsible for any misuse of the code. Always ensure you have proper authorization when running keyloggers.

#### This project is licensed under The MIT License
