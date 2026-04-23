# 2d_tile_game

A 2D top-down game built with the MinilibX graphics library.

## Overview

2d_tile_game is a top-down 2D game where the player navigates a map, collects items, and reaches the exit. Maps are loaded from `.ber` files with pixel-art assets that scale based on map size.

## Features

- Custom map parser with validation (rectangular, enclosed walls, valid elements)
- Three asset resolutions (16x16, 32x32, 64x64) auto-selected by map dimensions
- WASD/Arrow key movement with movement counter
- Collectibles and locked exit mechanics (exit only opens after all items collected)
- Win screen on successful completion

## Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Exit game |

## Map Format

`.ber` files using these characters:

| Char | Element |
|------|---------|
| `1` | Wall |
| `0` | Floor |
| `P` | Player (exactly one) |
| `C` | Collectible (at least one) |
| `E` | Exit (at least one) |

Example (`maps/map1.ber`):

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Build & Run

```bash
make
./so_long maps/<map>.ber
```

### Makefile Targets

| Target | Description |
|--------|-------------|
| `make` | Full build (clones mlx-linux, compiles everything) |
| `make clean` | Remove object files |
| `make fclean` | Remove all build artifacts including mlx-linux |
| `make re` | Clean and rebuild |

## Project Structure

```
.
├── main.c              # Entry point
├── so_long.h           # Main header
├── ft_map/             # Map parsing and validation
├── ft_game/            # Game loop, rendering, movement
├── libft/              # Standard library functions
├── ft_printf/          # Custom printf implementation
├── get_next_line/      # Line reader for map files
├── assets/             # XPM sprites (16/, 32/, 64/)
└── maps/               # Test .ber maps
```

## Requirements

- Linux with X11
- GCC
- Git (for cloning mlx-linux during build)
