# Solong
2D Game



Solong: A 2D SO_LONG
Solong is an exciting 2D adventure game where players take on the role of a character collecting valuable items and striving to reach the exit. This project combines the power of several components, including ft_printf, get_next_line, and minilibx, to deliver a captivating gaming experience.

Features
Collectibles: Players must gather valuable collectibles as they navigate through the game's levels.
Exit Point: The ultimate goal is to get all the collections and find the right path to reach the exit point.
Custom Printing: Leveraging the ft_printf project, we have custom terminal output for a seamless gaming experience.
Map Reading: Utilizing get_next_line, Solong can read map files to create dynamic and engaging levels.
Graphics: MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens It provides so-called simple window creation, a questionable drawing tool, half-ass image functions and a weird event management system.
Project Development
Algorithm Design
Before diving into coding, extensive algorithm design was carried out to ensure efficient and clear code structure. This meticulous planning phase laid the foundation for an organized and optimized project.
I believe this is very important and I try to implement it in every project. It is sustainability that will really make me an engineer.

Map Checks
The project begins with map checks, ensuring that the game environment is valid and error-free.
Each function has a clear purpose: we start by reading the map using get_next_line and then verify if the number of lines is consistent. Next, we perform a comprehensive map validation.
Afterwards, we check whether there is a path between the player and exit thanks to the fill_flood function, and whether it can collect all collectibles while doing this.
You want to see this recursive function.

MiniLibX Implementation
The implementation of minilibx was a pivotal moment in the project. It enabled us to render images and create the visual aspects of the game.

Key Handling
To provide smooth gameplay, key handling functions were developed to control player movement. These functions enhance the overall user experience.

Code Quality
Every function within the project adheres to a high standard of clarity and effectiveness. The main function is structured to optimize performance, resulting in a seamless gaming experience.

Memory Management
A rigorous approach to memory management has been taken to ensure a project free of memory leaks.

Get Involved
If you're interested in contributing to Solong or have any questions, feedback, or bug reports, please don't hesitate to reach out. Your involvement can help make this game even better.
You can use my email to contact me: [toktastuna@gmail.com]

Start the Game
When starting the game, we first compile all the files using the "make" command, thanks to our Makefile. Afterward, we execute the "./so_long" file, providing it with the necessary map as follows:

Run the command make.
Execute ./so_long maps/example.ber


Screenshots

<img width="2176" alt="SO_LONG" src="https://github.com/muzaffertuna/Solong/assets/92475119/a1f72730-a1c8-4681-b41a-13386cecec04">




