#ifndef EzyMessage_h
#define EzyMessage_h

#include "base/EzyRef.h"

#define MAX_SMALL_MESSAGE_SIZE 65535

EZY_NAMESPACE_START_WITH(codec)

class EzyMessageHeader : public base::EzyRef {
protected:
    EZY_SYNTHESIZE_BOOL_READONLY(BigSize) //bit 1
    EZY_SYNTHESIZE_BOOL(Encrypted) //bit 2
    EZY_SYNTHESIZE_BOOL_READONLY(Compressed) //bit 3
    EZY_SYNTHESIZE_BOOL(Text) //bit 4
    EZY_SYNTHESIZE_BOOL(RawBytes) //bit 5
    EZY_SYNTHESIZE_BOOL(UdpHandshake) //bit 6
    EZY_SYNTHESIZE_BOOL(HasNext) //bit 8
public:
    EzyMessageHeader();
    EzyMessageHeader(uint32_t dataSize, bool encrypted);
    virtual ~EzyMessageHeader();
    
    virtual char getByte();
    virtual void parse(char headerByte);
    
    static EzyMessageHeader* create();
    static EzyMessageHeader* create(uint32_t dataSize, bool encrypted);
};

EZY_NAMESPACE_END_WITH

#endif /* EzyMessage_h */
