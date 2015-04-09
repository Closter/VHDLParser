#include "contextfilevhdl.h"


ContextFileVHDL::ContextFileVHDL(Word *startingWord, Word *endingWord, QObject *parent):
  AbstractContext(startingWord, endingWord, parent)
{
}



/**
 * @brief ContextFileVHDL::analyze Extract all sub context.
 * For a VHDL file, the existing context are :
 * - Library declaration
 * - Library usage
 * - Entity declaration
 * - Package declaration
 * - Architecture declaration
 * - Package body
 */
void ContextFileVHDL::analyze()
{
  QList<Word*> wordList = getWordList();  // The word list for this context


}
