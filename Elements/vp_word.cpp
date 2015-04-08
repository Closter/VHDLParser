#include "vp_word.h"


VP_Word::VP_Word(QString word, int lineNumber, int colNumber, bool isComment, VP_Word *previous, VP_Word *next, QObject *parent) :
  Word(word, lineNumber, colNumber, isComment, previous, next, parent)
{
}



