#include "keyword.h"

KeyWord::KeyWord(QString strChar, int lineNumber, int colNumber, Word *previous, Word *next, QObject *parent) :
  Word(strChar, lineNumber, colNumber, previous, next, parent)
{
}
