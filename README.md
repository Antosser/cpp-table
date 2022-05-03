# C++ Table Library
An advanced library for managing and storing string tables in C++

## Installation
1. Download the `table.cpp` file
1. Put it in the folder with your project
1. Include it using `#include "table.cpp"`

## Usage
```cpp
// Create a table like this
Table t;

// Add some rows
t.addRow({"a", "b", "c"});
t.addRow({"d", "x", "f"});

// Change a cell's value
t[1][1] = "e";
// or
t[{1, 1}] = "e";

// Print it out
t.print_ASCII();
/*
+---+---+---+
| a | b | c |
+---+---+---+
| d | e | f |
+---+---+---+
*/

// Convert to CSV
t.toCSV();
/*
a,b,c
d,e,f
*/

// Convert to JSON
t.toJSON();
/*
[
  {
    "a": "a",
    "b": "b",
    "c": "c"
  },
  {
    "a": "d",
    "b": "e",
    "c": "f"
  }
]
/*
{
"a": "b",
"d": "e",
"g": "h"
} 
*/

// Convert to HTML
t.toHTML();
/*
<table>
<tr>
<th>a</th>
<th>b</th>
<th>c</th>
</tr>
<tr>
<td>d</td>
<td>e</td>
<td>f</td>
</tr>
</table>
*/

// Clear the table
t.clear();
```