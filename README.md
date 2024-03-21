# This is the README file about the 1st challenge 

# Implemenatation
* The code as 2 version, the 1st one is implemented using free functions, while the second one using the
Muparser library *

# Makefile
* the make file has some instruction that are commented, becuse the defual version is used for compile and  run the version using free function. For both implementation it's necessary to change the name of the folder (on my PC the folder is called CHALLENGE while on github i have called it Challenge)
For using the second version you must do the followig instruction:
1. in CPPFLAGS line there are 2 -I one is commented and must be uncommented when you want to try to run the muParser version (and put your path to the library) 
2. select as EXEC mainMuparser and comment the lain EXEC main
3. erese the simbol of # near LDFLAGS and LIBS, and putting you path into LDFLAGS
4. change LD_LIBRARY_PATH with your own path of the required library
5. select the second SRCS, and comment the 1st one
*




