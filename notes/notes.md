
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------
																			 |
### 9.1 — Introduction to testing your code    								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------


### The Testing Challenge

 **Notes:** 
* Testing every single possible input combination is mathematically impossible for most programs. 
* Instead, rely on testing different logic paths (e.g., `<`, `>`, `==`) just a few times to gain confidence that the logic holds.

* **To Remember:**
* [ ] Avoid trying to test every possible input.
* [ ] Identify and test the distinct logic cases in your code.



### Test Your Programs in Small Pieces

* **Notes:** Writing the entire program before testing makes finding the source of a bug incredibly difficult. 
* Testing small, isolated units of code (unit testing) allows you to catch and fix errors immediately before they cause "ripple effects" across your project.

 **To Remember:**
* [ ] Write your program in small, well-defined units (functions or classes).
* [ ] Compile often.
* [ ] Test your code as you go, rather than waiting until the end.



### Informal Testing (Temporary Testing)

* **Notes:** This involves writing temporary test code (usually in `main()`) to verify a newly written unit, then deleting it once the test passes.

**To Remember:**
* [ ] Use informal testing for quick, on-the-fly validation.
* [ ] Recognize that deleting the tests means you can't easily re-verify that code later.



### Preserving Your Tests - Manual Console check happens here

* **Notes:** Instead of deleting your informal tests, move them into a dedicated testing function (e.g., `testVowel()`). 
* This saves your test cases so you can run them again if you modify the code in the future.

**To Remember:**
* [ ] Keep your tests around to ensure future updates don't break existing, working code.



### Automating Your Test Functions 

* **Notes:** Manually reading test output to see if it matches the expected result is tedious. 
* You can automate this by having your test function compare the actual output against the expected output and return an error code if they don't match (or `0` if all pass).

**To Remember:**
* [ ] Write test functions that do the validation for you.
* [ ] Return a specific fail state or success state so you only need to check one result.



### For Advanced Readers (Using `assert`)

* **Notes:** Instead of manually returning error codes, you can use `assert` from the `<cassert>` library. 
* It automatically halts the program and prints an error message if a test fails.

**To Remember:**
* [ ] Use `assert()` to force the program to abort on a failed test case.
* [ ] Remember that asserts can be compiled out by defining `NDEBUG`.



### Unit Testing Frameworks

* **Notes:** Because unit testing is so common, third-party software frameworks exist entirely to help you write, maintain, and execute tests.

**To Remember:**
* [ ] Be aware that tools exist to handle testing infrastructure for larger projects.



### Integration Testing

* **Notes:** After testing isolated units, you must test them together to ensure they interact correctly. This is usually more complicated than unit testing.

**To Remember:**
* [ ] Run the program a few times after integrating new units to spot-check their combined behavior.



# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------




# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------

* Assert header and its define performs a Magic as it will read again the preprocessor steps like to be read multiple times if declared anywhere.



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------
																			 |
### 9.2 — Code coverage						  								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------

Code Coverage
Notes: Code coverage is a metric used to describe how much of your program's source code is actually executed while running your tests.

To Remember:

[ ] Use coverage metrics to evaluate how thorough your testing routines are.


Statement Coverage
Notes: This measures the percentage of individual statements in your code that are exercised by your tests. 
While hitting 100% statement coverage is a good goal, it is rarely enough to guarantee the code is perfectly correct.

To Remember:

[ ] Call your functions enough times to execute every line of code inside them.

[ ] Don't rely on statement coverage alone to prove your code has no bugs.


Branch Coverage
Notes: This measures the percentage of branches (like the true and false paths of an if statement, or various cases in a switch) that have been executed. 
Each possible path is counted separately.

To Remember:

[ ] Test all possible outcomes for your conditional statements (both the positive and negative use cases).

[ ] You don't need to separately test multiple switch cases if they all feed into the exact same body.

[ ] Best Practice: Aim for 100% branch coverage.



Loop Coverage
Notes: This is used to ensure loops function properly by testing them with a specific set of iteration counts, informally known as the 0, 1, 2 test. 
Since a loop can't execute a negative number of times, these tests cover all foundational possibilities.

To Remember:

[ ] Test the loop when it iterations 0 times.

[ ] Test the loop when it iterates 1 time.

[ ] Test the loop when it iterates 2 times (if it works for 2, it should logically work for anything > 2).

[ ] Best Practice: Always use the 0, 1, 2 test for loops.



Testing Different Categories of Input
Notes: When functions accept parameters or user input, you should test different sets (categories) of inputs 
that share similar characteristics to ensure the unit handles them properly.




# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------

[ ] Floats/Doubles: Test values with potential precision issues (e.g., numbers slightly larger than expected like 0.1 and slightly smaller like 0.7).

they have diff precision except 0.5 - which has accurate precision (seems fraction of 2^10 could be accurate like 1/2, 1/4....etc?)

## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------

To Remember:

[ ] Integers: Test negative values, zero, positive values, and check for overflow.

