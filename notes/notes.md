
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




# Core Concept -----------------------------------------------------------------------------------------------------------------------------------------------



# Key Points ------------------------------------------------------------------------------------------------------------------------------------------------



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


# Real-World Examples ------------------------------------------------------------------------------------------------------------------------------




# When to Use / When Not to Use ------------------------------------------------------------------------------------------------------------------------------



# Pros ------------------------------------------------------------------------------------------------------------------------------------------------------



# Cons / Limitations -----------------------------------------------------------------------------------------------------------------------------------------



# Best Practices ---------------------------------------------------------------------------------------------------------------------------------------------



# Common Pitfalls / Gotchas ----------------------------------------------------------------------------------------------------------------------------------



# Things to Remember -----------------------------------------------------------------------------------------------------------------------------------------



# Findings / Important Observations -------------------------------------------------------------------------------------------------------------------------



## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------



# Key Takeaways ---------------------------------------------------------------------------------------------------------------------------------------------



# Rule of Thumb (ROT) ---------------------------------------------------------------------------------------------------------------------------------------------



# Additional ------------------------------------------------------------------------------------------------------------------------------------------------



                 UNDERSTAND
                     │
             ┌───────┴────────┐
             │                │
          WHAT IS IT?      HOW IT WORKS
             │                │
             └───────┬────────┘
                     ↓
              WHEN TO USE IT
                     ↓
             TRADE-OFFS
             ┌───────┴───────┐
            PROS            CONS
             └───────┬───────┘
                     ↓
              BEST PRACTICES
                     ↓
                GOTCHAS
                     ↓
             🧠 REMEMBER




------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
