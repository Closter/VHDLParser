#include "word.h"


Word::Word(QString text, int lineNumber, int colNumber, Word *previous, Word *next, QObject *parent) :
  QObject(parent)
{
  // Update word's member
  m_wordText    = text;
  m_lineNumber  = lineNumber;
  m_colNumber   = colNumber;

  m_previousWord  = previous;
  m_nextWord      = next;
}
