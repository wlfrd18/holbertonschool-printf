# Implementation of the _printf function

## Table of Contents
#### 1- Introduction  
#### 2- Implementation of the _printf function  
#### 3- The handle_specifiers function  
#### 4- Specific printing functions  
#### 5- Summary of the implementation process  
#### 6- Common mistakes to avoid when using _printf  
#### 7- Recommendations  

***
### 1. Introduction
#### **Description of the _printf function**
The _printf() function is a custom version of the standard printf function in C. It allows for formatting and printing a series of characters and values to the standard output stream (stdout). Format specifiers, preceded by the % sign, are used to determine the output format for each argument in the list following the format string.
#### **Project Requirements**
-  All files must be compiled on Ubuntu 20.04 LTS using the gcc compiler, with the following options: **-Wall -Werror -Wextra -pedantic -std=gnu89.**
- The code must follow the Betty style and be checked using the betty-style.pl and betty-doc.pl scripts.

### 2- ImplÃ©mentation of the _printf function
#### **Prototype of the fonction**
    int _printf(const char * format, ...)

The function ***_printf*** takes a format string and a variable number of arguments, indicated by "**...**". It returns an integer representing the number of characters printed, excluding the null-terminating character.
### **Detailed Functionality of the _printf Function**

#### Variable Declarations:
```c
va_list arguments;
```
*Used to access variable arguments.*

```c
int count = 0;
```
*A counter to keep track of the number of characters printed.*

```c
const char *pointer = format;
```
*A pointer to the format string, used to iterate through each character.*

***
#### Initializing the Arguments List:
```c
va_start(arguments, format);
```
*Initializes the arguments list from the format, allowing access to the additional arguments.*

***
#### Format Processing Loop:
```c
while (*pointer != '\0') 
{
    if (*pointer == '%') 
    {
        pointer++;
        count = count + handle_specifiers(*pointer, arguments);
    } 
    else
    {
        count = count + print_character(*pointer);
    }
    pointer++;
}
```
*The loop goes through each character in the format string. If a `%` is encountered, the handle_specifiers function is called to process the format specifier. Otherwise, the character is simply printed.*

***
#### End of Arguments Handling:
```c
va_end(arguments);
```
*Ends the handling of the arguments list.*

***
#### Returning the Number of Printed Characters:
```c
return (count);
```

### 3- **handle_specifiers Function**

#### **Description of the handle_specifiers Function**
This function is responsible for processing different format specifiers in the format string. It takes a specifier character and the arguments list as inputs, and calls the appropriate function for each specifier.
Its **prototype** is:  
```c
int handle_specifiers(char specifier, va_list arguments);
```
Parameters:  
- **specifier**: The format specifier character (e.g., c, s, %, d, i).
- **arguments**: The arguments list passed to _printf.

#### Handling Specifiers:
- If **specifier** is **'c'**: Call the **print_character** function.
- If **specifier** is **'s'**: Call the **print_string** function.
- If **specifier** is **'%'**: Call the **print_percent** function.
- If **specifier** is **'d'** or **'i'**: Call the **print_number** function.
- If **specifier** is unknown: Print **%** followed by the specifier.

### 4. **Specific Printing Functions**

#### **print_character**
```c
int print_char(char c) 
{
    return (write(1, &c, 1));
}
```
**Input Parameter**: A character **c**.  
**Functionality**: The function uses `write` to print the character to the standard output stream (stdout).

#### **print_string**
```c
int print_string(char *string)
{
    int index = 0;

    if (string == NULL) 
    {
        string = "(null)";
    }

    while (string[index] != '\0')
    {
        index++;
    }
    return (write(1, string, index));
}
```
**Input Parameter**: The string **string** to print.

**Functionality**:
- If **string** is **NULL**, the function prints **(null)**.
- The function iterates through the string to determine its length and uses **write** to print the string.

#### **print_percent**  
```c
int print_percent(void) 
{
    return (write(1, "%", 1));
}
```
**Input Parameter**: None.  
**Functionality**: The function uses `write` to print the `%` character to the output stream.  

#### **print_number**  

    int print_number(int number)
    {
    
	    char digit;
	    int count = 0;
	    unsigned int abs_number;

	    if (number < 0)
	    {
		    count += print_character('-');
		    abs_number = -number;
	    }
	    else
	    {
		    abs_number = number;
	    }
	    if (abs_number / 10)
	    {
		    count = count + print_number(abs_number / 10);
	    }
	    digit = (abs_number % 10) + '0';

	    count = count + print_character(digit);

	    return (count);
    }


 

Functionning :
- If the number is negative, it prints a minus sign ('-') and converts the number to positive.
- It checks if the number has more than one digit. If so, it recursively calls itself with the number divided by 10 until only a single digit remains.
-  After reaching the last digit, it prints it by converting the digit to a character.
- Each printed character (including digits and the minus sign) increments the count, which is returned at the end.  
#### **5. RÃ©sumÃ© du processus dâ€™implÃ©mentation**
The **_printf** function traverses the format string.
When a format specifier is encountered (indicated by **%**), it calls the appropriate function through **handle_specifiers**.
Depending on the specifier (e.g., **c**, **s**, **%**, **d**, **i**), it calls a specific printing function like **print_character**, **print_string**, **print_percent** or **print_number**.
The function returns the total number of characters printed, excluding the null-terminating character.

#### **6. Errors to avoid when using _printf:**

* Forgetting to match specifiers with the correct argument types  
*Using an incorrect format specifier (e.g., %d for a string or %s for an integer) can lead to undefined behavior.*
* Missing required arguments
*Failing to provide all necessary arguments for the format specifiers can result in unpredictable behavior.*  
* Not handling NULL pointers correctly with %s
*Passing a NULL pointer with %s can cause a crash. It is important to check if the string is NULL before printing it.*
* Not using the correct precision for floating-point numbers
*Omitting precision when displaying floating-point numbers can lead to overly detailed or incomplete output.*
* Incorrect use of minimum width and precision
*Specifiers like %*d and %.*f can be confusing if their width and precision are not correctly specified.*
* Ignoring return values from printf
*The return value from printf (the number of characters printed) can be useful for debugging and should be considered.*
* Avoiding the use of _printf for critical performance scenarios
*_printf may be slower than other alternatives like write, and should not be used in performance-critical situations.*
* Failing to ensure proper string termination
*A string not properly terminated with a null character ('\0') can cause serious errors when used with %s.*
* Incorrect use of escape characters in format strings
*Escape characters like \n or \t should be used correctly to avoid unexpected output.* 

#### **7. Recommandations**
For correct use of the **_printf function**, it is essential to:

* Correctly match format specifiers with argument types.
* Ensure that all required arguments are provided.
* Properly handle pointers.


## Badges

Add badges from somewhere like: [shields.io](https://shields.io/)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![AGPL License](https://img.shields.io/badge/license-AGPL-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)


## Feedback


## FAQ

#### Question 1

Answer 1

#### Question 2

Answer 2


## Documentation

[secrets of "printf"](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2022/11/d38f88e96a617135804dca9f9c49632751e06aa7.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20241128%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20241128T021031Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=6baae0dd3453da793e800883b230c156564828deee4074ad2b8da272a54eb7d6)

[man 3 printf](http://manpagesfr.free.fr/man/man3/printf.3.html)
## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


