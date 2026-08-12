> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Battlegrounds
  
**What does your program currently do? (1–3 sentences)**   
→ Currently my project has a main menu with options to start, or edit settings. In Settings you can change the map length height and width, and the enemy count. When starting it generates a grid of tiles with the input height and width, or with the default of 5x5. One player is generated represented by P, and enemies are generated represented by E. Pressing W A S or D and then enter, moves the player up left down and right.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   Basic map generation and display work. Settings menu works and user cannot input numbers out of specific ranges.
  
**What is NOT working or incomplete?**   
→   The battle system isn't implemented yet. When an enemy and a player collide nothing happens.
  
**What feels confusing or messy in your code?**   
→   The way I implemented entity and map updates is pretty weird. I think I could've done it better. Each tile doesn't actually store an entity object in it, instead storing a string of what entity is on it, which is updated by the map class detecting if the tile position and entity position match.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Battle system
  
**What does this feature do?**   
→   When an enemy and player collide, it should open a battle menu, potentially with some ascii art of an enemy. The combat will be basic rock paper scissors where you pick from 3 options and each option wins or loses to each other.
  
**Why is this feature important?**   
→   Essentially the core gameplay of the game. Without it it's just a map simulator.
  
---
### Feature 2  
**Name:**   
→   Loss screen and temporary "win" screen
  
**What does this feature do?**   
→  Upon defeat user will see a screen stating they've lost and allow them to return to the main menu. If all enemies are defeated a screen will say they won and let them go to the main menu. The win screen will only stay in the game if there is no time for feature 3.
  
**Why is this feature important?**   
→   This lets the program actually loop instead of nothing happening when the last enemy or the player is defeated.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Endless levels
  
**What does this feature do?**   
→   Make it so after the last enemy is defeated a new map is generated but the player's health stays the same.
  
**Why is this feature important?**   
→   Allow endless gameplay, offering a much more enriching experience.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   A battle class to handle all battle logic.
  
**Will you modify any existing classes? How?**   
→   The menus class will need to be modified to add a combat menu and call logic from the battle class
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   No new data structures should be needed for these features, but the vector containing the enemies will need to be modified as enemies are removed.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Main menu appears
2. User chooses →   Start or settings
3. Program responds →   Opening map or settings menu
4. Loop/next step →   Player completes game or finishes changing settings, and returns to main menu.

---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Make sure menus are organized neatly and have good placement.
  
- Better error handling:   
→   Make sure user can never enter a number that would exceed specific ranges and prevent user from starting game if enemy count is too high.
  
- Improved menu/navigation:   
→   Make control smooth and comfortable. Ideally should be able to comfortably play with left hand around WASD and right hand on Enter.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Detecting when the player collides with an enemy will be difficult, especially if I decide to make enemies move in the future.
  
**What is your plan if you get stuck?**   
→   Step back, think it through, carefully write down each step to keep track of everything.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Future planning and preparing. 
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Write and map down things more on paper (or mspaint)
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [x]   Detect player and enemy collision
- [x]   Create battle menu
- [x]   Create functioning battle system.
- [x]   Create win/loss screen.
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.
> Plan now but also debug later. Debugging should always happen. Nothing should work perfectly first try.