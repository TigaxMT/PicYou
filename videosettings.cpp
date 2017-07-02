/************************************************************************************************************
*    											                                                            *
*    PicMoments - Is a simple program to take photos. Written on C++ and using Opencv library and QT Framework *
*											                                                                *
*    Copyright (C) 2017  Tiago Martins                        				                                *
*											                                                                *
*    This program is free software: you can redistribute it and/or modify		                            *
*    it under the terms of the GNU General Public License as published by                                   *
*    the Free Software Foundation, either version 3 of the License, or                                      *
*    (at your option) any later version. 					                                                *
*											                                                                *
*    This program is distributed in the hope that it will be useful,			                            *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of			                                *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			                                *
*    GNU General Public License for more details.					                                        *
*											                                                                *
*    You should have received a copy of the GNU General Public License			                            *
*    along with this program. If not, see <http://www.gnu.org/licenses/>.                                   *
*											                                                                *
*************************************************************************************************************/

#include "videosettings.h"
#include "ui_videosettings.h"

VideoSettings::VideoSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoSettings)
{
    ui->setupUi(this);

    dlgExec = true;

    ui->extBox->addItem(".avi");
    ui->extBox->addItem(".mov");

    ui->codecsBox->addItem("XVID");
    ui->codecsBox->addItem("MPEG-4");
    ui->codecsBox->addItem("MPEG-4.2");
    ui->codecsBox->addItem("MPEG-4.3");
    ui->codecsBox->addItem("MJPG");
}

VideoSettings::~VideoSettings()
{
    delete ui;
}

void VideoSettings::reject()
{
    dlgExec = false;

    QDialog::reject();
}

int VideoSettings::getCodecVal()
{
    return ui->codecsBox->currentIndex();
}

int VideoSettings::getExtVal()
{
    return ui->extBox->currentIndex();
}

void VideoSettings::on_okBtn_clicked()
{
    this->close();
}
