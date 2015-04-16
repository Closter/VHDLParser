#include "word.h"


Word::Word(QString text, int lineNumber, int colNumber, bool isComment, Word *previous, Word *next, QObject *parent) :
  QObject(parent)
{
  // Update word's member
  m_wordText    = text;
  m_lineNumber  = lineNumber;
  m_colNumber   = colNumber;

  m_previousWord  = previous;
  m_nextWord      = next;

  m_isComment = isComment;
}


/**
 * @brief Word::nextWord Return the word next to this word.
 * @param nextComment If true, return the next word, this word could be a comment. If False, this word could not be a comment.
 * @return
 */
Word *Word::nextWord(bool nextComment)
{
  Word *w = m_nextWord; // Init on the next word

  if(nextComment)
    return m_nextWord;
  else
  {
    while(w != NULL)      // Run until no more next word
    {
      if(!w->isComment()) // Not a comment, we get it !
        break;

      w = w->nextWord();  // Any next word
    }
  }

  return w;
}


/**
 * @brief Word::previousWord Return the word before this word.
 * @param nextComment If true, return the word before, this word could be a comment. If False, this word could not be a comment.
 * @return
 */
Word *Word::previousWord(bool nextComment)
{
  Word *w = m_previousWord; // Init on the previous word

  if(nextComment)
    return m_previousWord;
  else
  {
    while(w != NULL)      // Run until no more previous word
    {
      if(!w->isComment()) // Not a comment, we get it !
        break;
    }

    w = w->previousWord();  // Any previous word
  }

  return w;
}




/**
 * @brief Word::nextWord Return the word next to this word after nbWord.
 * nextWord(1) is equivalent to nextWord().
 * @param nbWord Nb word to skip
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::nextWord(int nbWord, bool nextComment)
{
  Word *next = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(next->nextWord(nextComment) != NULL)  // Word exists
      next = next->nextWord(nextComment);    // Jump to this word
    else
      return NULL;                // No word after this position
  }

  return next;
}


/**
 * @brief Word::previousWord Return the word befor to this word skipping nbWord.
 * previousWord(1) is equivalent to previousWord().
 * @param nbWord Nb word to skip
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::previousWord(int nbWord, bool nextComment)
{
  Word *prev = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(prev->previousWord(nextComment) != NULL)  // Word exists
      prev = prev->previousWord(nextComment);    // Jump to this word
    else
      return NULL;                    // No word after this position
  }

  return prev;
}

