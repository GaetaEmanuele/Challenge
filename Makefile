CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations -I../${CHALLENGE_FOLDER}/include #-I../pacs-examples/Examples/include

#EXEC     = mainMuparser
EXEC     = main
#LDFLAGS  ?= -L../pacs-examples/Examples/lib # Se necessario
#LIBS     ?= -lmuparser # Se necessario

SRCS     =  main.cpp minimum.cpp Armijo.cpp Fraction.cpp ExponentialDecay.cpp  
#SRCS     =  mainMuparser.cpp minimum.cpp Armijo.cpp Fraction.cpp ExponentialDecay.cpp
OBJS     = $(SRCS:.cpp=.o)

.PHONY: all clean distclean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

# Genera le dipendenze automaticamente
%.d: %.cpp
	@set -e; $(CXX) -MM $(CPPFLAGS) $< \
	| sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@; \
	[ -s $@ ] || rm -f $@

-include $(SRCS:.cpp=.d)

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(SRCS:.cpp=.d)

distclean: clean
	$(RM) $(EXEC)
