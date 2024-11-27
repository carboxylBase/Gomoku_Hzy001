# Gomoku AI -- Hzy001
## Why did I develop this AI?
+ This is my metalworking internship assignment. Two other classmates and I need to collaborate to create a robot that can play Gomoku. This robot consists of three parts: mechanical control, vision system, and chess algorithm. The code for the chess algorithm is recorded in this repository.
+ In my freshman year, my C++homework was also Gomoku - a 2000+line C++file without header files, classes, encapsulation, or git. The only advantage was that it could indeed run. Now that I am a sophomore, I have participated in Robocup and ACM series competitions in the past year, and my engineering code and algorithm abilities have improved significantly. I want to develop a better AI based on my previous foundation.
+ I hope to complete the introductory learning of AI through this project.

## Why did I choose C++ to delelop this AI?
+ I usually only use C++ and am not familiar with other programming languages.
+ I prefer to build code from the bottom up and hope to write an entire framework on my own.C++is a relatively low-level language that meets my needs very well.

## What are the characteristics of this project?
+ **A Mode designed using the minimax algorithm**.This is a classic game algorithm, whose core idea is to maximize one's own score while minimizing the enemy's score.
+ **Chess record function**.I use ".gcm" format files to record the game records, whose main function is to record the order of the moves for later reproduction and other work.

---
# Update
## 2024.11.26
### Preliminary implementation of AI based on minimax algorithm.

Please allow me to briefly describe the design concept and principles:

As is well known, the core idea of the minimax algorithm is to maximize one's own score while minimizing the enemy's score. To achieve this in code, let's first think about how to describe this algorithm in mathematical language.

If we consider a chessboard state as a node on a decision tree, then for the current state, what we need to do is to select the optimal point from its many child nodes.We will simply design the score transfer equation as follows:

$Score(Fa) = max(Value(x,y)-Score(Son))$

Among them, $Son$ is a sub state of $Fa$, and the $Value$ function evaluates the value at (x, y).

The specific code implementation is in the $place$\_$min$\_$max$_$dfs$ function of Gomoku-Hzy001.cpp, and I have encapsulated all the necessary content for implementing the minimax algorithm in this function.

The following picture shows a game between me (white) and AI (black).

![minimax_demo](https://github.com/carboxylBase/Gomoku_Hzy001/blob/main/src/png/minimax_demo.png)

To be honest, I didn't give it my all. In the game, I also noticed some issues with it, such as a weak desire to attack. But overall, it is much stronger than the first generation Gomoku AI I created.
