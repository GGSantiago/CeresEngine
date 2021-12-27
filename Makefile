Executable: main.c
	gcc main.c ceresMath.h -o executable -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lm

Testing: testExe
	./quaternionTest

testExe:
	gcc ceresMath.h ceresMath.c quaternionTesting.c -lm -o testExe
 


