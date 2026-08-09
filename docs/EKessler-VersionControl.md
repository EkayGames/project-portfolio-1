# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [COS119-0]

- [**Evan Kessler**]
- [**8/8/2026**]

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [CLS]: Clear the Screen
- [ PWD]: Print the "Working Directory"
- [ LS ]: List files and folders
- [ LS -force ]: List files and folders, including invisible files
- [ tree /f ]: List all files and folders, in human readable form
- [ CD ]: Change directory
- [ CD \ ]: Change directory, go to root directory
- [ CD ~ ]: Change directory and go to user home directory
- [ CD .. ]: Change directory, go up one folder level
- [ CD ../.. ]: Change directory, go up two folder levels
- [ CD ~\Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ Visual studio tries to open everything in the folder as projects or something. I assume it's supposed to copy the directory link of the folder into the terminal but that did not work for me. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local version control: Stores all project versions on one computer. Typically one user. No online functionality.]
[Centralized version control: All versions are stored in a single server. Multiple workers connect to the server to commit and update their local versions.]
[Distributed version control: Each worker has an extra local repository which is connected to the central server. Workers commit and update to their local repository, then push and pull from the main repository.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone (url) ]: Clone a repository
- [ git config --global user.name "(name)" ]: Set-up a global user name
- [ git config --global user.email “(email)” ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add (file) ]: Add modified files to the next commit
- [ git commit -m (message) ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Install git Git onto your computer.  Set your username and email with the terminal. Clone or add your repository with the terminal then log in and cache credentials with GCM]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [.gitignore determines which files should be ignored and not tracked in version control. Keeps the repository clean and prevents unnecessary files.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [A macOS file that stores certain attributes of a folder. Holds unnecessary information for a repository such as icon positions]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [Logs are unnecessary to add to a repository because they store local data and aren't needed for a repository to function.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: Actual Git documentation was most helpful but people had very good resources like lists of commands. ]

**Terminal Commands**  
[Site Address](https://gist.github.com/bradtraversy/cc180de0edee05075a6139e42d5f28ce)
[Site Address](https://www.pdq.com/powershell)
**Three Types of Version Control**  
[Site Address](https://www.geeksforgeeks.org/git/version-control-systems/)

**Git Commands**  
[Site Address](https://education.github.com/git-cheat-sheet-education.pdf)

**Connecting to GitHub using Terminal**  
[Site Address](https://docs.github.com/en/get-started/git-basics/set-up-git)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.geeksforgeeks.org/git/what-is-git-ignore-and-how-to-use-it/)
