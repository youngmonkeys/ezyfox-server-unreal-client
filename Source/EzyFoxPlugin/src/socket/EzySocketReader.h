#ifndef EzySocketReader_h
#define EzySocketReader_h

#include "EzySocketAdapter.h"
#include "codec/EzyDataDecoder.h"

EZY_NAMESPACE_START_WITH_ONLY(config)
class EzySocketConfig;
EZY_NAMESPACE_END_WITH

EZY_NAMESPACE_START_WITH(socket)

class EzySocketReader : public EzySocketAdapter, public codec::EzyDataDecoderDelegate {
protected:
#ifdef USE_MESSAGE_HEADER
    int mDataSize;
    int mBufferSize;
    int mReserveSize;
    std::string mDecryptionKey;
    std::vector<char> mByteBuffer;
    codec::EzyDecodeState mDecodeState;
    codec::EzyMessageHeader* mMessageHeader;
protected:
    virtual void preInsertData();
    virtual void onDataReceived();
    virtual void onUpdateDataHeader();
    virtual void onUpdateDataSize();
    virtual void onUpdateData();
#endif
    codec::EzyDataDecoder* mDecoder;
    virtual void acceptData(const char* data, size_t size);
    virtual void onReceivedMessage(entity::EzyValue* value);
public:
    EzySocketReader(config::EzySocketConfig* config);
    virtual ~EzySocketReader();
    virtual void run();
    virtual void popMessages(std::vector<EzySocketData*>& buffer);
    virtual void setDecryptionKey(std::string decryptionKey);
};

EZY_NAMESPACE_END_WITH

#endif /* EzySocketReader_h */
