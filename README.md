# This is the README file about the 1st challenge 

# Implemenatation
* The code as 2 version, the 1st one is implemented using free functions, while the second one using the
Muparser library *

# Makefile
* the make file has some instruction that are commented, becuse the defual version is used for compile and  run the version using free function. for using the second version you must do the followig instruction:
1. in CPPFLAGS, there are 2 -I .. you have to cancel the # for the second path, and chage the second path with the path in you machine (the path to the Muparser library)
2. select as EXEC mainMuparser and comment the lain EXEC main
3. erese the simbol of # near LDFLAGS and LIBS, and putting you path into LDFLAGS
4. change LD_LIBRARY_PATH with your own path of the required library
5. select the second SRCS, and comment the 1st one
*




