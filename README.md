# Implementation of the _printf function.

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=100&size=18&duration=2000&pause=1000&color=E2A40FE7&background=17EEF720&width=435&lines=This+project+is+made+by+%3A;Brice+Kanga;Wilfried+Guele)](https://git.io/typing-svg)

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


## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Documentation

[secrets of "printf"](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2022/11/d38f88e96a617135804dca9f9c49632751e06aa7.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20241128%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20241128T021031Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=6baae0dd3453da793e800883b230c156564828deee4074ad2b8da272a54eb7d6)

[man 3 printf](http://manpagesfr.free.fr/man/man3/printf.3.html)
## FAQ

### Frequently Asked Questions (FAQ) for _printf Function Implementation

#### 1. **What is the purpose of the _printf function?**

**Answer**:  
The _printf function is a custom implementation of the standard `printf` function in C. It is used to format and print data (strings, integers, characters, etc.) to the standard output (stdout). It takes a format string and a variable number of arguments, processes each argument according to the format specifiers, and outputs the corresponding formatted result.

---

#### 2. **What format specifiers are supported by _printf?**

**Answer**:  
Initially, _printf supports the following basic format specifiers:
- **c**: Prints a character.
- **s**: Prints a string.
- **d** or **i**: Prints an integer.
- **%**: Prints a percent sign.

Additional specifiers can be added as the implementation evolves, such as handling unsigned integers (`u`), hexadecimal (`x`, `X`), and others.

---

#### 3. **How does _printf handle format specifiers?**

**Answer**:  
When a format specifier (preceded by `%`) is encountered in the format string, _printf calls the `handle_specifiers` function to process it. Based on the specifier (e.g., `c`, `s`, `%`, `d`, `i`), the appropriate printing function (e.g., `print_char`, `print_string`, `print_percent`, or `print_number`) is called. If the specifier is not recognized, `%` followed by the specifier is printed.

---

#### 4. **What happens if a NULL string is passed to _printf?**

**Answer**:  
If a NULL string is passed with the `%s` specifier, the function will print `(null)` instead of causing a crash. This behavior is specifically handled in the `print_string` function to ensure safety and proper output.

---

#### 5. **What does the _printf function return?**

**Answer**:  
The _printf function returns the total number of characters printed, excluding the null terminator used to mark the end of the string. This return value can be useful for debugging or for confirming the success of the function.

---

#### 6. **How does _printf handle integer values?**

**Answer**:  
When an integer value is passed with the `%d` or `%i` specifier, the `print_number` function is called. The function checks if the number is negative, prints a minus sign if needed, and then recursively prints the digits of the number in the correct order.

---

#### 7. **What happens if an invalid specifier is passed?**

**Answer**:  
If an invalid specifier (e.g., `%r` for an unsupported specifier) is passed, _printf prints `%` followed by the invalid specifier. This ensures that the function behaves predictably even when incorrect input is provided.

---

#### 8. **What are the limitations of _printf in this project?**

**Answer**:  
Some of the limitations in this implementation include:
- No support for field widths, precision, or flags (such as left/right alignment or zero-padding).
- The function does not handle length modifiers like `l` or `h`.
- Only basic specifiers like `%c`, `%s`, `%d`, `%i`, and `%` are supported initially.

---

#### 9. **How does _printf handle the `write` system call?**

**Answer**:  
The `write` system call is used in the printing functions (e.g., `print_char`, `print_string`, etc.) to send the formatted output to the standard output. The `write` call is a low-level function that directly writes to the file descriptor (1 for stdout). This is used instead of `printf`'s higher-level implementation.

---

#### 10. **Why do I need to use `va_start` and `va_end`?**

**Answer**:  
The `va_start` and `va_end` macros are necessary to manage the variable argument list. `va_start` initializes the arguments list, allowing you to access the variable arguments passed to _printf. `va_end` is called at the end of argument processing to clean up any memory used by the variable argument list. These macros are crucial for handling an unknown number of arguments in a function like _printf.

---

#### 11. **Can _printf be used for performance-critical applications?**

**Answer**:  
No, _printf is not optimized for high-performance scenarios. It is a custom implementation and may be slower than alternatives like `write` or `sprintf`. If performance is critical, it is recommended to use more efficient methods like direct use of `write` or optimized functions from the standard library.

---

#### 12. **How does _printf handle the printing of negative numbers?**

**Answer**:  
In the case of negative numbers, the `print_number` function handles them by first checking if the number is negative. If it is, a minus sign is printed using `print_char`, and then the absolute value of the number is printed recursively. This ensures that the negative sign is printed only once at the beginning.

---

#### 13. **Why is my output incorrect when using %s with an empty string?**

**Answer**:  
If an empty string (i.e., `""`) is passed to _printf with the `%s` specifier, the output should be an empty output (no characters printed). If it is not behaving as expected, check the implementation to ensure that the length of the string is properly handled and that it is not being mistakenly treated as `NULL`.

---

#### 14. **What is the expected output when I call _printf with just a `%`?**

**Answer**:  
When you call _printf with just a `%` (e.g., `_printf("%%");`), the function will correctly print a single `%` character. This is handled by the `print_percent` function, which simply writes the `%` to stdout.

---

#### 15. **What should I do if my _printf implementation is failing to compile?**

**Answer**:  
Ensure that:
1. You have correctly included the necessary header files (e.g., `main.h`, `stdarg.h`).
2. You are using the correct compiler flags (`-Wall -Werror -Wextra -pedantic -std=gnu89`).
3. Your code adheres to the Betty style (if required by the project).
4. Your functions are correctly defined and that all function prototypes match what is expected.

If the issue persists, try to isolate the problem by compiling the code in smaller chunks or running it through a debugger.

## ðŸ›  Skills

![wlfrd18's Stats](https://github-readme-stats.vercel.app/api?username=wlfrd18&theme=vue-dark&show_icons=true&hide_border=true&count_private=true)
![wlfrd18's Streak](https://github-readme-streak-stats.herokuapp.com/?user=wlfrd18&theme=vue-dark&hide_border=true)
![wlfrd18's Top Languages](https://github-readme-stats.vercel.app/api/top-langs/?username=wlfrd18&theme=vue-dark&show_icons=true&hide_border=true&layout=compact)
***  

***  

![kanga-prog's Stats](https://github-readme-stats.vercel.app/api?username=kanga-prog&theme=vue-dark&show_icons=true&hide_border=true&count_private=true)
![kanga-prog's Streak](https://github-readme-streak-stats.herokuapp.com/?user=kanga-prog&theme=vue-dark&hide_border=true)
![kanga-prog's Top Languages](https://github-readme-stats.vercel.app/api/top-langs/?username=kanga-prog&theme=vue-dark&show_icons=true&hide_border=true&layout=compact)
## ðŸ”— Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/wilfried-guele-5a456a190/?otpToken=MTUwMDFkZTgxNzJhY2ZjMmJjMjQwNGVkNDUxY2UwYjc4OGNlZDc0MjkwYWU4NzYxNzZjZTAwNjY0YzVlNThmYmYyZDBkZjgyNmJmYWUyZmMwMzhjYTkwMmMyOTM3MWE2Yzc3NWQ0OTI3YTYxZmQ3MzhjOTA4YiwxLDE%3D&midSig=0mo82sJRdDGbw1&eid=cgtpzg-m4094dyz-ns&midToken=AQGShgxxqbBN4g&original_referer=&trkEmail=eml-email_network_conversations_01-header-0-profile_glimmer-null-cgtpzg%7Em4094dyz%7Ens-null-null&trk=eml-email_network_conversations_01-header-0-profile_glimmer&originalSubdomain=cm)
****  
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/kanga-kouakou-brice-8a787a16a/)

