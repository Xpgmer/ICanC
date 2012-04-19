/****************************************************************************
** Meta object code from reading C++ file 'userinterface.h'
**
** Created: Sun Apr 3 20:33:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      37,   14,   14,   14, 0x08,
      57,   14,   14,   14, 0x08,
      91,   14,   14,   14, 0x08,
     118,   14,   14,   14, 0x08,
     144,   14,   14,   14, 0x08,
     171,   14,   14,   14, 0x08,
     198,   14,   14,   14, 0x08,
     224,   14,   14,   14, 0x08,
     254,   14,  249,   14, 0x08,
     283,   14,  249,   14, 0x08,
     309,   14,   14,   14, 0x08,
     317,   14,   14,   14, 0x08,
     332,   14,   14,   14, 0x08,
     344,   14,  249,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserInterface[] = {
    "UserInterface\0\0on_generate_clicked()\0"
    "on_Format_clicked()\0"
    "on_actionInstructions_triggered()\0"
    "on_actionPaste_triggered()\0"
    "on_actionCopy_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionClose_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionNew_triggered()\0bool\0"
    "on_actionSave_As_triggered()\0"
    "on_actionSave_triggered()\0about()\0"
    "instructions()\0showGraph()\0maybeSave()\0"
};

const QMetaObject UserInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserInterface,
      qt_meta_data_UserInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserInterface))
        return static_cast<void*>(const_cast< UserInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UserInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_generate_clicked(); break;
        case 1: on_Format_clicked(); break;
        case 2: on_actionInstructions_triggered(); break;
        case 3: on_actionPaste_triggered(); break;
        case 4: on_actionCopy_triggered(); break;
        case 5: on_actionAbout_triggered(); break;
        case 6: on_actionClose_triggered(); break;
        case 7: on_actionOpen_triggered(); break;
        case 8: on_actionNew_triggered(); break;
        case 9: { bool _r = on_actionSave_As_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = on_actionSave_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: about(); break;
        case 12: instructions(); break;
        case 13: showGraph(); break;
        case 14: { bool _r = maybeSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
