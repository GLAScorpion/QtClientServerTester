import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import my.handler 1.0

ApplicationWindow {
    required property ClientHandler handler
    id: mainwin
    width: 768
    height: 1280
    visible: true
    title: qsTr("Client Tester")
    menuBar : MenuBar{

        Menu{
            title: qsTr("Client Tester")
            Button{
                text: qsTr("Set ip/port")
                onClicked: popip.open()
            }
            Button{
                text: qsTr("Set nickname")
            }
            Button{
                text: qsTr("Connect")
            }

        }
    }
    Popup{
        id: popip
        anchors.centerIn: Overlay.overlay
        width: iprect.childrenRect.width + 20
        height: iprect.childrenRect.height + iprectbutton.childrenRect.height + 30
        modal: true
        focus: true


            ColumnLayout{
                anchors.centerIn: Overlay.overlay
                id:colpopip
                spacing: 10
                PaddedRectangle{
                    id: iprect
                    height: 20
                    padding: 10
                    RowLayout{
                        TextField{
                            placeholderText: qsTr("Ip address")
                            width: 145
                            id: ipfield
                        }
                        Text{
                            id: iplabel
                            text: qsTr(":")
                        }
                        TextField{
                            placeholderText: qsTr("Port")
                            width: 45
                            id: portfield
                            maximumLength: 5
                        }
                    }
                }
                PaddedRectangle{
                    id: iprectbutton
                    padding: 10
                    RowLayout{

                        Button{
                            id: confirmip
                            text: qsTr("Confirm")
                            onClicked: popip.close()
                        }
                        Button{
                            id: cancelip
                            text: qsTr("Cancel")
                            onClicked: popip.close()
                        }
                    }
                }
            }

    }

    ScrollView{
        width: parent.width
        height: parent.height
        contentWidth: availableWidth
        contentHeight: log.implicitHeight
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.horizontal.interactive: false
        ScrollBar.vertical.interactive: true
        Text{
            id: log
            width: parent.width
            leftPadding: 10
            rightPadding: 10
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
            text:qsTr("Benvenuto!")
        }
    }
}



