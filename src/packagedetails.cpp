#include "packagedetails.h"

PackageDetails::PackageDetails(OCI::Package *package, int count, QObject *parent )
{
    setStyleSheet( "background-color : white" );
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing( 0 );
    QHBoxLayout *packageLayout = new QHBoxLayout;
    m_summary = new QLabel( QString( "<b>Summary:</b> %1" ).arg( package->summary() ) );
    m_packageName = new QCheckBox( package->name() );
    m_showDescription = new QLabel( QString( "<a href = %1>Show Details</a>" ).arg( count ) );
    m_description = new QLabel( QString( "%1" ).arg( package->description() ) );

    m_descriptionVisible = false;

    QObject::connect( m_showDescription, SIGNAL( linkActivated( QString ) ), this, SLOT( showPackageDescription( QString ) ) );

    m_packageName->setContentsMargins( 20,20,20,20 );
    m_packageName->setStyleSheet( "background-color : white; border-left : 1px solid rgb(196,181,147);  padding-top : 10px; padding-bottom : 10px; padding-left : 3px;" );
    m_summary->setStyleSheet( "background-color : white; border-left : 1px solid rgb(196,181,147); border-right : 1px solid rgb(196,181,147);  padding-top : 10px; padding-bottom : 10px; padding-left : 3px;" );

    m_showDescription->setStyleSheet( "background-color : white;border-right : 1px solid rgb(196,181,147); " );
    m_description->setStyleSheet( "background-color : white; border-bottom : 1px solid rgb(196,181,147); border-left : 1px solid rgb(196,181,147); border-right : 1px solid rgb(196,181,147);" );
    m_description->setContentsMargins( 10, 10, 10, 10 );

    packageLayout->addWidget( m_packageName );
    packageLayout->addWidget( m_showDescription );
    mainLayout->addLayout( packageLayout );
    mainLayout->addWidget( m_summary );
    setLayout( mainLayout );
}

void PackageDetails::showPackageDescription( QString link )
{
    int linkNo = link.toInt();
    qDebug() << linkNo;

    if( m_descriptionVisible ) {
        m_showDescription->setText( QString( "<a href = %1>Show Details</a>" ).arg( linkNo ) );
        m_description->hide();
        m_descriptionVisible = false;
    } else {
        m_showDescription->setText( QString( "<a href = %1>Hide Details</a>" ).arg( linkNo ) );
        this->layout()->addWidget( m_description );
        m_description->show();
        m_descriptionVisible = true;
    }
}