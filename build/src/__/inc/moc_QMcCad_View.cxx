/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_View.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_View.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_View[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,
      43,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   65,   12,   12, 0x0a,
      97,   65,   12,   12, 0x0a,
     129,   65,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     178,   12,   12,   12, 0x0a,
     198,   12,   12,   12, 0x0a,
     225,   12,   12,   12, 0x0a,
     253,   65,   12,   12, 0x0a,
     278,   65,   12,   12, 0x0a,
     304,   65,   12,   12, 0x0a,
     332,   12,   12,   12, 0x0a,
     347,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMcCad_View[] = {
    "QMcCad_View\0\0InitFinished()\0viewModified()\0"
    "SigSelectionChanged()\0e\0"
    "mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "LeaveEvent(QEvent*)\0EnterEvent(QEvent*)\0"
    "FocusInEvent(QFocusEvent*)\0"
    "FocusOutEvent(QFocusEvent*)\0"
    "wheelEvent(QWheelEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0SlotInitTask()\0"
    "PreExecute()\0"
};

void QMcCad_View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCad_View *_t = static_cast<QMcCad_View *>(_o);
        switch (_id) {
        case 0: _t->InitFinished(); break;
        case 1: _t->viewModified(); break;
        case 2: _t->SigSelectionChanged(); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->LeaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 7: _t->EnterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 8: _t->FocusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 9: _t->FocusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 10: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 11: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 12: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 13: _t->SlotInitTask(); break;
        case 14: _t->PreExecute(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMcCad_View::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCad_View::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_QMcCad_View,
      qt_meta_data_QMcCad_View, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCad_View::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCad_View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCad_View::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCad_View))
        return static_cast<void*>(const_cast< QMcCad_View*>(this));
    if (!strcmp(_clname, "McCadCom_CasView"))
        return static_cast< McCadCom_CasView*>(const_cast< QMcCad_View*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int QMcCad_View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QMcCad_View::InitFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMcCad_View::viewModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMcCad_View::SigSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
