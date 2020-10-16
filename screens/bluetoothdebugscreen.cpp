#include "bluetoothdebugscreen.h"
#include "ui_bluetoothdebugscreen.h"
#include "ex_variables.h"

#define MAX_ROW_ITEMS       50000
BluetoothDebugScreen::BluetoothDebugScreen(QWidget *parent,
                                           SettingsWindowBasic * settingsBasicBackend)
    : QDialog(parent),
    ui(new Ui::BluetoothDebugScreen),
    settingsBasicScreen(settingsBasicBackend)
{
    hide();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowState(Qt::WindowFullScreen);
    setGeometry(0,0,width(),height());
    indexCount = 0;

    if(settingsBasicScreen)
    {
        connect(settingsBasicScreen,SIGNAL(showBluetoothDebugScreen()),
                this,SLOT(show()));
    }

    ui->decrementButton->hide();
    ui->incrementButton->hide();
    ui->textTransferSize->hide();

    // ListWidget
//    ui->bluetoothListView->setWordWrap(true);
//    ui->bluetoothListView->setSpacing(2);
    ui->bluetoothListWidget->setUniformItemSizes(true);

    ui->bluetoothListWidget->setWordWrap(true);
    ui->bluetoothListWidget->setSpacing(2);

//    ui->bluetoothListView->setVerticalScrollMode((QAbstractItemView::ScrollPerPixel);

//    listViewModel.setStringList(listView);
//    ui->bluetoothListView->setModel(listViewModel);

    ui->bluetoothListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    //Enable Scrolling mechanism for scroll area
//    QScroller::grabGesture(ui->bluetoothListView,QScroller::LeftMouseButtonGesture);
    QScroller::grabGesture(ui->bluetoothListWidget,QScroller::LeftMouseButtonGesture);

    /* TODO Remove every time updation
     * Update only when Bluetooth debug screen is open
    */
    bluetoothDebugEnable = true;

    QFont text("Roboto-Light",8);
    ui->bluetoothListWidget->setFont(text);

    for(int i=0;i < MAX_ROW_ITEMS;i++){
        QListWidgetItem * item = new QListWidgetItem;
        item->setHidden(true);
        ui->bluetoothListWidget->insertItem(i,item);
    }
}

BluetoothDebugScreen::~BluetoothDebugScreen()
{
    delete ui;
}

void BluetoothDebugScreen::resetLogScreen(void)
{
    for(int i=0;i < MAX_ROW_ITEMS;i++){
        QListWidgetItem * listItemLocal = ui->bluetoothListWidget->item(i);
        if(listItemLocal->isHidden() == false)
            listItemLocal->setHidden(true);
    }

    indexCount = 0;
}

void BluetoothDebugScreen::on_backBluetoothDebug_pressed()
{
    hide();
}

void BluetoothDebugScreen::addRowData(const QString & data,BluetoothDebugColorType colorType)
{
    if(bluetoothDebugEnable == false)
        return;

    if(indexCount < ui->bluetoothListWidget->count())
    {
        QListWidgetItem * listItemLocal = ui->bluetoothListWidget->item(indexCount);
        QColor bkColor;
        QColor txtColor;

        switch(colorType)
        {
        case BLUETOOTH_TRANSMIT:
            bkColor = QColor(0x009688);
            txtColor = QColor("black");
            break;
        case BLUETOOTH_RECEIVE:
            bkColor = QColor(0xb28704);
            txtColor = QColor("black");
            break;
        case BLUETOOTH_DATA:
            bkColor = QColor(0x292929);
            txtColor = QColor("gray");
            break;
        }
        listItemLocal->setBackgroundColor(bkColor);
        listItemLocal->setTextColor(txtColor);
        listItemLocal->setText(data);
        listItemLocal->setHidden(false);

        ui->bluetoothListWidget->scrollToItem(listItemLocal);
        indexCount++;
    }
    else
    {
        qCritical() << Q_FUNC_INFO << "No more items available" << indexCount << ui->bluetoothListWidget->count();
    }

    logToFile(data);
}

void BluetoothDebugScreen::setBleDebugFilePath(const QString & filePath)
{
    qDebug() <<  Q_FUNC_INFO << "Ble Debug File Path" << filePath;
//    bleDebugFilePath.clear();
//    bleDebugFilePath.append(filePath);
}

void BluetoothDebugScreen::logToFile(const QString & localStrData)
{
    QString dateStr = QDate::currentDate().toString("d/MMM/yyyy ");
    QString timeStr = QTime::currentTime().toString("hh:mm:ss:zzz ");

    QString pathName = QString("%1/ble_log.txt").arg(Providers::getEdfLogFilesPath());

    QFile localFile(pathName);

    if (!localFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    localFile.seek(localFile.size());
    QTextStream outStream(&localFile);

    outStream << dateStr << timeStr << localStrData << "\n";

    localFile.close();
}

void BluetoothDebugScreen::on_decrementButton_released()
{
    if(fileTransferPacketSize > 20)    fileTransferPacketSize--;
    ui->textTransferSize->setText(QString::number(fileTransferPacketSize));
}

void BluetoothDebugScreen::on_incrementButton_released()
{
    fileTransferPacketSize++;
    ui->textTransferSize->setText(QString::number(fileTransferPacketSize));
}

void BluetoothDebugScreen::changeEvent(QEvent* e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
