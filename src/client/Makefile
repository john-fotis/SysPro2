CPP	= g++
FLAGS	= -g -c -Wall -std=c++0x
OBJS	= main.o Person.o Record.o Virus.o Country.o VirusCountryEntry.o $(EXTERN)/PipeLibrary.o $(EXTERN)/AppStandards.o $(EXTERN)/Messaging.o $(EXTERN)/LogHistory.o
LDLIBS	=
TARGET	= ../../Monitor
EXTERN	= ../common

$(TARGET): $(OBJS)
	$(CPP) -g $(OBJS) -o $@ $(LDLIBS)
	
%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(EXTERN)/*.o $(OBJS) $(TARGET)