
#include "EzyPrimitive.h"
#include <iomanip>

EZY_NAMESPACE_START_WITH(entity)

inline std::string _value_escape_json(const std::string &s) {
	std::ostringstream o;
	for (auto c = s.cbegin(); c != s.cend(); c++) {
		switch (*c) {
		case '"': o << "\\\""; break;
		case '\\': o << "\\\\"; break;
		case '\b': o << "\\b"; break;
		case '\f': o << "\\f"; break;
		case '\n': o << "\\n"; break;
		case '\r': o << "\\r"; break;
		case '\t': o << "\\t"; break;
		default:
			if ('\x00' <= *c && *c <= '\x1f') {
				o << "\\u"
					<< std::hex << std::setw(4) << std::setfill('0') << (int)*c;
			}
			else {
				o << *c;
			}
		}
	}
	return o.str();
}

EzyPrimitive::EzyPrimitive() {
	this->setUInt(0);
}

EzyPrimitive::~EzyPrimitive() {
}

void EzyPrimitive::writeToBuffer(codec::EzyDataEncoder* encoder) {
	switch (mValueType) {
		case EzyValueType::TypeBool: {
			encoder->writeBool(data.boolValue);
			break;
		}
		case EzyValueType::TypeFloat: {
			encoder->writeFloat(data.floatValue);
			break;
		}
		case EzyValueType::TypeDouble: {
			encoder->writeDouble(data.doubleValue);
			break;
		}
		case EzyValueType::TypeInt: {
			encoder->writeInt(data.i64Value);
			break;
		}
		case EzyValueType::TypeUInt: {
			encoder->writeUint(data.ui64Value);
			break;
		}
	}
}

#ifdef EZY_DEBUG
void EzyPrimitive::printToOutStream(std::ostringstream& stream, int padding) {
	switch (mValueType)
	{
	case EzyValueType::TypeBool: {
		stream << "[Bool] " << data.boolValue;
		break;
	}
	case EzyValueType::TypeFloat: {
		stream << "[Float] " << data.floatValue;
		break;
	}
	case EzyValueType::TypeDouble: {
		stream << "[Double]" << data.doubleValue;
		break;
	}
	case EzyValueType::TypeInt: {
		stream << "[Int] " << data.i64Value;
		break;
	}
	case EzyValueType::TypeUInt: {
		stream << "[UInt] " << data.ui64Value;
		break;
	}
	default:
		stream << "[NULL]";
		break;
	}
}
#endif

void EzyPrimitive::setBool(bool b) {
	mValueType = EzyValueType::TypeBool;
	data.boolValue = b;
}

void EzyPrimitive::setFloat(float f) {
	mValueType = EzyValueType::TypeFloat;
	data.floatValue = f;
}

void EzyPrimitive::setDouble(double d) {
	mValueType = EzyValueType::TypeDouble;
	data.doubleValue = d;
}

void EzyPrimitive::setInt(int64_t i64) {
	mValueType = EzyValueType::TypeInt;
	data.i64Value = i64;
}

void EzyPrimitive::setUInt(uint64_t ui64) {
	mValueType = EzyValueType::TypeUInt;
	data.ui64Value = ui64;
}

bool EzyPrimitive::getBool() {
	return data.boolValue;
}

float EzyPrimitive::getFloat() {
    switch (mValueType) {
        case EzyValueType::TypeBool: {
            return data.boolValue ? 1 : 0;
        }
        case EzyValueType::TypeFloat: {
            return data.floatValue;
        }
        case EzyValueType::TypeDouble: {
            return data.doubleValue;
        }
        case EzyValueType::TypeInt: {
            return data.i64Value;
        }
        case EzyValueType::TypeUInt: {
            return data.ui64Value;
        }
        default: {
            return data.floatValue;
        }
    }
}

double EzyPrimitive::getDouble() {
    switch (mValueType) {
        case EzyValueType::TypeBool: {
            return data.boolValue ? 1 : 0;
        }
        case EzyValueType::TypeFloat: {
            return data.floatValue;
        }
        case EzyValueType::TypeDouble: {
            return data.doubleValue;
        }
        case EzyValueType::TypeInt: {
            return data.i64Value;
        }
        case EzyValueType::TypeUInt: {
            return data.ui64Value;
        }
        default: {
            return data.doubleValue;
        }
    }
}

int64_t EzyPrimitive::getInt() {
    switch (mValueType) {
        case EzyValueType::TypeBool: {
            return data.boolValue ? 1 : 0;
        }
        case EzyValueType::TypeFloat: {
            return data.floatValue;
        }
        case EzyValueType::TypeDouble: {
            return data.doubleValue;
        }
        case EzyValueType::TypeInt: {
            return data.i64Value;
        }
        case EzyValueType::TypeUInt: {
            return data.ui64Value;
        }
        default: {
            return data.i64Value;
        }
    }
}

uint64_t EzyPrimitive::getUInt() {
    switch (mValueType) {
        case EzyValueType::TypeBool: {
            return data.boolValue ? 1 : 0;
        }
        case EzyValueType::TypeFloat: {
            return data.floatValue;
        }
        case EzyValueType::TypeDouble: {
            return data.doubleValue;
        }
        case EzyValueType::TypeInt: {
            return data.i64Value;
        }
        case EzyValueType::TypeUInt: {
            return data.ui64Value;
        }
        default: {
            return data.ui64Value;
        }
    }
}

std::string EzyPrimitive::toString() const {
    switch (mValueType) {
        case EzyValueType::TypeBool: {
            return data.boolValue ? "true" : "false";
        }
        case EzyValueType::TypeFloat: {
            return std::to_string(data.floatValue);
        }
        case EzyValueType::TypeDouble: {
            return std::to_string(data.doubleValue);
        }
        case EzyValueType::TypeInt: {
            return std::to_string(data.i64Value);
        }
        case EzyValueType::TypeUInt: {
            return std::to_string(data.ui64Value);
        }
        default: {
            return "null";
        }
    }
}

EZY_NAMESPACE_END_WITH
