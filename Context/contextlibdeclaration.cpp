#include "contextlibdeclaration.h"

ContextLibDeclaration::ContextLibDeclaration(VP_Word *startingWord, VP_Word *endingWord, QObject *parent):
  AbstractContext(startingWord, endingWord, parent)
{
}


/**
 * @brief ContextLibDeclaration::analyze
 * @param firstWord Pointer to the first word to analyze
 */
void ContextLibDeclaration::analyze(VP_Word *firstWord)
{

}
