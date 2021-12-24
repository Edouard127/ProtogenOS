typedef unsigned long long long size_t;

typedef struct {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} Framebuffer;

void _start(Framebuffer* framebuffer){
    
	unsigned int y = 50;
	unsigned int BBP = 4;

    	for(unsigned int i = 0; i < newBuffer->Width/2*BBP; i+=BBP){
		*(unsigned int*)(i+(y*newBuffer->PixelsPerScanLine*BBP) + newBuffer->BaseAddress) = 0xffffffff;
	}
    return;
}