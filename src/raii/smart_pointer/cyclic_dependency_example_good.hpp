#include <memory>

class Person {

public:
	Person(std::string name) :
			mName(name) {
		std::cout << "Constructor invoked for " << mName << std::endl;
	}
	~Person() {
		std::cout << "Destructor invoked for " << mName << std::endl;
	}

	void likes(std::weak_ptr<Person> crush) {
		mCrush = crush;
		std::cout << mName << " likes " << mCrush.lock()->mName << std::endl;
		std::cout << "Number of crush's admirer: " << crush.use_count()
				<< std::endl;
	}

private:
	std::weak_ptr<Person> mCrush;
	std::string mName;
};

void executeExample() {
	std::shared_ptr<Person> goodBoy = std::make_shared<Person>("Good boy");
	std::shared_ptr<Person> goodGirl = std::make_shared<Person>("Good girl");
	std::shared_ptr<Person> fckBoy = std::make_shared<Person>("fck boy");
	std::shared_ptr<Person> fckGanern = std::make_shared<Person>("fck ganern");

	goodBoy->likes(goodGirl);
	goodGirl->likes(fckBoy);
	fckBoy->likes(fckGanern);
	fckGanern->likes(goodBoy);
}
