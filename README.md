# 📚 Anki-Style Vocabulary Learning System (C Project)

## 📌 Overview
This project is a command-line vocabulary learning system inspired by flashcard applications such as Anki.  
It uses spaced repetition to help users memorize words more effectively.

The system allows users to review vocabulary, track progress, and manage words dynamically.

---

## 🎯 Features
- Add new vocabulary words
- Delete existing words
- Search for words (fast lookup using hash table)
- Review system with:
  - Easy / Medium / Hard logic
  - Spaced repetition scheduling
- Save and load data from file
- CLI interface (menu-based)

---

## 🧠 Data Structures Used

### 1. Linked List
- Stores all vocabulary words
- Allows dynamic insertion and deletion

### 2. Queue
- Manages review sessions
- Controls spaced repetition order

### 3. Hash Table
- Provides fast search functionality
- Improves performance

---

## ⚙️ Algorithms

The system implements a **spaced repetition algorithm**:

- Easy → Move to later set (long delay)
- Medium → Move to next set (short delay)
- Hard → Repeat in the same set

This ensures difficult words are reviewed more frequently.

---

## 📁 Project Structure

```
project/
├── main.c
├── deck.c / deck.h        # Linked List (vocabulary storage)
├── queue.c / queue.h      # Queue (review system)
├── hash.c / hash.h        # Hash Table (search)
├── review.c / review.h    # Spaced repetition logic
├── storage.c / storage.h  # Save / Load system
├── ui.c / ui.h            # User interface
└── data.txt               # Saved vocabulary (auto-generated)
```


---

## 👨‍💻 Team Members

| Name   | Role                        | GitHub |
|--------|-----------------------------|--------|
| Palm   | Linked List                 | @kanyapetch21-max |
| August | Queue & Review System       | @augusttt_ag |
| Nano   | Hash Table                  | @sssuwan |

---

## 🚀 How to Run

### 🔧 Compile
```bash
gcc main.c deck.c queue.c hash.c review.c storage.c ui.c -o anki
