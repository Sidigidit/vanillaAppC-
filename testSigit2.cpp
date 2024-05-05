#include <QtWidgets>

class FileEditor : public QWidget {
public:
    FileEditor(QWidget *parent = nullptr) : QWidget(parent) {
        // Create UI components
        textEdit = new QTextEdit;
        QPushButton *loadButton = new QPushButton("Load");
        QPushButton *saveButton = new QPushButton("Save");

        // Layout setup
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(textEdit);
        layout->addWidget(loadButton);
        layout->addWidget(saveButton);

        // Connect signals and slots
        connect(loadButton, &QPushButton::clicked, this, &FileEditor::loadFile);
        connect(saveButton, &QPushButton::clicked, this, &FileEditor::saveFile);
    }

private slots:
    void loadFile() {
        QString filePath = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                textEdit->setText(in.readAll());
                file.close();
            }
        }
    }

    void saveFile() {
        QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath());
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << textEdit->toPlainText();
                file.close();
            }
        }
    }

private:
    QTextEdit *textEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileEditor editor;
    editor.show();

    return app.exec();
}
