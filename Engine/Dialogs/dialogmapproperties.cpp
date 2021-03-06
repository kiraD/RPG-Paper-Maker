/*
    RPG Paper Maker Copyright (C) 2017 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dialogmapproperties.h"
#include "ui_dialogmapproperties.h"
#include "wanok.h"

// -------------------------------------------------------
//
//  CONSTRUCTOR / DESTRUCTOR / GET / SET
//
// -------------------------------------------------------

DialogMapProperties::DialogMapProperties(MapProperties &properties,
                                         QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMapProperties),
    m_mapProperties(properties)
{
    ui->setupUi(this);
    setFixedSize(geometry().width(), geometry().height());

    // Tileset
    SuperListItem::fillComboBox(ui->comboBoxTileset,
                                Wanok::get()->project()->gameDatas()
                                ->tilesetsDatas()->model());
    connect(ui->comboBoxTileset, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_comboBoxTilesetCurrentIndexChanged(int)));

    initialize();
}

DialogMapProperties::~DialogMapProperties()
{
    delete ui;
}

// -------------------------------------------------------
//
//  INTERMEDIARY FUNCTIONS
//
// -------------------------------------------------------

void DialogMapProperties::initialize(){
    ui->widgetLangName->initializeNames(&m_mapProperties);

    // Sizes
    ui->spinBoxLength->setValue(m_mapProperties.length());
    ui->spinBoxWidth->setValue(m_mapProperties.width());
    ui->spinBoxHeight->setValue(m_mapProperties.height());
    ui->spinBoxDepth->setValue(m_mapProperties.depth());

    ui->widgetConstantVariableSteps->initializeNumberVariable();
    ui->widgetConstantVariableStepsVariation->initializeNumberVariable();

    // Tileset
    ui->comboBoxTileset->setCurrentIndex(
                SuperListItem::getIndexById(Wanok::get()->project()->gameDatas()
                                            ->tilesetsDatas()->model()
                                            ->invisibleRootItem(),
                                            m_mapProperties.tileset()->id()));
}

// -------------------------------------------------------
//
//  SLOTS
//
// -------------------------------------------------------

void DialogMapProperties::on_spinBoxLength_valueChanged(int i){
    m_mapProperties.setLength(i);
}

// -------------------------------------------------------

void DialogMapProperties::on_spinBoxWidth_valueChanged(int i){
    m_mapProperties.setWidth(i);
}

// -------------------------------------------------------

void DialogMapProperties::on_spinBoxHeight_valueChanged(int i){
    m_mapProperties.setHeight(i);
}

// -------------------------------------------------------

void DialogMapProperties::on_spinBoxDepth_valueChanged(int i){
    m_mapProperties.setDepth(i);
}

// -------------------------------------------------------

void DialogMapProperties::on_comboBoxTilesetCurrentIndexChanged(int index){
    m_mapProperties.setTileset((SystemTileset*) Wanok::get()->project()
                               ->gameDatas()->tilesetsDatas()->model()
                               ->item(index)->data().value<qintptr>());
}
