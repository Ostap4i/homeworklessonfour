#include <iostream>
#include <string>

// Абстрактний клас будівельника
class MessageBuilder {
public:
    virtual void buildSubject() = 0;
    virtual void buildBody() = 0;
    virtual void buildRecipient() = 0;
    virtual std::string getMessage() = 0;
};

// Конкретний клас будівельника для текстових повідомлень
class TextMessageBuilder : public MessageBuilder {
private:
    std::string message;

public:
    void buildSubject() override {
        message += "Text Message - ";
    }

    void buildBody() override {
        message += "This is a simple text message.";
    }

    void buildRecipient() override {
        message += " [To: John Doe]";
    }

    std::string getMessage() override {
        return message;
    }
};

// Конкретний клас будівельника для електронних листів
class EmailBuilder : public MessageBuilder {
private:
    std::string message;

public:
    void buildSubject() override {
        message += "Email - ";
    }

    void buildBody() override {
        message += "This is an email body.";
    }

    void buildRecipient() override {
        message += " [To: jane@example.com]";
    }

    std::string getMessage() override {
        return message;
    }
};

// Клас директора для керування процесом будівництва повідомлень
class MessageDirector {
private:
    MessageBuilder* builder;

public:
    MessageDirector(MessageBuilder* builder) : builder(builder) {}

    void constructMessage() {
        builder->buildSubject();
        builder->buildBody();
        builder->buildRecipient();
    }
};

int main() {
    // Використання паттерна "Будівельник" для створення текстового повідомлення
    TextMessageBuilder textBuilder;
    MessageDirector textDirector(&textBuilder);
    textDirector.constructMessage();
    std::cout << "Text Message: " << textBuilder.getMessage() << std::endl;

    // Використання паттерна "Будівельник" для створення електронного листа
    EmailBuilder emailBuilder;
    MessageDirector emailDirector(&emailBuilder);
    emailDirector.constructMessage();
    std::cout << "Email: " << emailBuilder.getMessage() << std::endl;

    return 0;
}