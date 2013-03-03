//      Copyright 2012 Saurabh Sood <saurabh@saurabh.geeko>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      


#include "mainheader.h"

MainHeader::MainHeader( QWidget *parent )
{
    setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );
    setStyleSheet( "background-color : rgb(251,248,241)" );
    m_statusLabel = new QLabel( "This installer will install and download packages" );

    m_statusLabel->setWordWrap( true );
    m_statusLabel->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    const QPixmap icon( "/usr/share/icons/hicolor/32x32/apps/oneclickinstall.png" );
    m_icon = new QLabel;
    m_icon->setPixmap( icon );

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget( m_icon );
    mainLayout->setSpacing( 20 );
    mainLayout->addWidget( m_statusLabel );

    setLayout( mainLayout );
    show();
}

void MainHeader::changeStatusLabel( int repoCount, int packageCount )
{
    m_packageCount = packageCount;
    m_repoCount = repoCount;

    QString statusText = QString( tr( "This installer will download and install %n package(s) ", "", m_packageCount ) );
    statusText.append( QString( tr( "from %n source(s)", "", m_repoCount ) ) );

//    if( m_packageCount > 1 )
//        statusText.append( " packages" );
//    else
//        statusText.append( " package" );

//    if( m_repoCount > 1 )
//        statusText.append( QString( " from %1 sources" ).append( m_repoCount ) );
//    else
//        statusText.append( " from 1 source");
    m_statusLabel->setText( statusText );
}

void MainHeader::updateDetails( QString size )
{
    QString statusText = QString( "This installer will download and install %1" ).arg( m_packageCount );

    if( m_packageCount > 1 )
        statusText.append( " packages" );
    else
        statusText.append( " package" );

    if( m_repoCount > 1 )
        statusText.append( QString( " from %1 sources" ).append( m_repoCount ) );
    else
        statusText.append( " from 1 source");
    statusText.append( QString( " totalling %1" ).arg( size ) );

    m_statusLabel->setText( statusText );
}

void MainHeader::installationStarted()
{
    m_statusLabel->setText( "Downloading and Installing Packages..." );
}

void MainHeader::installationCompleted()
{
    m_statusLabel->setText( "Success!!!" );
}
