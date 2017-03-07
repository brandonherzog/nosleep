nosleep
=======

A simple command line tool for Windows that prevents the operating system from powering off the machine or (optionally) turning off the display while it is running. Useful when concurrently running long-lasting commands that do not properly handle system idling themselves or any time you want to prevent Windows from putting the system to sleep without editing operating system settings.

Supports Windows Vista and newer.

Build
-------
Easiest way to build is using the included *nosleep.sln* Visual Studio solution.
```dos
devenv nosleep.sln /Build Release
```

Usage
---------
Prevent system sleep:
```dos
nosleep
```

Prevent system sleep and keep display on:
```dos
nosleep --display
```
*Note that user initiated power events will not be affected.*

License
----------
The MIT License (MIT)

Copyright (c) 2017 Brandon Herzog

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
