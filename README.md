# 🗺️ Fil de Fer – Wireframe Map Renderer

FdF is a learning project that introduces students to computer graphics and 3D representation using C.
The goal is to create a simple program that takes a map of height values and colours (a .fdf file) and displays a 3D wireframe model of the terrain using isometric projection as first view. Features for rotating and translating the view, for zooming in and out and changing the z scale of the map enhance the project. 

## ✨ Features

- Renders a 3D wireframe map from a 2D grid of height values and colours (rgb).
- Smooth rendering using the MiniLibX graphics library.
- Bresenham’s line algorithm for drawing lines efficiently.
- Displays realistic depth effects through color gradients.
- Custom map files supported — you can create and visualize your own landscapes!
- Bonus features: Supports rotation, zoom, and translation for better visualization.

## 🛠️ Installation
### Requirements
- Linux
- gcc
- make
- XWin library
### Build
```
//Install dependecies
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
//Clone the directory
git clone https://github.com/atoepper/FDF.git
//Create the minilibx
cd FDF/mlx_linux && make
//Compile the project and create the executable
cd .. && make
```
## ▶️ Usage
### Run the shell:
```
./fdf test_maps/<filename>.fdf
```
### Features:
- rotation on z axis: `Arrow left` & `Arrow right`
- rotation on x axis: `Arrow up` & `Arrow down`
- translation: `A` & `W` & `S` & `D`
- zoom in/out: `-` & `+`
- increase/decrease z scale factor: `Page up` & `Page down`

### Exit the Window:
- press `ESC` or click on `x`.

## 📚 Constraints & Requirements
This project follows 42 School constraints:
- Use of C and the MiniLibX library
- Use of own libft and ft_printf
- Global variables are forbidden
- Manual memory management and error handling
### Allowed functions:
- `open`, `close`
- `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `exit`
- `gettimeofday`
- all functions of the math library

## 🏗️ Architecture Overview

Corner stones and flow:
parsing of the map → calculating the first view → initialising the mlx window → setting hooks → rendering loop

### Parsing
The map file should look like 
```
Height(,Colour) Height(,Colour) Height(,Colour)
Height(,Colour) Height(,Colour) Height(,Colour)
Height(,Colour) Height(,Colour) Height(,Colour)
...
```
with Height as an integer value and Colour a hexadecimal rgb value in the form of 0x000000. So i use a simple combination of my `ft_split()` and some validation functions to parse the elements while making sure that every line has the same amount of elements.
Height and colour are stored in two arrays (`long **h`,`long **col` that are part of my `struct s_map`.

### Calculate the projection
To get the coordinates for the projection i apply the following operations on the array `t_map->h`
Transfer to carthesian coordinates → Add zoom → Rotate → Translate 
```
int	project_map(t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			map_to_cartesian(map, i);
			zoom(map, i);
			rotate(map, i);
			translate(map, i);
		}
	}
	return (0);
}
```
To calculate the first view, an isometric projection, i use an rotation vector with `map->rot.x = (atan(1 / sqrt(2))); map->rot.y = (0); map->rot.z = (PI / 4);` and roughly calculate a zoom factor and z scale factor considering the maximum x and y values of a thus rotated rectangle. The values of the calculated vectors are stored in `t_vector **proj`. 

### MLX and Hooks
After initializing the mlx_win and creating a window and a first image, the hooks for `KeyPress` and `KeyRelease` are set. The pressing/releasing of a certain key will set a flag that causes the according projection vectors to be manipulated correctly during the main loop.

### Rendering
During the main loop that runs with a chosen value for frames per second, calculates the new projection, based on the manipulated vectors for rotation, zoom and translation and uses the Bresenham algorithm to draw the lines between neighboured coordinates into a new image, that is loaded into the xwindow. 

## 📜 License
This project is part of the 42 School curriculum and is intended for educational purposes only.
