#ifndef RN2483_H
#define RN2483_H

#include <Arduino.h>
#include "lora\rn2483Model.h"


#define SW_VER_LEN 50

class RN2483 {
private:
    int answerLen;
    char *bufferAnswer;
    int bufferAnswerLen;
    char swVer[50];

public:
    RN2483(){swVer[0]=0;};
    void init();
    void rawData(String stream);
    inline void prepareAnswer(char *buffer, int bufferLen){
        bufferAnswer = buffer;
        bufferAnswerLen = bufferLen;
    };
    boolean hasAnswer(void);
    inline const char* getLastAnswer(void) {return bufferAnswer;};

    //SYS specific command
    const char* getVersion(void);
    void factoryReset(void);
    inline void reset(void) {rawData(SYS_RESET);};
};

// external variable used by the sketches
extern RN2483  lora;
#endif
