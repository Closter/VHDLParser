#include "vp_library.h"


#define VP_LIBRARY_KEYWORD_ALL  "all"


VP_Library::VP_Library(QPoint posLibrary, QPoint posPackage, QString libraryName, QString packageName, QString partName, QObject *parent) :
  QObject(parent)
{
  m_posLibrary  = posLibrary;
  m_posPackage  = posPackage;

  m_library = libraryName;
  m_package = packageName;
  m_part    = partName;

  // Are all package used
  if(partName.compare(VP_LIBRARY_KEYWORD_ALL, Qt::CaseInsensitive) == 0)
    m_allPackages = true;
  else
    m_allPackages = false;
}
