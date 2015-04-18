#include "keyword.h"

KeyWord::KeyWord(QString strChar, int lineNumber, int colNumber, bool isEOL, bool isComment, Word *previous, Word *next, QObject *parent) :
  Word(strChar, lineNumber, colNumber, isEOL, isComment, previous, next, parent)
{
}
