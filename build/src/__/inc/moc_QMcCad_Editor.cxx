/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_Editor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_Editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_Editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_Editor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      38,   14,   14,   14, 0x05,
      62,   14,   14,   14, 0x05,
      80,   14,   14,   14, 0x05,
      89,   14,   14,   14, 0x05,
     106,  104,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     134,   14,   14,   14, 0x0a,
     153,   14,   14,   14, 0x0a,
     175,  173,   14,   14, 0x0a,
     201,  173,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMcCad_Editor[] = {
    "QMcCad_Editor\0\0keyPressed(QKeyEvent*)\0"
    "keyReleased(QKeyEvent*)\0updateMainTitle()\0"
    "saveAs()\0destroyed(int)\0,\0"
    "updateProgress(int,QString)\0"
    "SlotViewModified()\0updateProgress(int)\0"
    "e\0keyPressEvent(QKeyEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0"
};

void QMcCad_Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCad_Editor *_t = static_cast<QMcCad_Editor *>(_o);
        switch (_id) {
        case 0: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->keyReleased((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->updateMainTitle(); break;
        case 3: _t->saveAs(); break;
        case 4: _t->destroyed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->SlotViewModified(); break;
        case 7: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 9: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMcCad_Editor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCad_Editor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QMcCad_Editor,
      qt_meta_data_QMcCad_Editor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCad_Editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCad_Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCad_Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCad_Editor))
        return static_cast<void*>(const_cast< QMcCad_Editor*>(this));
    if (!strcmp(_clname, "McCadAEV_Editor"))
        return static_cast< McCadAEV_Editor*>(const_cast< QMcCad_Editor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QMcCad_Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QMcCad_Editor::keyPressed(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMcCad_Editor::keyReleased(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMcCad_Editor::updateMainTitle()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QMcCad_Editor::saveAs()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QMcCad_Editor::destroyed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMcCad_Editor::updateProgress(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
