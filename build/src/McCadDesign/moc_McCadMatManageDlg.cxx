/****************************************************************************
** Meta object code from reading C++ file 'McCadMatManageDlg.hxx'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/McCadDesign/McCadMatManageDlg.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'McCadMatManageDlg.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_McCadMatManageDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      33,   18,   18,   18, 0x0a,
      47,   18,   18,   18, 0x0a,
      64,   18,   18,   18, 0x0a,
      91,   79,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_McCadMatManageDlg[] = {
    "McCadMatManageDlg\0\0AddMaterial()\0"
    "DelMaterial()\0ModifyMaterial()\0"
    "SaveMaterial()\0item,colume\0"
    "ShowSelectedMaterial(QTreeWidgetItem*,int)\0"
};

void McCadMatManageDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        McCadMatManageDlg *_t = static_cast<McCadMatManageDlg *>(_o);
        switch (_id) {
        case 0: _t->AddMaterial(); break;
        case 1: _t->DelMaterial(); break;
        case 2: _t->ModifyMaterial(); break;
        case 3: _t->SaveMaterial(); break;
        case 4: _t->ShowSelectedMaterial((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData McCadMatManageDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject McCadMatManageDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_McCadMatManageDlg,
      qt_meta_data_McCadMatManageDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &McCadMatManageDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *McCadMatManageDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *McCadMatManageDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_McCadMatManageDlg))
        return static_cast<void*>(const_cast< McCadMatManageDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int McCadMatManageDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
