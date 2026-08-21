# 🚀 Welcome to Project & Portfolio!


# Project & Portfolio 1

### Evan Kesler

Hello my name is Evan Kessler. I am a student from Illinois. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week


🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

![⚙️](https://discord.com/assets/7afdc0163bb3fba3.svg) Overview – What did you work on this past week?
I worked on making map generation, and settings to customize the map. The map displays players and enemies, and the player is able to move using WASD. Sadly you do have to press enter after each movement input but that's ok. 
![🌵](https://discord.com/assets/37be3ccf68ee491b.svg) Challenges – What obstacles did you encounter, and how are you addressing them?
Like I said, you have to press enter after every WASD press. Not ideal but in the end I had to settle for it because I don't want to use getch(). I also had some trouble later on in creating the player movement because at first I never actually assigned a player to each tile. Instead each tile just detects what type of entity is on it. If I had made it so it actually had an entity object assigned, I think certain things would have been made easier. 
![🏆](https://discord.com/assets/f11aff9f1c8c5f19.svg) Accomplishments – What is something you learned, improved, or "leveled up" on this week?
I've learned a lot so far like how to keep my main.cpp much more clean. I think I'm starting to improve on my layered thinking. For example making children classes for the entity class. The entity class has a player child class, which then goes into the map class. It's like multiple layers and that aspect always threw me off but I'm improving. 
![🔮](https://discord.com/assets/b1b7b56fe20bf6c6.svg) Next Steps – What do you plan to prioritize before your next milestone?
For my next milestone I want to have basic combat done. I want a combat screen to initiate when a player and enemy collide on the map. It will be a basic rock paper scissors system to keep things simple. Once that's done I'll have a very basic functional game and I'll be able to add my further plans in, such as items and multiple levels. But that's further in the future. Next week should just be basic combat.

### Week 2

 Overview – What did you work on this past week?

This week I worked on adding the combat system and refining user input. The basic combat is now fully finished and the game has a proper game loop, entering a new floor on beating all enemies or returning to the main menu if the player health reaches 0.

 Challenges – What obstacles did you encounter, and how are you addressing them?

This week went surprisingly smooth honestly but it was difficult keeping track of my menu system. Stuff like when each loop ends which will return to the previous menu. Writing stuff out in mspaint helped a lot haha.

 Accomplishments – What is something you learned, improved, or "leveled up" on this week?

I think I'm doing better with my understanding of pointers.

 Next Steps – What do you plan to prioritize before Week 3?

Going into week 3 my priorities are to plan out how I want to make the gameplay more interesting. I have plans for the player getting a powerup at the end of each floor and possibly adding different types of tiles like treasure tiles.

### Week 3

 Overview – What did you work on this past week?

The past week has been huge for improving actual gameplay. The biggest thing I've added is a whole powerup system so the player gets powers between floors. Different enemies also behave differently, making the game easier if you know which enemy does what.

 Improvements – What changes, refinements, or new features did you make?

I improved the general gameplay loop. With everything added the player can now actually beat floor 1 way more often. Before it was difficult and too luck based. I refactored some repetitive code by putting them in methods, and started using enums for previous and new things instead of strings.

 Challenges – What obstacles did you encounter, and how are you addressing them?

Oh boy I had one major pain this week. An extra enemy was being generated in my enemies vector, which would make it so sometimes an enemy doesn't disappear and is replaced by a new one. Debugging this took a good amount of time.

 Feedback – What feedback have you received, and how will it influence your next steps?

Kari was king enough to give me a suggestion for refactoring, so going forward I'll look out for repetitive code and turn that code into their own methods.

 Next Steps – What is your primary goal for Week 4?

The overall goal next week is to polish it and make it look nice. I hope to get a couple more features in though like scaling enemies and adding new enemies

### Week 4

My final stand up...
