#include <QtGui>

#include "CodeEditor.h"
#include "MarginStacker.h"

#include "SyntaxDocument.h"

class QodeEditor : public CodeEditor {
    Q_OBJECT

public:
    QodeEditor( QWidget* parent = 0 )
        : CodeEditor( parent )
    {
        // fake save document shortcut
        new QShortcut( QKeySequence::Save, this, SLOT( save() ) );
    }

protected slots:
    void save() {
        document()->setModified( false );
    }
};

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    
    QRect rect = QRect( QPoint(), QSize( 640, 480 ) );
    rect.moveCenter( QApplication::desktop()->availableGeometry().center() );
    
    MarginStacker* margins = new MarginStacker;
    margins->setVisible( MarginStacker::LineBookmark, true );
    margins->setVisible( MarginStacker::LineNumber, true );
    margins->setVisible( MarginStacker::LineRevision, true );
    margins->setVisible( MarginStacker::LineFold, true );
    margins->setVisible( MarginStacker::LineSpacing, true );
    
    QodeEditor* editor = new QodeEditor;
    editor->setMarginStacker( margins );
    editor->setGeometry( rect );
    editor->show();
    
    const QString path = "/home/pasnox/Developpement/C++/Qt5/mks-ng/3rdparty/qodeedit.git/share/syntax";
    const QFileInfoList files = QDir( path ).entryInfoList( QStringList( "*.xml" ) );
    
    QTime time;
    time.start();
    
    foreach ( const QFileInfo& file, files ) {
    qWarning() << "--- Parsing" << file.fileName();
        Syntax::Document document;
        Q_ASSERT( document.open( file.absoluteFilePath() ) );
    }
    
    qWarning() << "All languages parsed in " << time.elapsed() /1000.0 << "seconds";
    
    return app.exec();
}

#include "main.moc"
