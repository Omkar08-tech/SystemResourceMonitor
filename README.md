# System Resource Monitor (Linux + C++ + ncurses)

A lightweight, modular command-line system monitor written in C++ using Linux APIs and `ncurses`. It displays real-time CPU usage, memory consumption, and active processes with optional filtering and sorted output.
---

## 🚀 Features

- ✅ Real-time CPU and memory usage monitoring
- ✅ Process list with dynamic updates
- ✅ Filtering by process name (e.g., `chrome`, `firefox`)
- ✅ Sorted process display (alphabetical)
- ✅ Interactive ncurses-based UI
- ✅ Clean modular codebase using Linux `/proc` and system calls

---

## 🛠️ Built With

- **C++ (C++11)**  
- **Linux system APIs** (`/proc`, `sys/sysinfo.h`, etc.)  
- **ncurses** for terminal-based UI

---

## 📦 Installation

### 🔧 Prerequisites

Install required packages (for Debian/Ubuntu):

```bash
sudo apt update
sudo apt install build-essential libncurses5-dev
```

---

## 🧪 Build & Run

### 💻 Compile

```bash
make
```

### ▶️ Run

```bash
./sysmon                # Show all processes
./sysmon firefox        # Filter for processes with 'firefox'
```

> Exit using `Ctrl+C`

---

## 📁 Project Structure

```
SystemResourceMonitor/
├── include/              # Header files (e.g., ProcessMonitor.h)
├── src/                  # Source code
├── Makefile              # Build script
├── sysmon                # Compiled binary (after build)
└── README.md             # This file
```

---

## 🧩 Future Improvements

- [ ] Display CPU & memory usage per process  
- [ ] Sorting by CPU or memory usage  
- [ ] Support for colored UI & themes  
- [ ] Mouse or keyboard interaction  
- [ ] Export stats to file  

---

## 🧑‍💻 Author

**Omkar Shirdhone**  
Built with ❤️ using C++ & Linux internals  
[GitHub](https://github.com/Omkar08-tech)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
