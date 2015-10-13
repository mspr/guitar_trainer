#include "exception.h"

Exception::Exception(const QString& message)
	: m_message(message)
{
}

QString Exception::message() const
{
	return m_message;
}
