
output: app.o log.o common.o
	g++ app.o \
	log.o \
	common.o \
	-o output

main.o: app.cpp
	g++ -c app.cpp

common.o: common.cpp
	g++ -c common.cpp

log.o: log.cpp
	g++ -c log.cpp

clean:
	rm *.o output
