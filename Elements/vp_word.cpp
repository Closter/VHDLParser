#include "vp_word.h"


VP_Word::VP_Word(QString word, int lineNumber, int colNumber, VP_Word *previous, VP_Word *next, QObject *parent) :
  Word(word, lineNumber, colNumber, previous, next, parent)
{
}



