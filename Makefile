CFLAGS = -Wall -O2

VT32PAL_OUTPUT_NORMAL = vt32pal_normal.exe
VT32PAL_OUTPUT_BLUECASTREMOVAL = vt32pal_bluecastremoval.exe

.phony: all clean paltab vt32pal vt369pal

all: paltab vt32pal vt369pal

paltab:
	$(CC) $(CFLAGS) -o paltab.exe paltab.c

vt32pal:
	$(CC) $(CFLAGS) -o $(VT32PAL_OUTPUT_NORMAL) vt32pal.c
	$(CC) $(CFLAGS) -D_BLUECASTREMOVAL -o $(VT32PAL_OUTPUT_BLUECASTREMOVAL) vt32pal.c

vt369pal:
	$(CC) $(CFLAGS) -o vt369pal.exe vt369pal.c

clean:
	rm -f paltab.exe $(VT32PAL_OUTPUT_NORMAL) $(VT32PAL_OUTPUT_BLUECASTREMOVAL) vt369pal.exe
