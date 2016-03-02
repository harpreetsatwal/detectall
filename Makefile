CXXFLAGS =-std=gnu++0x  -Wl,--no-as-needed

EXE     = detect

LDFLAGS = -lpthread

TEMP_DIR = obj

SRCS      = $(wildcard *.cpp)
OBJS      = $(patsubst %.cpp,$(TEMP_DIR)/%.o,$(SRCS))


all:$(EXE)
  
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS)  $^  $(INCLUDE) $(LDFLAGS) $(LDLIBS) $(LIBS)  -o $@

$(OBJS): | $(TEMP_DIR)

$(TEMP_DIR):
	@mkdir -p $@
  
$(TEMP_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(PROGS) $(OBJS) core
	rm -rf $(TEMP_DIR)
