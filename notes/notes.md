
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
### 9.1 —     								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------



# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------




# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.1 —     								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------



# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------




# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.1 —     								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------



# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------




# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------
																			 |
### 9.1 —     								 |
																			 |
------------------------------------------------------------------------------


### Project Logic Overview ----------------------------------------------------------------------------------------------------------------------------------



# Hands-on Doubts cleared: ---------------------------------------------------------------------------------------------------------------------------------------------------


## New things I learned ------------------------------------------------------------------------------------------------------------------------------------------------------




# Best Practices



# * Additional *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



# * Findings *  ------------------------------------------------------------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
