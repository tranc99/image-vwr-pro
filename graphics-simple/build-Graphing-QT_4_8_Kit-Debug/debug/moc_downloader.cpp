/****************************************************************************
** Meta object code from reading C++ file 'downloader.h'
**
** Created: Sat Jan 11 17:10:13 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphing/downloader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Downloader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      41,   36,   11,   11, 0x0a,
      94,   85,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Downloader[] = {
    "Downloader\0\0state\0stateChanged(int)\0"
    "resp\0responseHeaderReceived(QHttpResponseHeader)\0"
    "id,error\0requestFinished(int,bool)\0"
    "readTcpData()\0"
};

void Downloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Downloader *_t = static_cast<Downloader *>(_o);
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->responseHeaderReceived((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 2: _t->requestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->readTcpData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Downloader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Downloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Downloader,
      qt_meta_data_Downloader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Downloader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Downloader))
        return static_cast<void*>(const_cast< Downloader*>(this));
    return QObject::qt_metacast(_clname);
}

int Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
