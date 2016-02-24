# gcc cam2bs.c -lcurl-gnutls -L/usr/lib/i386-linux-gnu/libcurl-gnutls.a -o test
#CFLAGS = -Wall -g -O2 #-static
#CFLAGS += -static -Wl,-lgcc_s,-Bstatic
#ifdef HW_TK1
#CC = arm-linux-gnueabihf-gcc-4.5
#ARMGCC_LIB=-L/usr/arm-linux-gnueabihf/lib
#CFLAGS = -O3 -pipe -march=armv7-a -mfpu=vfpv3 -w -mfloat-abi=hard -DHW_PLATFORM_IS_JETSON_TK1
#endif
CXXFLAGS =-std=gnu++0x  -Wl,--no-as-needed

PROGS     = detect

LDFLAGS = -lpthread
# -lglib-2.0
#LDFLAGS += -L../../lib/curl/lib  #-Wl,-Bsymbolic-functions -Wl,-z,relro
#LDFLAGS += -L../../lib/c-ares/lib
#LDFLAGS += -L/usr/lib/i386-linux-gnu  # -lcurl 
#LDFLAGS += $(ARMGCC_LIB)
SRCS      = $(wildcard *.cpp)
OBJS      = $(SRCS:.cpp=.o)
all:	$(PROGS)

$(PROGS): $(OBJS)
	$(CXX) $(CXXFLAGS)  $^  $(INCLUDE) $(LDFLAGS) $(LDLIBS) $(LIBS)  -o $@

#OBJS      = $(SRCS:.cpp=.o)
#all:	$(PROGS)

#$(PROGS): $(OBJS)
#	$(CXX) $(CXXFLAGS)  $^  $(INCLUDE) $(LDFLAGS) $(LDLIBS) $(LIBS)  -o $@

clean:
	rm -f $(PROGS) *.o ../../common/*.o core
	rm -f *.tar *~ *ftp*.txt

