#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
	public:
		Exception(const QString& message);

		QString message() const;

	private:
		QString m_message;
};

#endif // EXCEPTION_H
