objects = MatrixUtils.o VectorUtils.o ArrayUtils.o
output = ./builds/



utils: $(objects)
	cd builds
	g++ -o $(output)libutils.so -shared $(objects)
	ar rvs libutils.a $(objects)
	cd -

MatrixUtils.o : MatrixUtils.cpp
	g++ -o $(output)MatrixUtils.o -c MatrixUtils.cpp

VectorUtils.o : VectorUtils.cpp
	g++ -o $(output)VectorUtils.o -c VectorUtils.cpp

ArrayUtils.o : ArrayUtils.cpp
	g++ -o $(output)ArrayUtils.o -c ArrayUtils.cpp

remove:
	for i in $(objects); do \
		@echo "hello there"; \
		rm -f $(output)i; \
	done	