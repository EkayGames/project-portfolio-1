
## Features Added
- Powerup menu after beating floor
- Powerups that apply to the player for the rest of the run
- Enemy behaviors
## Refactoring Improvements
- Made tile entity type variable use an enum instead of string
- Changed nested do while loops in powerup generation to be one separate method
- The player is now generated separately before map generation so player can keep data between floors

## Testing Completed
- Tested if Powerup menu opens
- tested if powerup menu displays text properly
- tested if powerups roll no duplicates
- tested if powerups apply changes to player object
## Challenges
- Enemies were occasionally not being removed from the map upon beating them
- Changing names caused an infinite loop which made the powerup menu blank
## Next Steps