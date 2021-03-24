/****************************************************************************
** Meta object code from reading C++ file 'tp4.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp4.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tp4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TP4[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      33,    4,    4,    4, 0x0a,
      61,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TP4[] = {
    "TP4\0\0dialogInscriptionCandidat()\0"
    "dialogInscriptionElecteur()\0"
    "dialogDesinscription()\0"
};

void TP4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TP4 *_t = static_cast<TP4 *>(_o);
        switch (_id) {
        case 0: _t->dialogInscriptionCandidat(); break;
        case 1: _t->dialogInscriptionElecteur(); break;
        case 2: _t->dialogDesinscription(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TP4::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TP4::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TP4,
      qt_meta_data_TP4, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TP4::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TP4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TP4::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TP4))
        return static_cast<void*>(const_cast< TP4*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TP4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
