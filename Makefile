# ========== Run "make help" to see the available commands ==========
CODE	= $$PWD/src
SERVER	= $(CODE)/server
CLIENT	= $(CODE)/client
COMMON	= $(CODE)/common
HEADER	= $(CLIENT)/include/*.hpp $(SERVER)/include/*.hpp include/*.hpp
SOURCE	= $(CLIENT)/*.cpp $(SERVER)/*.cpp $(COMMON)/*.cpp
OBJS	= $(CLIENT)/*.o $(SERVER)/*.o $(COMMON)/*.o
TARGET	= travelMonitor
TARGET2	= Monitor
SCRIPTS	= create_infiles.sh

# Run Parameters
BUFFSZ	= 64
NUMBER	= 9
BLOOMSZ	= 1000
INDIR	= $$PWD/input_dir/
INFILE	= citizenRecordsFile
BINDIR	= $$PWD/bin/
LOGDIR	= $$PWD/logs/

all:
	$(MAKE) -C $(SERVER)
	$(MAKE) -C $(CLIENT)

$(TARGET):
	$(MAKE) -C $(SERVER)

$(TARGET2):
	$(MAKE) -C $(CLIENT)

clean:
	$(MAKE) clean -C $(SERVER)
	$(MAKE) clean -C $(CLIENT)

cleanFull:
	$(MAKE) clean -C $(SERVER)
	$(MAKE) clean -C $(CLIENT)
	rm -rf $(INDIR) $(BINDIR) $(LOGDIR)

count:
	wc -l -w $(SOURCE) $(HEADER) $(SCRIPTS)

run:
	./$(TARGET) -m $(NUMBER) -b $(BUFFSZ) -s $(BLOOMSZ) -i $(INDIR)

scriptRun:
	./$(SCRIPTS) $(INFILE) $(INDIR) $(NUMBER)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --trace-children=yes --track-origins=yes ./$(TARGET) -m $(NUMBER) -b $(BUFFSZ) -s $(BLOOMSZ) -i $(INDIR)

help:
	@echo Options:
	@printf "make (all) %14s -- build $(TARGET) and $(TARGET2)\n"
	@printf "make $(TARGET) %6s -- build $(TARGET)\n"
	@printf "make $(TARGET2) %12s -- build $(TARGET2)\n"
	@printf "make clean %14s -- delete application\n"
	@printf "make cleanFull %10s -- delete application and its data\n"
	@printf "make count %14s -- project line and words accounting\n"
	@printf "make run %16s -- run $(TARGET) test\n"
	@printf "make scriptRun %10s -- run $(SCRIPTS) test\n"
	@printf "make valgrind %11s -- run $(TARGET) test with valgrind enabled\n"
	@printf "make help %15s -- view this help message\n"