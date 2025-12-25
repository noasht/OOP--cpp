# Object Oriented Programming

🎯 OOP course assignments at SCE College of Engineering
 
**Language:** C++ | **Topics:** Classes, Operators, Inheritance, Polymorphism, Templates, STL

---

## 🗂️ Project Structure
```
├── HW1_tictactoe_mynumber/
│   ├── Q1_TicTacToe/
│   ├── Q2_MyNumber/
│   └── Q3_MyNumberStack/
├── HW2_operators_linkedlist/
│   ├── Q1_MyNumber/
│   ├── Q2_LinkedList/
│   └── Q3_MyMain/
├── HW3_matchmaking/
├── HW4_shapes_employees/
│   ├── Q2_Shapes/
│   └── Q3_Employees/
└── HW5_bimap_stl/
```

---

## 📝 Assignments

### Assignment 1: Classes & Basic OOP

| Folder | Project | Description |
|--------|---------|-------------|
| Q1_TicTacToe | **TicTacToe** | A complete Tic-Tac-Toe game. The `TicTacToe` class manages a 3x3 board, validates player moves, detects win/draw states, and runs the game loop. |
| Q2_MyNumber | **MyNumber** | Represents non-negative integers as dynamic boolean arrays (binary). Supports addition, comparison, copy, and conversion to long. |
| Q3_MyNumberStack | **MyNumberStack** | A stack data structure holding `MyNumber` objects. Implements push, pop, top, isEmpty, isFull with dynamic memory management. |

---

### Assignment 2: Operator Overloading

| Folder | Project | Description |
|--------|---------|-------------|
| Q1_MyNumber | **MyNumber Extended** | Extends MyNumber with operators: `+`, `*`, `/`, `%`, `+=`, `++`, `==`, `<`, `>`, `<<`, `>>`, and conversion to `int` and `char*`. |
| Q2_LinkedList | **LinkedList** | A sorted linked list (no duplicates) using a private `Node` inner class. Supports `+=` (insert), `-=` (remove), `+` (merge lists), and `<<` (print). |
| Q3_MyMain | **MyMain** | Menu-driven system to manage two `MyNumber` objects and two `LinkedList` objects. Allows arithmetic operations, comparisons, and list manipulations. |

---

### Assignment 3: Inheritance & Operators
**Project:** Matchmaking Agency 💕

A dating service management system:

| Class | Description |
|-------|-------------|
| `MyString` | Custom string class with dynamic memory, copy constructor, `=` and `==` operators. |
| `Client` | Stores ID, name, gender, age, and hobbies array. The `compatibility()` method checks if two clients match (opposite gender, age diff ≤5, shared hobby). |
| `VIPClient` | Inherits from Client. Requires minimum number of shared hobbies for compatibility. |
| `MatchmakingAgency` | Database of clients (dynamic array of pointers). Supports `+=` (add), `-=` (remove), `<<` (print all), and `searchByID()` to find matches. |
| `Menu` | User interface with options: add client, remove client, print all, find matches, quit. |

---

### Assignment 4: Polymorphism & RTTI

| Folder | Project | Description |
|--------|---------|-------------|
| Q2_Shapes | **Shapes Hierarchy** | Abstract `Shape` base class with `Circle`, `Rectangle`, `Ring` (inherits Circle), `Cylinder` (inherits Circle), and `Cuboid` (inherits Rectangle). Each calculates area/volume. Menu system to filter by color, volume, type, and sum areas/volumes. Uses RTTI for type checking. |
| Q3_Employees | **Employee Management** | Abstract `Person` class with virtual inheritance. `Employee` has salary, `Customer` has purchase history array. `CustomerEmployee` inherits both and gets 10% discount. Menu manages database with add, buy, update salary, print, and average salary calculation. |

---

### Assignment 5: Templates & STL
**Project:** City Union Management 🏙️

| Component | Description |
|-----------|-------------|
| `BiMap<T1,T2>` | A generic bidirectional map where both keys and values are unique. Access by either key type in O(log n). Includes custom iterators (`iteratorF`, `iteratorS`). |
| `City<T>` | Generic city class with name, size, and unique identifier of type T. Implements comparison operators based on identifier. |
| `Exception Classes` | Abstract exception base class with `exceptionCity` and `exceptionRep` subclasses for error handling. |
| **Menu System** | 12 operations: add/remove cities and representatives, lookup by city or name, check existence, sort and print, clean database. Input/output via files with exception handling. |

---

## 📄 License

Academic coursework at SCE College of Engineering.