[ ] Floats/Doubles: Test values with potential precision issues (e.g., numbers slightly larger than expected like 0.1 and slightly smaller like 0.7).

[ ] Strings: Test empty strings, valid alphanumeric strings, and strings with varying whitespace (leading, trailing, inner, or all whitespace).

[ ] Pointers: Remember to test with nullptr.


# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.3 — Common semantic errors in C++										 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------


    C++ PROGRAMMING
                       │
        ┌──────────────┴──────────────┐
        ↓                             ↓
   Syntax correctness          Semantic correctness
        │                             │
   "Does C++ understand       "Does the program do
      this code?"                 what I intended?"
        │                             │
        └──────────────┬──────────────┘
                       ↓
                Correct Program

# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


🔴 Conditions

=       // assign
==      // compare

if (x = 5)    // BUG: assigns
if (x == 5)   // compare

Mental check

"Am I changing the value or checking the value?"

🔄 Loops

Ask 3 things:

1. Where does it start?
2. What makes it stop?
3. What moves it toward the stop?

Watch for:

while (...) { }       // infinite loop risk
unsigned count = 0;   // decrement → wraparound

🎯 Off-by-one

<     → excludes the limit
<=    → includes the limit

Ask:

"Should the boundary be included?"

🧠 Operator precedence

If an expression makes you think twice:

if (!x > y)

don't guess.

Use:

if (!(x > y))

Parentheses beat memory.

🔢 Types change behavior

5 / 3                  // 1
static_cast<double>(5) / 3  // 1.666...

Also remember:

unsigned → no negatives
float/double → precision is limited

💀 Tiny syntax, huge consequences

if (x);       // empty statement

if (x)
    a();
    b();      // b() is NOT inside if

Best:

if (x)
{
    a();
    b();
}

Braces make intent obvious.

📞 Function call

getValue()    // CALL function
getValue      // function itself

The second can undergo function-to-pointer conversion.

In a stream, you may see an address-like function pointer value.

() = DO ITno () = REFER TO IT


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------

When output looks weird, run this checklist:

□ Condition correct?
□ = vs == ?
□ Missing braces?
□ Accidental ; ?
□ Loop guaranteed to terminate?
□ Unsigned near 0?
□ Off-by-one?
□ Operator precedence?
□ Integer division?
□ Floating-point equality?
□ Forgot ()?
□ Compiler warnings checked?


🔥 The 10 Errors You Need to Remember
#	Error	Typical mistake
1	Conditional logic	
>= instead of >

2	Infinite loop	
Forgetting to update loop variable

3	Unsigned loop	
unsigned >= 0

4	Off-by-one	
< instead of <=

5	Operator precedence	
!x > y

6	Floating-point precision	
0.1 + ... == 1.0

7	Integer division	
5 / 3 == 1

8	Accidental null statement	
if (x);

9	Missing braces	
Only first statement belongs to if

10	= instead of ==	
if (x = 5)

11	Forgetting ()	
getValue instead of getValue()


# Best Practices

Whenever your program gives a weird result, ask:

□ Is my condition correct?
□ Did I accidentally use = instead of ==?
□ Did I forget braces?
□ Did I accidentally put ; after if/while?
□ Is my loop guaranteed to terminate?
□ Am I using unsigned near zero?
□ Did I make an off-by-one error?
□ Is operator precedence doing something unexpected?
□ Am I accidentally doing integer division?
□ Am I comparing floating-point values directly?
□ Did I forget () when calling a function?

# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------


The master model

SYNTAX
"What did I write?"
        ↓
SEMANTICS
"What does it mean?"
        ↓
INTENTION
"What did I actually want?"

The compiler checks the first two.

You must verify the third.




# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------


✓ Compiles ≠ Correct
✓ Valid C++ ≠ Correct logic
✓ Indentation ≠ control flow
✓ Types affect behavior
✓ Tiny symbols can change everything
✓ Context changes meaning
✓ Tests catch semantic mistakes

------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.4 — Detecting and handling errors                                      |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------

    
    When reality violates your assumptions, how does your program communicate that failure safely?


One final mental model :

Put this in your C++ brain's permanent storage:

             SOMETHING GOES WRONG IN A CALLEE FUNCTION
                     │
                     ▼
              Can I fix it here?
                /           \
              YES            NO
               │              │
          handle locally      ▼
                        Can I tell caller?
                           /       \
                         YES        NO
                          │          │
                    return error    fatal?
                    optional        │
                    expected        ▼
                                  terminate

                          OR

                       exception
                          │
                          ▼
                    propagate upward
                          │
                          ▼
                        catch

# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------

☐ A function can detect an error without necessarily being the right place to handle it.
☐ bool can communicate simple success/failure to the caller.
☐ A sentinel value is a special return value meaning “something went wrong”.
☐ Sentinel values are dangerous if that value can also be a valid result.
☐ std::optional<T> solves the “value or no value” problem cleanly.
☐ std::expected<T, E> can represent “value or specific error”.
☐ Exceptions allow an error to travel up the call stack until handled.
☐ std::cerr is intended for error/diagnostic output, not normal output.

## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------

* anticipate defensive programming (errors to happen and then handle)
* 
🧠 Error handling isn't just detecting errors. It's deciding who should handle them.
🔄 Detect → Communicate → Handle/Recover is the core pattern.
🚨 Not every error is recoverable. Some failures should terminate the program.
🧩 bool → success/failure
optional → value/no value
expected → value/error
exception → propagate failure
🎯 Happy path + failure path = complete program thinking.

# Best Practices


The hidden lesson: Defensive Programming

This connects directly to the previous lesson.

    New programmer:

    // Happy path only
readFile();
processFile();
saveFile();

    Experienced programmer:
    // Sad path assumptions
Can file fail?
Can input be invalid?
Can file be missing?
Can network fail?
Can memory allocation fail?
Can caller pass invalid arguments?
Can function return failure?



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------

☐ Errors are expected possibilities, not always bugs.
☐ First ask: “Who can handle this error?”
☐ Handle locally if the function can recover.

☐ Otherwise communicate failure to the caller.
   Common mechanisms: bool, sentinel value, std::optional, std::expected, exceptions.

☐ Sentinel values work only when the value cannot be a valid result.
☐ Fatal errors → terminate when continuing is unsafe.
☐ Use std::cerr for error/diagnostic output.
☐ Test the sad path, not just the happy path.

# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------

🧠 Error handling = Detect → Communicate → Recover/Terminate
🎯 The key design question: “Who is responsible for handling the failure?”
⚠️ Never assume a function succeeded just because it returned.
🔗 bool → simple success/failure.
🔗 optional → value may or may not exist.
🔗 expected → value or detailed error.
🔗 Exceptions → propagate errors up the call stack.
🧩 Robust programs are designed for failure paths, not only successful paths.

------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.5 — std::cin and handling invalid input                  				 |
																			 |
------------------------------------------------------------------------------

### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------



* First, leading whitespace (spaces, tabs, and newlines at the front of the buffer) is discarded from the input buffer (with after values if takes place).
* If the input buffer is now empty, operator>> will wait for the user to enter more data. Leading whitespace is discarded again and again and again....


* If any characters were extracted, extraction is a success. The extracted characters are converted into a value that is then assigned to the variable.
* If no characters could be extracted, extraction has failed. The object being extracted to is assigned the value 0 
  (as of C++11), and any future extractions will immediately fail (until std::cin is cleared).



# Hands-on Doubts Cleared -----------------------------------------------------------------------------------------------------------------------------------

* switch case labels act as entry point and goes downward including 'default' if there is no 'break' in 'case labels'.
* input buffer gets carried. next inputs msgs in console can be seen without input value as the buffer automatically inserts it from code.
* if the one line input data has valid values to keep in buffer, it gets carried properly without any 'cin' fail but the code structure view messed up.
* early 'return' preferable, an idiomatic C++ way to write this specific function. It is cleaner, shorter, and easier to read. 
* By removing the Loop flags (keepLog/isInvalid) or state variables (operation), you reduce the "cognitive load" (the amount of stuff a programmer has to keep in their memory while reading your code).


      !std::cin.eof() && std::cin.peek() != '\n' 
      
            ^                       ^
           true                    true             --> means, There is still input available (not a end of file), and the next character isn't the end of the current line (not a '\n' newline) 
                                                        then it has "un extracted values"..



                                                        The input stream hasn't reached its end, and the next character isn't a newline, so there may be unextracted input remaining on the current line.
```newline value```
As a character literal: '\n'
As a decimal number: 10
As a hexadecimal number: 0x0A



```eof```
* real eof sentinal value : -1
* decimal value in windows : 26


peek_1 == 26 ('\x1A') means the next byte in the input buffer is 0x1A (ASCII SUB, often Ctrl+Z on Windows). std::cin.peek() returned that value because the stream contains that character — it is not the EOF sentinel (-1).
Likely causes
•	The user or input file inserted a Ctrl+Z / SUB character.
•	Assigning stdcin.peek() directly to a char hides C++'s EOF sentinel (traits_typeeof()), so you can't reliably detect EOF that way.


peek_1 == 26 (0x1A) means peek() returned a real byte 0x1A (ASCII SUB, often Ctrl+Z), not the EOF sentinel (-1). The debugger shows the non-printable char as '\x1a' and the console renders a control-glyph (␦). You didn’t see an EOF sentinel because the stream actually had the 0x1A byte available.

Mechanism — step by step
•	stdcin.peek() returns an int-type (stdistream::int_type, usually an int). That return value is either:
•	traits_type::eof() (typically -1) to signal end-of-file, or
•	a non-negative integer representing the next character’s byte value (0..255).
•	If you store peek() into a char (char peek_1 = std::cin.peek();), you convert that int to char immediately. If peek() had returned EOF (-1) you would lose the ability to detect EOF because char cannot reliably represent the special EOF sentinel.
•	In your run peek() returned 26, so both:
•	int peek_2 == 26 (shows the numeric byte), and
•	char peek_1 == '\x1a' (debugger prints hex for a non-printable char). Those two are consistent: same byte, different view.
•	The console printed a control-picture symbol (␦) because consoles often display unprintable control bytes as glyphs; that’s a rendering, not an EOF marker.

