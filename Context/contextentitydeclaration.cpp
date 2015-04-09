#include "contextentitydeclaration.h"

ContextEntityDeclaration::ContextEntityDeclaration(VP_Word *startingWord, VP_Word *endingWord, QObject *parent):
  AbstractContext(startingWord, endingWord, parent)
{
}


/**
 * @brief ContextEntityDeclaration::analyze
 * @param firstWord Pointer to the first word to analyze
 */
void ContextEntityDeclaration::analyze(VP_Word *firstWord)
{

}
