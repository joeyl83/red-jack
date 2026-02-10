# 🎴 Red Jack

A hybrid **Texas Hold'em × Blackjack-style** card game built with **Godot 4.3** and **C++ GDExtension**.

Players receive two cards, face off against a dealer, and place bets as community cards are revealed across flop, turn, and river phases. The goal is to build the best hand while managing risk through progressive betting — with future competitive twists planned.

---

## 🧠 Game Concept

This project explores a unique hybrid card game structure:

- Player vs Dealer format (Blackjack-inspired)
- Texas Hold'em style community board
- Progressive betting rounds
- Partial information (dealer has hidden cards)
- Planned strategic modifiers and twists

### Basic Round Flow

1. Initial deal (2 player cards, 2 dealer cards)
2. Pre-flop betting
3. Flop reveal (3 community cards)
4. Turn reveal (1 card)
5. River reveal (1 card)
6. Showdown (best 5-card hand wins)

---

## 🛠️ Tech Stack

- **Engine:** Godot 4.3
- **Language:** C++ (GDExtension)
- **Build System:** SCons
- **Rendering:** 2D
- **Architecture:** Data-driven card system

---

## 🧱 Project Architecture

### Core Data Layer

| Class | Responsibility |
|------|---------------|
| `CardData` | Immutable card info (rank, suit, value, texture) |
| `Deck` | Generates and manages shuffled card pool |
| `Hand` | Player/Dealer hole cards |
| `Board` | Flop/Turn/River management |
| `GameManager` | Phase logic + game flow |

---

### Game Flow System

The game uses a phase-based state machine:

```
START_ROUND
→ PRE_FLOP
→ FLOP
→ TURN
→ RIVER
→ SHOWDOWN
```

---

### Rendering Layer

- `CardNode` handles:
  - visual flipping
  - animations
  - face-up / face-down state
- Game data remains separate from visuals.

---

## 🚀 Setup Instructions (Mac)

### Requirements

- Godot 4.3
- Python 3
- SCons
- Clang / Xcode tools

### Build Steps

```bash
scons platform=macos
```

### Run

1. Open project in Godot
2. Ensure GDExtension loads correctly
3. Run main scene

---

## 🎮 Current Features

- Standard 52-card deck
- Dealer vs Player structure
- Texas Hold’em community board
- Phase-based game manager
- GDExtension architecture

---

## 🔮 Planned Features

- Betting system + chips
- Poker hand evaluator
- Special card modifiers
- Competitive mechanics
- Animated card flips
- AI dealer behavior
- Save/load support

---

## 🧪 Development Status

```
Version: 0.1.0
Status: Early Playable Prototype
```

---

## 📚 Learning Goals

- Godot C++ GDExtension architecture
- Data-driven card systems
- Game state machines
- Hybrid card game design

---

## 📜 License

Personal project — license TBD.

---

## 👤 Author

Joey — passionate about:
- strategy games
- card game design
- systems programming
- game development