Why you might see 0x1A instead of EOF
•	The input actually contains a SUB byte (you typed Ctrl+Z and it was delivered as data, or the piped/file input contains 0x1A).
•	On Windows, historically Ctrl+Z can be treated as EOF in some text modes, but behavior depends on how the runtime/console is configured; sometimes you still get the raw 0x1A byte.
Correct, robust pattern

        // cpp
        int ch = std::cin.peek(); // capture EOF sentinel (-1) if present
        if (ch == std::char_traits<char>::eof()) {
            // handle EOF
        } else {
            char c = static_cast<char>(ch);
            std::cout << "peeked: '" << c << "' (0x" << std::hex << ch << ")\n";
        }


Root cause and fix
•	Root cause: storing peek() directly into a char hides the EOF sentinel and mixes up "no-data" vs "a data byte with value 0x1A".
•	Fix: keep peek() in an int (or stdistreamint_type) and compare to EOF before converting to char.


# Core Concept -----------------------------------------------------------------------------------------------------------------------------------------------


cin >> :
            INPUT STREAM
                  │
                  ▼
        '1' '2' '3' '\n'
                  │
          ┌───────┴────────┐
          │                │
       formatted       unformatted
       extraction       extraction
          │                │
       >> int           get()
          │                │
    "interpret this"   "give me
          │             this char"
          ▼                ▼
       123               '1'




>>          → formatted extraction to the requested type
get()       → unformatted character extraction


    -------------------------------------------------                                                                    
    | std::cin >> value                             |                                                                            
    |         ↓                                     |                                                                                         
    | formatted extraction                          |                                                                                       
    |         ↓                                     |                                                                                                                                          
    | usually SKIPS leading whitespace              |                                                       
    |         ↓                                     |             
    | extracts the requested value                  |                                                                           
    |                                               |                                                                                 
    |------------------------------------------------
    |                                               |                 
    |                                               |                         
    | std::cin.get(ch)                              |     
    |         ↓                                     |     
    | character extraction                          |     
    |         ↓                                     |     
    | DOES NOT skip whitespace                      |     
    |         ↓                                     |     
    | takes whatever character is currently there   |     
    | ______________________________________________|                         




# Key Points to Remember ------------------------------------------------------------------------------------------------------------------------------------------------

* Input typed into the console becomes available in the standard input stream. 
* std::cin can later extract that input as the program requests it.
  (The value entered in the console becomes available in the input stream, and cin >> can extract it later anytime)


``` IMPORTANT cin FEATURES - std::cin input stream operations ```

* std::getline() - extracts characters from the input stream until it reaches a newline, and stores those characters as one complete line in a string.

* std::ws        - tells the input stream to consume and discard all whitespace characters currently at the beginning of the stream, such as spaces, tabs, and newlines.

* std::get(..)   - extracts the character at the current input position and advances the current position to the next character.
                    NOTE : it doesnt skips whitespaces.

* std::peek()    - looks at the character at the current input position and can return it,
                   but does not consume it or advance the current position.

* std::putback   - putback() adjusts the input sequence so the supplied character becomes available before that previously-next character.
                   it doesn't replaces the current character (which is pointed in input buffer). 
                   It makes X come before the character that was currently next to be extracted from input buffer.





But for your mental model:

getline()  → extract characters until '\n'
ws         → discard leading whitespace
peek()      → look at FRONT 👀
get()       → take from FRONT ✋ → FRONT moves forward
putback(c)  → put c at FRONT on current target position ↩️


std::cin.get()       → character-level extraction
std::getline()       → line-level extraction into std::string


┌──────────────┬──────────────────────────────────────┐
│ Operation    │ Visual behavior                      │
├──────────────┼──────────────────────────────────────┤
│ peek()       │ 👀 Look, DON'T consume               │
│              │                                      │
│              │ A   B   C   D                        │
│              │ ↑                                    │
│              │ └── stays here                       │
├──────────────┼──────────────────────────────────────┤
│ get()        │ ✋ Consume + MOVE →                  │
│              │                                      │
│              │ A   B   C   D                        │
│              │     ↑                                │
│              │     └── A consumed                   │
├──────────────┼──────────────────────────────────────┤
│ putback('X') │ ↩️ Make X available NEXT              │
│              │                                      │
│              │ A   X   B   C   D                    │
│              |    ↑                                 │
│              |    └── X is now next                 │
├──────────────┼──────────────────────────────────────┤
│ getline()    │ 📏 Consume until '\n'                │
│              │                                      │
│              │ S p i d e r   M a n \n               │
│              │ ↑──────────────────↑                 │
│              │     extract whole line               │
├──────────────┼──────────────────────────────────────┤
│ ws           │ 🧹 Remove leading whitespace         │
│              │                                      │
│              │ \n  \t  SPACE  →  🗑️                 │
│              │              ↓                       │
│              │          Spider Man                  │
└──────────────┴──────────────────────────────────────┘


