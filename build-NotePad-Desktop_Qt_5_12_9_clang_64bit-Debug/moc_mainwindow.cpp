/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NotePad/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "doProcessTriggeredByNew"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "doProcessTriggeredByOpen"
QT_MOC_LITERAL(4, 61, 25), // "doProcessTriggeredByUTF_8"
QT_MOC_LITERAL(5, 87, 26), // "doProcessTriggeredByGB2312"
QT_MOC_LITERAL(6, 114, 22), // "doProcessTriggerByExit"
QT_MOC_LITERAL(7, 137, 22), // "doProcessTriggerBySave"
QT_MOC_LITERAL(8, 160, 24), // "doProcessTriggerBySaveAs"
QT_MOC_LITERAL(9, 185, 23), // "doProcessTriggerByClose"
QT_MOC_LITERAL(10, 209, 26), // "doProcessTriggerByCloseAll"
QT_MOC_LITERAL(11, 236, 22), // "doProcessTriggerByTile"
QT_MOC_LITERAL(12, 259, 25), // "doProcessTriggerByCascade"
QT_MOC_LITERAL(13, 285, 22), // "doProcessTriggerByNext"
QT_MOC_LITERAL(14, 308, 26), // "doProcessTriggerByPrevious"
QT_MOC_LITERAL(15, 335, 23), // "doProcessTriggerByAbout"
QT_MOC_LITERAL(16, 359, 25) // "doProcessTriggerByAboutQt"

    },
    "MainWindow\0doProcessTriggeredByNew\0\0"
    "doProcessTriggeredByOpen\0"
    "doProcessTriggeredByUTF_8\0"
    "doProcessTriggeredByGB2312\0"
    "doProcessTriggerByExit\0doProcessTriggerBySave\0"
    "doProcessTriggerBySaveAs\0"
    "doProcessTriggerByClose\0"
    "doProcessTriggerByCloseAll\0"
    "doProcessTriggerByTile\0doProcessTriggerByCascade\0"
    "doProcessTriggerByNext\0"
    "doProcessTriggerByPrevious\0"
    "doProcessTriggerByAbout\0"
    "doProcessTriggerByAboutQt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       3,    1,   92,    2, 0x08 /* Private */,
       4,    1,   95,    2, 0x08 /* Private */,
       5,    1,   98,    2, 0x08 /* Private */,
       6,    1,  101,    2, 0x08 /* Private */,
       7,    1,  104,    2, 0x08 /* Private */,
       8,    1,  107,    2, 0x08 /* Private */,
       9,    1,  110,    2, 0x08 /* Private */,
      10,    1,  113,    2, 0x08 /* Private */,
      11,    1,  116,    2, 0x08 /* Private */,
      12,    1,  119,    2, 0x08 /* Private */,
      13,    1,  122,    2, 0x08 /* Private */,
      14,    1,  125,    2, 0x08 /* Private */,
      15,    1,  128,    2, 0x08 /* Private */,
      16,    1,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doProcessTriggeredByNew((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->doProcessTriggeredByOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->doProcessTriggeredByUTF_8((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->doProcessTriggeredByGB2312((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->doProcessTriggerByExit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->doProcessTriggerBySave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->doProcessTriggerBySaveAs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->doProcessTriggerByClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->doProcessTriggerByCloseAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->doProcessTriggerByTile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->doProcessTriggerByCascade((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->doProcessTriggerByNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->doProcessTriggerByPrevious((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->doProcessTriggerByAbout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->doProcessTriggerByAboutQt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
