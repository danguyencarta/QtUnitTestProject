import QtQuick 2.15
import QtTest
import QtQuick.Controls
import TestAppLib

Item {
    MyButton {
        id: myButtonTest
    }

    TestCase {
        name: "myButtonTest"

        function test_myButtonTest() {
            verify(myButtonTest.textVisible === false, "First time")
            mouseClick(myButtonTest.testButton)
            verify(myButtonTest.textVisible === true, "Second time")
            mouseClick(myButtonTest.testButton)
            verify(myButtonTest.textVisible === false, "Second time")
        }
    }
}
