/****************************************************************************
**
**         Created using Monkey Studio IDE v1.9.0.1 (1.9.0.1)
** Authors   : Filipe Azevedo aka Nox P@sNox <pasnox@gmail.com> and The QodeEdit development team
** Project   : QodeEdit
** FileName  : Highlighting.cpp
** Date      : 2012-09-02T23:04:46
** License   : LGPL3
** Comment   : A source code component editor based on QPlainTextEdit/QTextDocument/QSyntaxHighlighter and Kate xml language definition files.
** Home Page : https://github.com/pasnox/qodeedit
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/
#include "Highlighting.h"

class Syntax::HighlightingData : public QSharedData
{
public:
    QString defaultContext;
    Syntax::HashList lists;
    Syntax::Context::Hash contexts;
    Syntax::ItemData::Hash itemDatas;
    
    HighlightingData()
        : QSharedData()
    {
    }
    
    HighlightingData( const Syntax::HighlightingData& other )
        : QSharedData( other ),
            QE_OTHER_INIT( defaultContext ),
            QE_OTHER_INIT( lists ),
            QE_OTHER_INIT( contexts ),
            QE_OTHER_INIT( itemDatas )
    {
    }
    
    virtual ~HighlightingData() {
    }
};

QE_IMPL_SHARED_CLASS( Highlighting )

Syntax::Highlighting::~Highlighting()
{
}

QE_IMPL_MEMBER( QString, defaultContext, Highlighting )
QE_IMPL_MEMBER( Syntax::HashList, lists, Highlighting )
QE_IMPL_MEMBER( Syntax::Context::Hash, contexts, Highlighting )
QE_IMPL_MEMBER( Syntax::ItemData::Hash, itemDatas, Highlighting )

Syntax::List Syntax::Highlighting::list( const QString& name ) const
{
    return d->lists.value( name );
}
