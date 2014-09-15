#
# Make for Game:five_in_row
#
# Compiler: LLVM
# 
# Author: Ran Bao
#

# default compiler
COMP=clang++ -std=c++11 -stdlib=libc++
ARGU= -framework OpenGL -framework GLUT
#




# output name
OUTPUT=opengl_timer
BuildNO=1.0cpp
#





objects=Clock.o GL_Pt.o GLColor.o main.o GlutObject.o TextBox.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU)
	@echo "*** Compile Done ***"
	zip -q -r $(OUTPUT)_$(BuildNO).zip $(OUTPUT)

Clock.o:Clock.cpp Clock.h
	$(COMP) -c Clock.cpp

GL_Pt.o:GL_Pt.cpp GL_Pt.h
	$(COMP) -c GL_Pt.cpp
       
GLColor.o:GLColor.cpp GLColor.h
	$(COMP) -c GLColor.cpp

GlutObject.o:GlutObject.cpp GlutObject.h
	$(COMP) -c GlutObject.cpp

main.o:main.cpp Clock.h GlutObject.h GL_Pt.h
	$(COMP) -c main.cpp

TextBox.o:TextBox.cpp TextBox.h
	$(COMP) -c TextBox.cpp



clean:
	rm -rf *.o *.zip $(OUTPUT) *.d
	@echo "*** Clean Done ***"


