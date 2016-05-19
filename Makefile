CXXFLAGS =-std=gnu++0x  -Wl,--no-as-needed

EXE     =detect

LDFLAGS = -lpthread

TEMP_DIR = obj

SRCS      = $(wildcard *.cpp)
OBJS      = $(patsubst %.cpp,$(TEMP_DIR)/%.o,$(SRCS))
DEP = $(OBJS:%.o=%.d)

all:$(EXE)
  
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS)  $^  $(INCLUDE) $(LDFLAGS) $(LDLIBS) $(LIBS) -o $@

$(OBJS): | $(TEMP_DIR)

$(TEMP_DIR):
	@mkdir -p $@
  
# Include all .d files
-include $(DEP)

$(TEMP_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -MD -o $@

.PHONY: clean
clean:
	rm -f $(PROGS) $(OBJS) $(EXE) core *~
	rm -rf $(TEMP_DIR)
