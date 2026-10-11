#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
private:
    std::string title;
    std::vector<std::string> paragraphs;

public:
    explicit Document(std::string documentTitle) : title(std::move(documentTitle)) {}

    void addParagraph(const std::string& paragraph) {
        paragraphs.push_back(paragraph);
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    std::unique_ptr<Document> clone() const {
        return std::make_unique<Document>(*this);
    }

    void show() const {
        std::cout << "Title: " << title << "\n";
        for (const auto& paragraph : paragraphs)
            std::cout << "- " << paragraph << "\n";
    }
};

int main() {
    Document original("Project Plan");
    original.addParagraph("Introduction");
    original.addParagraph("Requirements");

    std::unique_ptr<Document> copy = original.clone();
    copy->setTitle("Project Plan - Copy");
    copy->addParagraph("Implementation details");

    std::cout << "Original document:\n";
    original.show();

    std::cout << "\nCloned and modified document:\n";
    copy->show();

    return 0;
}