# Important Classifications ----------------------------------------------------------------------------------------------------------------------------------



There are 3 basic ways to do input validation:

* Inline (as the user types):

      1. Prevent the user from typing invalid input in the first place.
    
* Post-entry (after the user types):

      2. Let the user enter whatever they want into a string, then validate whether the string is correct, and if so, convert the string to the final variable format.
      
      3. Let the user enter whatever they want, let std::cin and operator>> try to extract it, and handle the error cases.



4 Types of invalid text input


    1. Input extraction succeeds but the input is meaningless to the program (e.g. entering ‘k’ as your mathematical operator).
    2. Input extraction succeeds but the user enters additional input (e.g. entering ‘*q hello’ as your mathematical operator).
    3. Input extraction fails (e.g. trying to enter ‘q’ into a numeric input).
    4. Input extraction succeeds but the user overflows a numeric value



# How It Works   ----------------------------------------------------------------------------------------------------------------------------------------------


1. Console-la \n illana '\n' Type Pannal Enna Aagum?

Main Point: 
Console-la neenga literal ah \n illana single quotes oda '\n' nu type panna, program adha special "newline" command-ah eduthukkadhu. 
Verum normal text/symbols ah dhaan paakum.


Code vs Console Difference:

C++ Code-la: 
Neenga '\n' nu code la eludhuna, compiler adha purinjikittu orey oru invisible "newline" character-ah (ASCII 10) maathidum.


Console-la:
Console neenga type panradha compile pannaadhu. So, neenga '\n' nu quotes oda type panni Enter amukkuninga na, input buffer-la actually 5 different characters poi vizhum.


Buffer-la vizhum andha 5 characters (for '\n'):

        ' (Starting single quote)

        \ (Backslash character)

        n (Letter character)

        ' (Ending single quote)

Invisible newline character (Neenga Enter key press pannadhala create aaguradhu).


Simple ah sollanumna: 
Console-ku \n aagattum illana '\n' aagattum, ellame verum normal letters & symbols dhaan (just like typing 'A' or 'B'). 
Nijamaana "newline" buffer-ku poganum na, neenga verum Enter key dhaan press pannanum!


            ❌ What DOES NOT create a newline:

            * Typing the literal characters \ and n.

            * Typing '\n' with quotes.

            * Why? The console just reads these as ordinary, visible text data. It treats them no differently than typing "A", "B", or "C".



            ✅ What DOES create a true newline:

            * Physically pressing the Enter (or Return) button on your keyboard.

            * Why? The console hardware translates that specific physical button press into a special, invisible control signal (ASCII 10) and drops it into the input buffer.



            ✅ The "Submit" Effect:

            * Pressing Enter acts as your "Submit" button.

            * Until you press it, the console just holds onto whatever text you typed.

            * The moment you press Enter, it adds that invisible newline character to the very end and finally hands the whole line of text over to std::cin for your C++ program to process!




# Real-World Examples ------------------------------------------------------------------------------------------------------------------------------




# When to Use / When Not to Use ------------------------------------------------------------------------------------------------------------------------------



# Pros ------------------------------------------------------------------------------------------------------------------------------------------------------



# Cons / Limitations -----------------------------------------------------------------------------------------------------------------------------------------



# Best Practices ---------------------------------------------------------------------------------------------------------------------------------------------


# Nuances  ---------------------------------------------------------------------------------------------------------------------------------------------


| Concept / Character     | Character / Literal  | Decimal |        Hex | Glyph | Glyph Represents / Appears As                           |
| ----------------------- | -------------------- | ------: | ---------: | ----- | ------------------------------------------------------- |
|   EOF                   | No character literal |      -1 | 0xFFFFFFFF | —     | No glyph; EOF is a special `int` value, not a character |
|   Ctrl+D (Unix/macOS)   | '\x04'               |       4 |       0x04 | ␄     | EOT — End of Transmission                               |
|   Ctrl+Z (Windows)      | '\x1A'               |      26 |       0x1A | ␚ / ␦ | SUB — Substitute                                        |
|   Newline / Line Feed   | '\n'                 |      10 |       0x0A | ␊     | LF — Line Feed                                          |



* if existing input buffer is empty, cin.peek() waits the console for new inputs to store in buffer 
  and cin.ignore(..., delim) waits for given delim to be in buffer to continue for discarding all chars until the given delim.
  thats why im seeing the program got stuck with console in final as there is not inputs and buffer is empty !

* post ^Z char will discarded (eg: ash^Zweq) and pre chars before ^Z will be considered based on the input formats, but ^Z turns into unprintable char (glyph) not eof.
* eof is valid when ^Z comes 1st of input buffer


-> cin.peek() actually waits console for getting input incase if the buffer is empty

