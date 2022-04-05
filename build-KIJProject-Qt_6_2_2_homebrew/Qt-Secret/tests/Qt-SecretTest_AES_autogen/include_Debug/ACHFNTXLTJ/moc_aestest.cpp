/****************************************************************************
** Meta object code from reading C++ file 'aestest.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../Qt-Secret/src/Qt-AES/unit_test/aestest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aestest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AesTest_t {
    const uint offsetsAndSize[38];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AesTest_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AesTest_t qt_meta_stringdata_AesTest = {
    {
QT_MOC_LITERAL(0, 7), // "AesTest"
QT_MOC_LITERAL(8, 12), // "initTestCase"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 11), // "ECB128Crypt"
QT_MOC_LITERAL(34, 13), // "ECB128Decrypt"
QT_MOC_LITERAL(48, 11), // "ECB192Crypt"
QT_MOC_LITERAL(60, 13), // "ECB192Decrypt"
QT_MOC_LITERAL(74, 11), // "ECB256Crypt"
QT_MOC_LITERAL(86, 13), // "ECB256Decrypt"
QT_MOC_LITERAL(100, 12), // "ECB256String"
QT_MOC_LITERAL(113, 11), // "CBC128Crypt"
QT_MOC_LITERAL(125, 13), // "CBC128Decrypt"
QT_MOC_LITERAL(139, 12), // "CFB256String"
QT_MOC_LITERAL(152, 14), // "CFB256LongText"
QT_MOC_LITERAL(167, 11), // "OFB128Crypt"
QT_MOC_LITERAL(179, 12), // "OFB256String"
QT_MOC_LITERAL(192, 19), // "CBC256StringEvenISO"
QT_MOC_LITERAL(212, 21), // "CBC256StringEvenPKCS7"
QT_MOC_LITERAL(234, 15) // "cleanupTestCase"

    },
    "AesTest\0initTestCase\0\0ECB128Crypt\0"
    "ECB128Decrypt\0ECB192Crypt\0ECB192Decrypt\0"
    "ECB256Crypt\0ECB256Decrypt\0ECB256String\0"
    "CBC128Crypt\0CBC128Decrypt\0CFB256String\0"
    "CFB256LongText\0OFB128Crypt\0OFB256String\0"
    "CBC256StringEvenISO\0CBC256StringEvenPKCS7\0"
    "cleanupTestCase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AesTest[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    1 /* Private */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    0,  121,    2, 0x08,    6 /* Private */,
       8,    0,  122,    2, 0x08,    7 /* Private */,
       9,    0,  123,    2, 0x08,    8 /* Private */,
      10,    0,  124,    2, 0x08,    9 /* Private */,
      11,    0,  125,    2, 0x08,   10 /* Private */,
      12,    0,  126,    2, 0x08,   11 /* Private */,
      13,    0,  127,    2, 0x08,   12 /* Private */,
      14,    0,  128,    2, 0x08,   13 /* Private */,
      15,    0,  129,    2, 0x08,   14 /* Private */,
      16,    0,  130,    2, 0x08,   15 /* Private */,
      17,    0,  131,    2, 0x08,   16 /* Private */,
      18,    0,  132,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AesTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AesTest *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->ECB128Crypt(); break;
        case 2: _t->ECB128Decrypt(); break;
        case 3: _t->ECB192Crypt(); break;
        case 4: _t->ECB192Decrypt(); break;
        case 5: _t->ECB256Crypt(); break;
        case 6: _t->ECB256Decrypt(); break;
        case 7: _t->ECB256String(); break;
        case 8: _t->CBC128Crypt(); break;
        case 9: _t->CBC128Decrypt(); break;
        case 10: _t->CFB256String(); break;
        case 11: _t->CFB256LongText(); break;
        case 12: _t->OFB128Crypt(); break;
        case 13: _t->OFB256String(); break;
        case 14: _t->CBC256StringEvenISO(); break;
        case 15: _t->CBC256StringEvenPKCS7(); break;
        case 16: _t->cleanupTestCase(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject AesTest::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AesTest.offsetsAndSize,
    qt_meta_data_AesTest,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AesTest_t
, QtPrivate::TypeAndForceComplete<AesTest, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AesTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AesTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AesTest.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AesTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
