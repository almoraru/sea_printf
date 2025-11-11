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

**A pirate's implementation of printf, sailing the C seas with ZERO mallocs!**

> *"Why use the landlubber's printf when ye can have yer own sea_printf, free from the chains of heap allocation?"*

## 📜 About This Treasure

**sea_printf** be a custom implementation of the mighty `printf` function, crafted by the hands of **Swittzy** and **espadara** aboard the good ship *Code Kraken*. This library be built with performance and memory efficiency in mind, using **pure stack-based buffers** with nary a malloc in sight!

## ⚓ Features

### 🚀 **Zero Malloc - Pure Stack Power!**
- **No heap allocations** - All operations use fixed 4KB stack buffers
- **Predictable memory usage** - No fragmentation, no leaks, no surprises!
- **Embedded-friendly** - Perfect for systems where malloc be forbidden
- **Lightning fast** - No malloc overhead, just pure speed!

### ⚡ **High Performance**
- **4KB output buffer** - Reduces system calls dramatically
- **4KB conversion buffer** - Handles all number-to-string conversions in place
- **SIMD-optimized operations** - Uses fast `sea_memcpy_fast` from sealib
- **Cache-friendly** - Buffers sized perfectly for L1/L2 cache

### ✨ **Full printf compatibility** - All yer favorite format specifiers
- 🎯 **Conversion specifiers supported:**
  - `%c` - Character (a single letter from the treasure map)
  - `%s` - String (tales of the seven seas)
  - `%p` - Pointer (X marks the spot!)
  - `%d` / `%i` - Signed integers (doubloons counted)
  - `%u` - Unsigned integers (pieces of eight)
  - `%x` / `%X` - Hexadecimal (ancient pirate codes)
  - `%%` - Literal percent (because even pirates need percentages)
  - `%f` - Floating point (the tide be changin')

- 🎨 **Bonus flags support:**
  - Width specifiers (`%10d`)
  - Precision (`.5f`)
  - Left-align (`-`)
  - Zero-padding (`0`)
  - Sign flags (`+`, ` `)
  - Alternate form (`#`)

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
│   ├── sea_printf_buffer.c   # Buffer management (malloc-free!)
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

### Memory Architecture
- **Zero heap allocations** - Everything uses stack-based buffers
- **Dual 4KB buffers:**
  - Output buffer for final formatted text
  - Conversion buffer for number-to-string operations
- **Automatic flushing** when buffers fill
- **No malloc, no free, no leaks!** 🎉

### Performance Benefits
- **Reduced system calls** - Buffered output means fewer `write()` calls
- **No malloc overhead** - Eliminates heap allocation/deallocation time
- **Cache-friendly** - 4KB buffers fit perfectly in CPU cache
- **SIMD operations** - Uses optimized `sea_memcpy_fast` from sealib
- **Predictable performance** - No surprise GC pauses or allocation delays

### Perfect For
- 🔧 **Embedded systems** - Where malloc might not even exist
- ⚡ **Real-time applications** - Predictable, deterministic behavior
- 🎮 **Game development** - No allocation spikes during gameplay
- 🔒 **Systems programming** - When you need total control over memory

### Compilation
- **Flags**: `-Wall -Wextra -Werror -g`
- **Output**: Static library `libseaprintf.a`
- **Dependencies**: Requires `sealib` (automatically fetched)

## 👥 Crew

- **Swittzy/espadara/almoraru** - *Captain of the Code*

## 📝 License

This project be sailing under the MIT License. See the `LICENSE` file fer details.

## 🌊 Fair Winds and Following Seas!

May yer code be bug-free, yer buffers never overflow, and yer malloc count stay at zero! ☕🏴‍☠️

```
     ~    ~   ~  ~     ~    ~ ~  ~      ~     ~  ~
  ~    ~  ~    Sail on, brave coder!   ~    ~    ~
~    ~      ~     ~    ~    ~    ~   ~      ~    ~
```

---

*"In code we trust, in pirates we sail, and in stack buffers we prevail!"* ⚓

> **Pro tip**: No mallocs were harmed in the making of this library! 🏴‍☠️
