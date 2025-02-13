CC = g++
PROJECT = main
SRC = main.cpp Camera.cpp
CXXFLAGS = -I/usr/local/include/opencv4
LDFLAGS = -L/usr/local/lib
LIBS = `pkg-config --cflags --libs opencv4` -lpthread
LDFLAGS += -L/usr/local/cuda/lib64
LIBS += -lcudart -lcublas -lcurand
LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_cudaimgproc -lopencv_cudaarithm -lopencv_cudafilters -lopencv_videoio -lopencv_cudawarping
$(PROJECT) : $(SRC)
	$(CC) $(CXXFLAGS) $(SRC) -o $(PROJECT) $(LDFLAGS) $(LIBS)