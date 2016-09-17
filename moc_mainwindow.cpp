/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "new_diagnosticmessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "Diagnostic"
QT_MOC_LITERAL(4, 45, 17), // "new_devicemessage"
QT_MOC_LITERAL(5, 63, 6), // "Device"
QT_MOC_LITERAL(6, 70, 20), // "update_messageviewer"
QT_MOC_LITERAL(7, 91, 4), // "diag"
QT_MOC_LITERAL(8, 96, 16), // "kill_application"
QT_MOC_LITERAL(9, 113, 11), // "stop_system"
QT_MOC_LITERAL(10, 125, 13), // "launch_system"
QT_MOC_LITERAL(11, 139, 19), // "clear_messageviewer"
QT_MOC_LITERAL(12, 159, 26), // "changefilter_messageviewer"
QT_MOC_LITERAL(13, 186, 25), // "clearfilter_messageviewer"
QT_MOC_LITERAL(14, 212, 17), // "update_devicelist"
QT_MOC_LITERAL(15, 230, 6), // "device"
QT_MOC_LITERAL(16, 237, 23), // "update_devicelistviewer"
QT_MOC_LITERAL(17, 261, 16), // "change_RC_Server"
QT_MOC_LITERAL(18, 278, 3), // "set"
QT_MOC_LITERAL(19, 282, 15) // "send_RC_message"

    },
    "MainWindow\0new_diagnosticmessage\0\0"
    "Diagnostic\0new_devicemessage\0Device\0"
    "update_messageviewer\0diag\0kill_application\0"
    "stop_system\0launch_system\0clear_messageviewer\0"
    "changefilter_messageviewer\0"
    "clearfilter_messageviewer\0update_devicelist\0"
    "device\0update_devicelistviewer\0"
    "change_RC_Server\0set\0send_RC_message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   95,    2, 0x0a /* Public */,
       8,    1,   98,    2, 0x0a /* Public */,
       9,    1,  101,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x0a /* Public */,
      11,    1,  107,    2, 0x0a /* Public */,
      12,    0,  110,    2, 0x0a /* Public */,
      13,    0,  111,    2, 0x0a /* Public */,
      14,    1,  112,    2, 0x0a /* Public */,
      14,    1,  115,    2, 0x0a /* Public */,
      14,    0,  118,    2, 0x0a /* Public */,
      16,    0,  119,    2, 0x0a /* Public */,
      17,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 5,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_diagnosticmessage((*reinterpret_cast< Diagnostic(*)>(_a[1]))); break;
        case 1: _t->new_devicemessage((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 2: _t->update_messageviewer((*reinterpret_cast< const Diagnostic(*)>(_a[1]))); break;
        case 3: _t->kill_application((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->stop_system((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->launch_system((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->clear_messageviewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->changefilter_messageviewer(); break;
        case 8: _t->clearfilter_messageviewer(); break;
        case 9: _t->update_devicelist((*reinterpret_cast< const Diagnostic(*)>(_a[1]))); break;
        case 10: _t->update_devicelist((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 11: _t->update_devicelist(); break;
        case 12: _t->update_devicelistviewer(); break;
        case 13: _t->change_RC_Server((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->send_RC_message((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Diagnostic );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::new_diagnosticmessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(Device );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::new_devicemessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::new_diagnosticmessage(Diagnostic _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::new_devicemessage(Device _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
