# How to generate docs and diagrams

I use the tool [doxygen](https://www.doxygen.nl/index.html) to generate diagrams. When exploring undocumented C++ projects, you should always use doxygen to generate diagrams so that you can see what classes collaborate, the class hierarchy tree, and many more things. The [class hierarchy image](class_hierarchy.png) sitting in the docs folder you are in right now is generated from doxygen.

If you are on windows, follow the set up guide in [root](../) first.

Now, let's install `doxygen` and `graphviz`. Doxygen does not require graphviz as a dependency unless you want to generate diagrams, which we are doing.

```
# Windows, do this in MSYS2 MinGW 64-bit shell, not regular terminal

pacman -S mingw-w64-x86_64-doxygen mingw-w64-x86_64-graphviz

# MacOS
brew install doxygen graphviz

# Linux
You know how to install it better than I do
```

Then, in your terminal, make sure you are in `2DGame2021/docs` and run

```
doxygen ../DoxyFile
```

Now, you should see a html folder in `/docs`, run

```
# Inside of docs

# Windows
start html/index.html

# MacOS, Linux
open html/index.html

# If you want to be fancy and stupid
npm install -g http-server
cd html
http-server
```

You should see some nice documentation, explore around, see if you can find the class hierarchy diagram!

## Extension

Read the doxygen documentation online, and look through the options I enabled in our [DoxyFile](../DoxyFile)
