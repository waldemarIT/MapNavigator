#  MapNavigator

This project is a **C++ implementation (OOP, no STL containers)** of a pathfinding problem on a grid map with cities, roads, and one-way flight connections.

---

## 📌 Features
- Grid-based map with **roads, cities, and blocked cells**
- **City names** written directly on the map (letters occupy cells)
- **One-way flight connections** between cities with custom times
- **Shortest path calculation** (with or without route reconstruction)
- Implemented in **C++ without `std::string` or STL containers**
- Includes **custom string class** and **manual memory management**

---

## Implementation Notes
- STL containers (`vector`, `map`, etc.) are **not allowed**
- `std::string` and standard smart pointers are **forbidden**
- Implemented from scratch:
  - Custom **String** class  
  - Custom **data structures**  
  - Optional **smart pointers**
- Code follows **OOP principles**
- Focus on **efficiency and readability**
- Manual cleanup of memory is required

---

## 📥 Input Format

### Map dimensions
w h

markdown
Kopiuj
Edytuj

### Map description (h lines, each w characters)
- `.` → empty (impassable)  
- `#` → road (passable both ways)  
- `*` → city (passable like a road)  
- `[A-Z0-9]` → part of a city name (impassable)  

### Flights
k
source destination time
...

shell
Kopiuj
Edytuj

### Queries
q
source destination type
...

yaml
Kopiuj
Edytuj

- `type = 0` → only shortest travel time  
- `type = 1` → shortest travel time + route  

---

## 📤 Output Format
For each query, print one line:
- Always: **shortest travel time**  
- If `type = 1`: also print **intermediate cities in order**

---

## 🧩 Examples

### Correct map
GDANSK....OPOLE....RUMIA
...GDYNIA.............
SOPOT.................*
...PUCK*.*KRAKOW.REDA.HEL

shell
Kopiuj
Edytuj

### ❌ Incorrect map
**GDANSK..........OPOLE.
..........GDYNIA......
SOPOTHEL...............
..........REDA.PUCK..

css
Kopiuj
Edytuj

### ➡️ Path exists (A → B)
..................
A*####...#####B..
.....#.C.#........
.....####........

shell
Kopiuj
Edytuj

### ⛔ Path does not exist (A → B)
....##B
A##....
....##B
A#C...
.......
A*##C##*B

yaml
Kopiuj
Edytuj

---

## 🧪 Test Cases

The repository includes multiple tests:
1. Basic example  
2. Minimal input  
3. City name parsing  
4. Pathfinding correctness  
5. Simple grid test  
6. Small fan graph  
7. Small path graph  
8. Small complete graph  
9. Large map with few cities  
10. Large map with few cities (variant)  
11. Fan graph (array impl. too slow)  
12. Spiral (recursive DFS → stack overflow)  
13. Long path (inefficient impl. too slow)  
14. Many edges (performance stress test)  

---

## 🚀 Usage

Compile with any C++ compiler:
```bash
g++ main.cpp -o pathfinder
./pathfinder < input.txt > output.txt
