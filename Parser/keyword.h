#ifndef KEYWORD_H
#define KEYWORD_H

#include "word.h"

/**
 * @brief The KeyWord class describe a character which has a
 * particular meaning for the analyzis.
 */
class KeyWord : public Word
{
  Q_OBJECT
public:
  explicit KeyWord(QString strChar, int lineNumber = -1, int colNumber = -1, bool isComment = false, Word *previous = 0, Word *next = 0, QObject *parent = 0);


private:

};

#endif // KEYWORD_H
