<snippet>
  <content>
# MTRX3700 - Team Archibald

Track an RF-screeching parrot (strangely in ASCII 'e') with a robot. 

## To do

TODO: SW defined serial. <br />
TODO: XBee API Mode driver. <br />
TODO: Joystick. <br />
TODO: Hardware for controller. <br />
TODO: FSM for main.c into a separate file. <br />
TODO: PID for motors <br />

## New to git? 

If you're new to git, please have a look at awesome tutorials here: <br />

https://try.github.io/levels/1/challenges/1 <br />
https://github.com/jlord/git-it-electron <br />

## Naming Conventions

For functions, let's use the C naming standard, and for variables, let's use Java standard. I noticed that using Java standard for everything is a bit useless in C. 

| Constructs | Convention |
| -----------| -----------|
| Functions | ``` This_Is_Function() ``` |
| Variables | ``` thisIsVariable ``` |
| #define (preprocessor) constants | ``` THIS_IS_CONSTANT ``` |
| Structs and Enums | ``` ThisIsStruct ``` |

```c
// Defining structs and enums 
typedef struct _SOMESTRUCT{
	int foo; 
	int bar; 
} SomeStruct;

typedef enum _SOMEENUM{
	FOO = 0, 
	BAR,	
} SomeEnum


// Using them
SomeStruct structInstance = {1, 1}; 
SomeEnum enumInstance = FOO; 
```

## Things that make the maintainer happy. 

If you're adding new .X project, please make sure to add /build, /dist and /nbproject/private entries to .gitignore file. <br />

</content>
</snippet>
