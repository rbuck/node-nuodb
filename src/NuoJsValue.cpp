#include "NuoJsValue.h"

#include <sstream>
#include <iostream>

namespace NuoJs
{
SqlValue::SqlValue()
{}

SqlValue::SqlValue(const SqlValue& rhs)
    : name(rhs.name),
      sqlType(rhs.sqlType),
      u(rhs.u)
/*
      b(rhs.b),
      i8(rhs.i8),
      i16(rhs.i16),
      i32(rhs.i32),
      i64(rhs.i64),
      f4(rhs.f4),
      f8(rhs.f8),
      s(rhs.s),
*/
{}

const char* SqlValue::getName() const
{
    return name;
}
void SqlValue::setName(const char* s)
{
    name = s;
}

int SqlValue::getSqlType() const
{
    return sqlType;
}
void SqlValue::setSqlType(int type)
{
    sqlType = type;
}

bool SqlValue::getBoolean() const
{
    return u.b;
}
void SqlValue::setBoolean(bool value)
{
    u.b = value;
}

float SqlValue::getFloat() const
{
    return u.f4;
}
void SqlValue::setFloat(float value)
{
    u.f4 = value;
}

double SqlValue::getDouble() const
{
    return u.f8;
}
void SqlValue::setDouble(double value)
{
    u.f8 = value;
}

int8_t SqlValue::getByte() const
{
    return u.i8;
}
void SqlValue::setByte(int8_t value)
{
    u.i8 = value;
}

int16_t SqlValue::getShort() const
{
    return u.i16;
}
void SqlValue::setShort(int16_t value)
{
    u.i16 = value;
}

int32_t SqlValue::getInt() const
{
    return u.i32;
}
void SqlValue::setInt(int32_t value)
{
    u.i32 = value;
}

int64_t SqlValue::getLong() const
{
    return u.i64;
}
void SqlValue::setLong(int64_t value)
{
    u.i64 = value;
}

const char* SqlValue::getString() const
{
    return u.s;
}
void SqlValue::setString(const char* value)
{
    u.s = value;
}

std::string int64ToString(int64_t v)
{
    std::ostringstream os;
    os << v;
    return os.str();
}
}