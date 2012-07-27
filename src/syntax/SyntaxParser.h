#ifndef SYNTAXPARSER_H
#define SYNTAXPARSER_H

#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>

namespace Syntax {

class Document;
class ParserPrivate;

class Reader : public QXmlSimpleReader
{
public:
    bool parse( Syntax::Document* document, const QXmlInputSource& input );
};

class Parser : public QXmlDefaultHandler
{
    friend class Syntax::Reader;
    
public:
#if !defined( QT_NO_DEBUG )
    typedef QHash<QString, QHash<QString, QSet<QString> > > Debug;
#endif

    Parser();
    virtual ~Parser();
    
    virtual bool attributeDecl( const QString& eName, const QString& aName, const QString& type, const QString& valueDefault, const QString& value );
    virtual bool comment( const QString& ch );
    virtual bool endCDATA();
    virtual bool endDTD();
    virtual bool fatalError( const QXmlParseException& exception );
    virtual bool characters( const QString& ch );
    virtual bool startDocument();
    virtual bool endDocument();
    virtual bool startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts );
    virtual bool endElement( const QString& namespaceURI, const QString& localName, const QString& qName );
    virtual bool endEntity( const QString& name );
    virtual bool endPrefixMapping( const QString& prefix );
    virtual bool error( const QXmlParseException& exception );
    virtual QString errorString() const;
    virtual bool externalEntityDecl( const QString& name, const QString& publicId, const QString& systemId );
    virtual bool ignorableWhitespace( const QString& ch );
    virtual bool internalEntityDecl( const QString& name, const QString& value );
    virtual bool notationDecl( const QString& name, const QString& publicId, const QString& systemId );
    virtual bool processingInstruction( const QString& target, const QString& data );
    virtual bool resolveEntity( const QString& publicId, const QString& systemId, QXmlInputSource*& ret );
    virtual void setDocumentLocator( QXmlLocator* locator );
    virtual bool skippedEntity( const QString& name );
    virtual bool startCDATA();
    virtual bool startDTD( const QString& name, const QString& publicId, const QString& systemId );
    virtual bool startEntity( const QString& name );
    virtual bool startPrefixMapping( const QString& prefix, const QString& uri );
    virtual bool unparsedEntityDecl( const QString& name, const QString& publicId, const QString& systemId, const QString& notationName );
    virtual bool warning( const QXmlParseException& exception );
    
#if !defined( QT_NO_DEBUG )
    void debug() const;
#endif

private:
    ParserPrivate* d;
};

}; // Syntax

#endif // SYNTAXPARSER_H