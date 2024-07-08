import QtQuick
import QtQuick.Controls

Column {
    id: column
    property alias textVisible: text.visible
    property alias testButton: button
    Button {
        id: button
        text: "Hello"
        onClicked: text.visible = !text.visible
    }
    Text {
        id: text
        visible: false
        text: "Text"
    }

    Binding {
        property: textVisible
        value: text.visible
    }
}
