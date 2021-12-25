typedef unsigned long long size_t;

typedef struct {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width; 
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} Framebuffer;

typedef struct {
	unsigned char magic[2];
	unsigned char mode[2];
	unsigned char charsize;
} PSF1_HEADER;

typedef struct {
	PSF1_HEADER* psf1_Header;
	void* glyphBuffer;
} PSF1_FONT;
typedef struct {
	unsigned int X;
	unsigned int Y;
} Point;

void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char chr, unsigned int xOff, unsigned int yOff){


	unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
	char *fontPtr = psf1_font->glyphBuffer + (chr * psf1_font->psf1_Header->charsize);
	for(unsigned long y = yOff; y < yOff+16; y++) {
		for(unsigned long x = xOff; x < xOff+8; x++) {
			if((*fontPtr & (0b10000000 >> (x-xOff))) > 0){
				*(unsigned int*)(pixPtr +x+(y*framebuffer->PixelsPerScanLine)) = colour;
			}
		}
		fontPtr++;
	}
}


void PrintT(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char* chr){
	char* chr = str;
	while(*chr !=0){
		putChar(framebuffer, psf1_font, colour, *chr, x, 0);
		x+=8;
		chr++;
	}
}

void _start(Framebuffer* framebuffer, PSF1_FONT *psf1_font){
    
	PrintT(framebuffer, psf1_font, 0xffffffff, "Loading ProtOS");
	return ;
	
}