```
                       ______
                    .-"      "-.
                   /            \
       _          |              |          _
      ( \         |,  .-.  .-.  ,|         / )
       > "=._     | )(__/  \__)( |     _.=" <
      (_/"=._"=._ |/     /\     \| _.="_.="\_)
             "=._ (_     ^^     _)"_.="
                 "=\__|IIIIII|__/="
                _.="| \IIIIII/ |"=._
      _     _.="_.="\          /"=._"=._     _
     ( \_.="_.="     `--------`     "=._"=._/ )
      > _.="                            "=._ <
     (_/                                    \_)
```

# 🌊 SEA_PRINTF 🏴‍☠️

**A pirate's implementation of printf, sailing the C seas!**

> *"Why use the landlubber's printf when ye can have yer own sea_printf?"*

## 📜 About This Treasure

**sea_printf** be a custom implementation of the mighty `printf` function, crafted by the hands of **Swittzy** and **espadara** aboard the good ship *Code Kraken*. This library be built with performance in mind, using arena allocation to manage memory like a true captain manages their crew!

## ⚓ Features

- ✨ **Full printf compatibility** - All yer favorite format specifiers
- 🎯 **Conversion specifiers supported:**
  - `%c` - Character (a single letter from the treasure map)
  - `%s` - String (tales of the seven seas)
  - `%p` - Pointer (X marks the spot!)
  - `%d` / `%i` - Signed integers (doubloons counted)
  - `%u` - Unsigned integers (pieces of eight)
  - `%x` / `%X` - Hexadecimal (ancient pirate codes)
  - `%%` - Literal percent (because even pirates need percentages)
  - `%f` - Floating point (the tide be changin')

- 🚀 **Arena allocation** - Fast memory management, no leaks on this ship!
- 🎨 **Bonus flags support** - Width, precision, and more formatting treasures
- 🌊 **Built on sealib** - Our very own pirate utility library

## 🗺️ Installation & Compilation

### Prerequisites
- `gcc` compiler
- `make`
- `git` (to clone the repository and fetch dependencies)

### Setting Sail

1. **Clone the repository:**
```bash
git clone git@github.com:almoraru/sea_printf.git
cd sea_printf
```

2. **Build the library:**
```bash
make
```

This will:
- Automatically clone and build the `sealib` dependency
- Compile all source files
- Create `libseaprintf.a` - yer treasure chest of functions!

3. **Build and run the test program:**
```bash
make test
./test_seaprintf
```

## 🏴‍☠️ Usage

### In Your Code

Include the header and link the library:

```c
#include "sea_printf.h"

int main(void)
{
    sea_printf("Ahoy, %s! Ye have %d doubloons!\n", "Captain", 1000);
    sea_printf("Treasure coordinates: %p\n", &main);
    sea_printf("Temperature: %.2f degrees\n", 23.45);
    return (0);
}
```

### Compiling Your Project

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lseaprintf -Lsealib -lsealib -I includes -I sealib/includes -o your_program
```

## 🗂️ Project Structure

```
sea_printf/
├── includes/
│   └── sea_printf.h          # Main header file
├── srcs/
│   ├── sea_printf.c          # Core printf implementation
│   ├── sea_printf_handlers.c # Format specifier handlers
│   ├── sea_printf_arena.c    # Arena allocator
│   └── sea_printf_bonus.c    # Bonus flag parsing
├── sealib/                   # Pirate utility library (auto-cloned)
├── test_main.c               # Test suite
├── Makefile                  # Build configuration
└── README.md                 # Ye be here!
```

## 🧭 Makefile Commands

| Command | Description |
|---------|-------------|
| `make` or `make all` | Build the `libseaprintf.a` library |
| `make test` | Build library and create test executable |
| `make clean` | Remove object files |
| `make fclean` | Remove all generated files (library, objects, test executable, sealib) |
| `make re` | Rebuild everything from scratch |

## ⚔️ Technical Details

- **Memory Management**: Uses arena allocation for efficient memory handling
- **Dependencies**: Requires `sealib` (automatically fetched)
- **Compilation Flags**: `-Wall -Wextra -Werror -g`
- **Output**: Static library `libseaprintf.a`

## 👥 Crew

- **Swittzy** - *Captain of the Code*
- **espadara** - *Master Navigator* <espadara@pirate.capn.gg>

## 📝 License

This project be sailing under the MIT License. See the `LICENSE` file fer details.

## 🌊 Fair Winds and Following Seas!

May yer code be bug-free and yer coffee be strong! ☕🏴‍☠️

```
     ~    ~   ~  ~     ~    ~ ~  ~      ~     ~  ~
  ~    ~  ~    Sail on, brave coder!   ~    ~    ~
~    ~      ~     ~    ~    ~    ~   ~      ~    ~
```

---

*"In code we trust, in pirates we sail!"* ⚓
