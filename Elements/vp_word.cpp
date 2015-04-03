#include "vp_word.h"

VP_Word::VP_Word(QObject *parent) :
  QObject(parent)
{
  word = "";
}


VP_Word::VP_Word(QString word_l, QObject *parent) :
  QObject(parent)
{
  word = word_l;  // Store word's text
}


/**
 * @brief VP_Word::text
 * @return The text of this word.
 */
QString VP_Word::text()
{
  return word;
}