-> cin.ignore() used for ignoring the maximum buffer characters until a new line '\n', but the post ^Z(Ctrl+Z) can be not a valid for eof, but it also removes the trailing newline char in buffer
                        
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

 
```-------------- std::cin.peek() ------------------------------------------------------------------------------------------------------------```

  ○` Role:` Inspects the next character in the stream without extracting or advancing the
    stream position (LOOK 👀 + DON'T MOVE).

  ○ `Empty Buffer Behavior:` If the buffer is empty, it pauses and waits for user input so
    it has a character to inspect—it does not "pop" (consume) any character.

  ○ `Return Value:` Returns the ASCII integer code of the next character, or EOF (-1) if
    the input source has ended.


```-------------- std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') --------------------------------------------------------```

  ○` Role: `Extracts and discards all unread characters on the current line up to and
    including the '\n' delimiter.

  ○ `Buffer State After:` Leaves the buffer completely empty (the trailing '\n' is
    deleted, not left behind).

  ○` Prerequisite:` Requires the stream to be in a good state; if an extraction failed or EOF
    was encountered, call std::cin.clear() first so ignore() does not silently fail.


```Summary```

○ "Pop" vs. "Inspect": peek() never pops/removes anything; it only looks. The pause you
  see when the buffer is empty is simply the terminal blocking to wait for data.

○ Newline Removal: ignore() does not stop before '\n'; it extracts and discards
  '\n' as well, ensuring a clean buffer for the next line of input.


```--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------```
```--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------```



# Common Pitfalls / Gotchas ----------------------------------------------------------------------------------------------------------------------------------


Trailing Space Character

```Q: What happens if a user enters 25 followed by spaces and presses Enter?``` 

A: The program may ask for another input because peek() sees the trailing space as an actual character, 
so peek() != '\n' becomes true, even though the user sees nothing after 25 and thinks the input is complete.


# Things to Remember -----------------------------------------------------------------------------------------------------------------------------------------

* '\n' in C++ source code represents a newline character, but typing '\n' literally into the console does not create a newline. Pressing Enter does.
* '\n' is an actual character (ENTER key in our case) in the input stream, while EOF means no more characters are available, so they cannot occur at the same position.
* EOF and a newline can't happen at the exact same time.


```INPUTS SCENARIOS VALIDATIONS:```

Case 1: Numeric Start with `^Z`
  -> 12.2
  -> 12.2`^Z`12
  -> 12.2`^Z`abc

  Observations to Record:
    -> Glyph Occurrence: Note how `^Z` visually echoes in the terminal.
    -> Extraction: Verify if 12.2 extracts into x.
    -> std::cin.peek(): Check return value after extraction (char, decimal, and hex).
    -> std::cin.ignore() Behavior: Observe how ignore() acts when encountering `^Z`/`EOF.

Case 2: Non-Numeric Start with `^Z`
  -> abc`^Z`
  -> abc`^Z`123
  -> abc`^Z`abc

  Observations to Record:
    -> Glyph Occurrence: Note the echoed string abc`^Z` in the console.
    -> Extraction: Observe std::cin.fail() triggering on 'a'.
    -> std::cin.peek(): Inspect the unextracted character at the front of the buffer (char, decimal, and hex).
    -> std::cin.ignore() Behavior: Observe whether ignore() runs before vs. after calling std::cin.clear().

Case 3: `^Z` on an Empty Line
  -> `^Z` (pressed on a blank line + Enter)

  Observations to Record:
    -> Glyph Occurrence: Note the standalone `^Z` prompt output.
    -> Extraction: Observe the immediate fail/EOF state without user characters.
    -> std::cin.peek(): Inspect the return value (EOF sentinel / -1 / 0xFFFFFFFF).
    -> std::cin.ignore() Behavior: Check if ignore() halts immediately due to std::cin.eof().

Case 4: Leading `^Z` with Trailing Characters
  -> `^Z`abc`
  -> `^Z`123

  Observations to Record:
    -> Glyph Occurrence: Note `^Z`abc or `^Z`123 appearing in the console.
    -> Extraction: Verify that trailing characters are bypassed/ignored because `^Z` comes first.
    -> std::cin.peek(): Check if peek() returns the EOF state immediately.
    -> std::cin.ignore() Behavior: Observe how ignore() interacts with an already-terminated stream.



# Findings / Important Observations -------------------------------------------------------------------------------------------------------------------------


```Q: What happens if the input is 25 and hasUnExtractedInputs() is called?```

A: If the current extraction position points to a space:

25····
  ↑
current position
!std::cin.eof()          → true
std::cin.peek() != '\n'  → true

Therefore:

true && true → true

So hasUnExtractedInputs() returns true.

```Q: Why does it return true when there is only whitespace left?```

A: Because peek() checks the actual next character. A space ' ' is also a character.

' ' != '\n' → true

So the function detects remaining characters, not necessarily a meaningful value.

```Q: Is the space itself a semantic error?```

A: No. A space is valid input. But it can cause a logical/semantic problem if we interpret:

hasUnExtractedInputs() == true

as:

"A meaningful value is still available."

The function actually means:

"Some character other than '\n' remains in the stream."

🧠 ROT

peek() checks characters, not values. So trailing spaces can make hasUnExtractedInputs() return true even when no meaningful value remains.



```Q: What is a real-time problem that can occur with peek() != '\n'?```

A: Suppose a user enters:

    25····⏎


The user thinks:

"I entered 25 and pressed Enter, so I'm done."

But the stream contains:

    25····\n
      ↑
 spaces are still characters

After 25 is extracted, peek() sees a space:

    ' ' != '\n' → true



So the program may think:

"There is still input remaining."

and ask the user for another value.



The user sees:

    Enter next value:



and gets confused:

"Why is it asking me again? I already pressed Enter!" 😵

🧠 Real-world takeaway

A user sees whitespace as visually empty, but std::cin sees spaces as actual characters. Therefore, a character-level check can mistake trailing spaces for remaining input.


    * so if a user enter 25+spaces and clicks enter, he can still asked again to enter input but at that time he might confused as it seems blank in console after 25



```Q: What real-time problem can happen if a user enters 25 followed by spaces and presses Enter?```

A: The program may ask the user to enter another value because the spaces after 25 are still treated as input characters, 
   making the user confused as the console looks blank after 25 even though the program is waiting for another input.



## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------

```Error case 3: Extraction fails```

Extraction fails when no input can be extracted to the specified variable.

Now consider the following execution of our updated calculator program:

    Enter a decimal number: a
You shouldn’t be surprised that the program doesn’t perform as expected, but how it fails is interesting:

    Enter a decimal number: a
    Enter one of the following: +, -, *, or /: Oops, that input is invalid.  Please try again.
    Enter one of the following: +, -, *, or /: Oops, that input is invalid.  Please try again.
    Enter one of the following: +, -, *, or /: Oops, that input is invalid.  Please try again.
    and that last line keeps printing until the program is closed.........
    .....
    ...
    .....
    .....(infinite looop)...

This looks pretty similar to the extraneous input case, but it’s a little different. Let’s take a closer look.

When the user enters ‘a’, that character is placed in the buffer. Then operator>> tries to extract ‘a’ to variable x, which is of type double. Since ‘a’ can’t be converted to a double, operator>> can’t do the extraction. Two things happen at this point: ‘a’ is left in the buffer, and std::cin goes into “failure mode”.

Once in “failure mode”, future requests for input extraction will silently fail. Thus in our calculator program, the output prompts still print, but any requests for further extraction are ignored. This means that instead waiting for us to enter an operation, the input prompt is skipped, and we get stuck in an infinite loop because there is no way to reach one of the valid cases.


In order to get std::cin working properly again, we typically need to do three things:

1. Detect that a prior extraction has failed.
2. Put std::cin back in normal operation mode.
3. Remove the input that caused the failure (so the next extraction request doesn’t fail in an identical manner).


* Once an extraction has failed, future requests for input extraction (including calls to ignore()) will silently fail until the clear() function is called. 
  Thus, after detecting a failed extraction, calling clear() is usually the first thing you should do.



* input stream have bits  (like a on/off switches), here we have 2 relevant bits
     1. eofbit
     2. failbit


  
```Q: as for double x, If I type 0, no infinite loop. If I type abc, infinite loop. But x ends up as 0.0 in both cases — so what's the difference?```

A: 
The value 0.0 in double x is not the cause. The difference is in the stream state and the buffer:

   Type 0 → x becomes 0.0 by successful extraction → no failbit, buffer drained → next read works → no loop.
   Type abc → x becomes 0.0 by failed extraction (C++11 zero-assignment on failure) → failbit set, abc\n stuck in buffer → every next cin >> x is a no-op → loops forever.

   So the 0.0 sitting in double x is innocent — the loop is caused by failbit + clogged buffer, not the value.




# Key Takeaways ---------------------------------------------------------------------------------------------------------------------------------------------

* cin failure happens at:
                          - wrong data type extraction
                          - user defined EOF (CTRL + Z) . it triggers both failbit and eofbit as 'true' at the same time



console/terminal Inputs check for EOF (Ctrl+Z):

{ //all identical

    enter (Ctrl+Z) ^Zabc    -> ^Z treated as EOF (turns cin failbit and eofbit as 'true'), remaining discarded [ Post-^Z text-a console throw pannidum, because EOF already signal aachu antha read-ku ]
    enter (Ctrl+Z) ^Z123    -> ^Z treated as EOF (turns cin failbit and eofbit as 'true'), remaining discarded [ Post-^Z text-a console throw pannidum, because EOF already signal aachu antha read-ku ]
    enter (Ctrl+Z) ^Z       -> ^Z treated as EOF (turns cin failbit and eofbit as 'true'),

}
    
    enter (Ctrl+Z) 123^Z  -> 123 extracted, ^Z treated as normal char
    enter (Ctrl+Z) abc^Z  -> abc triggers cin.fail bit as 'true', ^Z treated as normal char

  
  * Ctrl+Z-at-start = failbit + eofbit both.



# Golden rule:

    Windows console la, ^Z EOF-ah act aagum ONLY when it's the FIRST character on the line. Edhavadhu type panni apparam ^Z potta → EOF illa, just junk-ah ignore aagum.



# Rule of Thumb (ROT) ---------------------------------------------------------------------------------------------------------------------------------------------



# Additional ------------------------------------------------------------------------------------------------------------------------------------------------


```EOF:```

* Windows console la, ^Z (Ctrl+Z) EOF-ah act aagum ONLY when it's the FIRST character on the line. Edhavadhu type panni apparam ^Z potta, adhu EOF illa — just oru normal char / ignored aagum.





🎯 Interview Q&A


```Q: Does std::cin >> discard all whitespace, and can std::cin.peek() see a space ?```

A: No. std::cin >> skips leading whitespace before its next formatted extraction, 
   but it does not automatically discard spaces occurring after the value it just extracted. 
   std::cin.peek() sees the exact next character without consuming it, so it can return ' '.



```Q: If std::cin >> skips whitespace, how can std::cin.peek() still see a space after extracting a value ?```

A: operator>> skips whitespace only when it begins its own formatted extraction. 
   It does not automatically remove whitespace that appears after the value it has just extracted. 
   Therefore, a space can remain as the next character, and peek() observes that exact character without consuming it.


   Code sample for peek() :

        // Input: 25 abc\n

        int x{};
        std::cin >> x;       // x = 25, space can remain

        char ch = std::cin.peek();  // ch = ' '

        std::cout << (ch != '\n'); // true



------------------------------------------------------------------------------
        

hasUnExtractedInputs() — Boolean Logic

    bool hasUnExtractedInputs()
    {
        return !std::cin.eof() && std::cin.peek() != '\n';
    }

   * It is a single-time check, and it checks the single character currently pointed to in that line by the input stream’s current extraction position.
     (its a single time check and it checks that single line character)


-> hasUnExtractedInputs()  is a one-time check of the stream's current extraction position at the exact moment you call it.
-> hasUnExtractedInputs() checks the current target position once; peek() looks at that position without moving it.
-> If you call hasUnExtractedInputs() again, it checks the new current position.



* newline comes first, EOF comes after it.
* '\n' (VALUE FROM KEYBOARD) is an actual character; EOF means there are no more characters left.
* Enter gives '\n'; when there is nothing left to read, the stream reaches EOF.


``` why peek()? why not cin.get(T) ?```
get() is an extraction operation, while peek() is an inspection operation. 
Since this function only needs to check the current character, peek() matches the function's purpose.
But get() technically valid if we going to use ignore() to remove the buffer and asking user to re enter the input later.




📊 Complete Logic Table

!eof()	        peek() != '\n'	        Logic	                        Meaning
true	        true	                true && true →   true	        Input innum irukku + next char newline illa → innum extract panna value irukku ✅
true	        false	                true && false →  false	        Input innum irukku, aana next char '\n' → current line mudinjiduchu
false	        true	                false && true →  false	        EOF reached → input source-la inime edhuvum illa ❌ EOF (true) + whatever (no need to consider)
false	        false	                false && false → false	        EOF reached → input source-la inime edhuvum illa ❌ EOF (true) + No more values in buffer and it reached newline




```true && true```


* !eof() → true = input innum mudiyala.

* peek() != '\n' → true = next character \n illa.

* true && true → true.

* Function result true → current line-la innum extract panna value irukku. ✅


```true && false```

* !eof() → true = input innum mudiyala.

* peek() != '\n' → false = next character \n ah irukku.

* true && false → false.

* Function result false → current line-la innum extract panna value illa. ❌



```false && true```

* !eof() → false = input mudinjiduchu.

* peek() != '\n' → true = next character \n illa.

* false && true → false.

* Function result false → input source mudinjiduchu, so innum extract panna input illa. ❌

Note: Genuine EOF-la peek()-ku normal next character irukkaadhu, so false && true is mainly a logical combination, not a normal buffer situation.


  If std::cin.eof() is genuinely already true, peek() isn't guaranteed to give you a meaningful next character. 
   So false && true is mainly a logical combination, not a normal real-world stream state you should try to construct.



```false && false```

* !eof() → false = input mudinjiduchu.

* peek() != '\n' → false = next character \n ah irukku.

* false && false → false.

* Function result false → input source mudinjiduchu, so innum extract panna input illa. ❌

Note: Genuine EOF and a normal \n simultaneously being the next character is not a normal stream situation.



### Conclusion ------------------------------------------------------------------------------------------------------------------------------------------------------------------

As you write your programs, consider how users will misuse your program, especially around text input. For each point of text input, consider:

Could extraction fail?
Could the user enter more input than expected?
Could the user enter meaningless input?
Could the user overflow an input?
 

------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
