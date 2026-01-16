# TurtleC – A Simple Turtle Graphics ASCII Implementation in C Using Bresenham’s Line Algorithm

This project was created to revive my C programming skills after not coding in C for a long time. It also serves as a foundation for building my own tools for drawing graphics directly in the terminal for future projects.

In addition, the project explores the basics of graphics programming by implementing a version of **Bresenham’s Line Algorithm** to draw lines in a discrete ASCII environment.

---

## Example from the Program

Below is a simple example demonstrating how just a few lines of code can generate a star using the turtle graphics system.  
The code for this example can be found in the `main` function of the program.

<p align="center">
  <img src="https://github.com/user-attachments/assets/25bd9371-c34a-4121-a51b-95d8983f3d03" alt="TurtleC example output" width="235"/>
</p>

---

## Bresenham’s Line Algorithm

Bresenham’s Line Algorithm is an elegant and efficient way to draw straight lines in a discrete grid. The algorithm works by deciding whether it is preferable to step in the x- or y-direction based on which choice minimizes the distance to the ideal continuous line.

One of the most interesting aspects of the algorithm is that it relies solely on simple integer arithmetic—using no division and minimal multiplication—which makes it extremely efficient and well-suited for low-level graphics programming.

---

## Further Improvements

There are many possible improvements that could be made to this project. Some interesting directions include:

- The program is currently not optimized beyond the choice of algorithms. Profiling and optimizing bottlenecks could significantly improve performance and reduce code size.
- Moving from terminal-based ASCII graphics to rendering in an actual graphical window would be a natural next step.
- Exploring a GPU-focused implementation for faster and more advanced rendering.
