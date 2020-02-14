# Project 2
For this project you will write a class and a nontrivial method (or function). 
You will use it all in a program with smart pointers and optionals. 
You will write a testing suite to ensure your program functions properly.


## Requirements
- [x] All of your programming files should be in a private GitHub repository in your section’s organization.
    - [x] The repository must be named with your initials + dash + Project2 (e.g. LD-Project2).
    - [x] The repository should have a `.gitignore` file and a README file.
    - [x] You may reuse your code from Project 1 if you want, but you have to create a new repository.

- [x] **Firstly**, in a header file, declare a class that has at least three fields and at least one method that is not a 
constructor/destructor/getter/setter. 
Why did you choose this class?
    >I chose to use the class I made for Project 1 since I was pretty happy with the results, but I found it to be a little messy. 
    Perhaps I will be able to clean it up a bit in this project.
    
    - [x] One of the fields must be an optional. 
    Why does it make sense for this field to be an optional?
        >I made the `delay` field an optional because a user may not care about the delay between the notes. If they just want the default delay
         then the field will remain a `nullopt` and proceed to play using the default delay.                                                                                        
    - [X] You must use at least one smart pointer in your program, either in your class/function(s) or in your main program. 
    Why did you use a pointer here?
        >I made the Piano object a unique pointer in `main.cpp` because I wanted this one pointer to be the only thing accessing this one object.
    - [x] If you are reusing your class from Project 1, declare a new global function that uses at least one object of the class. 
    Why did you choose this function?
        >I made the `resultsAndPlayAgain` function which shows the music currently stored in the piano object, and asks the user if they would like to hear it again.
        
- [ ] **Secondly**, write test cases for the methods/function(s) in a `testing.cpp` file. Commit to GitHub.
    - [ ] If you are reusing code from Project 1, you still need to write test cases for that code (as well as for the new global function).
    - [x] Put an add_executable line in CMakeLists.txt to create an executable for your testing program.

- [ ] **Thirdly**, implement the methods/function(s) in a `.cpp` file. 
Did all of your test cases pass on the first try? Commit to GitHub.
    >a
      
- [ ] **Fourthly**, add more test cases now that you have finished implementing the methods/function(s). 
Why do you think you did not have these cases before you implemented the algorithm(s)? Commit to GitHub.
    >a
    - [ ] In your README file, you must write answers to all of the above questions.
    
- [x] **Fifthly**, write a `main.cpp` that creates a fully functioning, creative, and impressive program.
    - [x] The program should use the optional field of the class in some way.
    - [x] The program should use at least one smart pointer.
    - [x] Put an `add_executable` line in` CMakeLists.txt` to create an executable for your main program.

- [x] Your `main.cpp` and `testing.cpp` should both have a main function.
The two `add_executable` lines will ensure that you are not running these simultaneously.
    - [x] Make sure that the two `add_executable` lines create executables with different names 
      (i.e. the first argument to the function call must be different).

- [ ] All of the above must be committed and pushed to your GitHub repository.

- [ ] On Gradescope, submit the URL of the repository in a file named submission.txt.

## Grading
The project is out of 70 points.
- 5 pts Project compiles and runs. GitHub repository includes all files as described above.
- 5 pts Good coding style and consistent style throughout project.
- 5 pts Commits as described above.
- 10 pts Class satisfies requirements described above.
- 15 pts Testing is robust and readable.
- 10 pts Main function uses the optional field from your class and at least one smart pointer.
- 15 pts Main program is fully functional, creative, and impressive.
- 5 pts The README file contains all that is described above. It is readable and grammatically correct.