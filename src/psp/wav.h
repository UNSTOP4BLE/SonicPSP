#ifndef __WAV_H__
#define __WAV_H__

typedef struct
{
        unsigned long channels; /**<  Number of channels */
        unsigned long sampleRate; /**<  Sample rate */
        unsigned long sampleCount; /**<  Sample count */
        unsigned long dataLength; /**<  Data length */
        unsigned long rateRatio; /**<  Rate ratio (sampleRate / 44100 * 0x10000) */
        unsigned long playPtr; /**<  Internal */
        unsigned long playPtr_frac; /**<  Internal */
        int loop; /**<  Loop flag */
        void *data; /**< A pointer to the actual WAV data */
        int id; /**<  The ID of the WAV */
        unsigned long bitPerSample; /**<  The bit rate of the WAV */
} Wav;

bool WavInit();
Wav *WavLoad(const char *filename);
void WavFree(Wav *theWav);
bool WavPlay(Wav *theWav);
void WavStop(Wav *theWav);
void WavStopAll();
void WavSetLoop(Wav *theWav, int loop);

#endif 
