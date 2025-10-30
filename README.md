# 🗺️ Fil de Fer – Wireframe Map Renderer

FdF is a learning project that introduces students to computer graphics and 3D representation using C.
The goal is to create a simple program that takes a map of height values (a .fdf file) and displays a 3D wireframe model of the terrain using isometric projection.

## 🚀 Features

- Renders a 3D wireframe map from a 2D grid of height values and colours (rgb).
- Smooth rendering using the MiniLibX graphics library.
- Bresenham’s line algorithm for drawing lines efficiently.
- Displays realistic depth effects through color gradients.
- Custom map files supported — you can create and visualize your own landscapes!
- Bonus features: Supports rotation, zoom, and translation for better visualization.
  
## 🧩 Requirements

- Use of C and the MiniLibX library.
- Use of own libft and ft_printf
- Allowed external functions: open, close, read, write, malloc, free, perror, strerror, exit, gettimeofday(), all functions of the math library 
- Global variables are forbidden
- Manual memory management and error handling
- The coordinates of the landscape are stored in a .fdf file, provided as a command line parameter to the program
- The program has to represent the model in isometric projection
