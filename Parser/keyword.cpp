#include "keyword.h"

KeyWord::KeyWord(QString strChar, int lineNumber, int colNumber, bool isComment, Word *previous, Word *next, QObject *parent) :
  Word(strChar, lineNumber, colNumber, isComment, previous, next, parent)
{
}
