import QtQuick
import QtQuick.Controls.Material

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Call QML from C++")

    function qmlJSFunction(param) {
        console.log("QML Talking, C++ called me with following parameter:" + param + "returning back something")
        return "This is QML, over to you C++. Thanks for the call !!"
    }

    Button {
        id: mButtonId
        text: qsTr("Call QML function from C++")
        onClicked: {
            QmlJsCaller.cppMethod("QML Calling....");
        }
    }
}
