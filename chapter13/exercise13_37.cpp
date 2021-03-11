#include<string>
#include<set>
#include<iostream>
#include<algorithm>

class Message {
	friend class Folder;
public:
	explicit Message(const std::string& str = "") :
		contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;
	void addto(Folder* f) { folders.insert(f); };
	void revfrom(Folder* f) { folders.erase(f); };
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder {
	friend Message;
public:
	Folder(const std::string& s = "") : name(s) {};
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void display() { for_each(messages.cbegin(), messages.cend(), [](Message* m) {std::cout << m->contents << std::endl; }); }
private:
	std::string name;
	std::set<Message*> messages;
	void addMsg(Message* m_ptr) { messages.insert(m_ptr); };
	void remMsg(Message* m_ptr) { messages.erase(m_ptr); };
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.messages) {
		m->folders.insert(this);
	}
}

Folder::Folder(const Folder& f) :
	name(f.name), messages(f.messages)
{
	add_to_Message(f);
}

void Folder::remove_from_Message()
{
	for (auto m : messages) {
		m->folders.erase(this);
	}
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator=(const Folder& f)
{
	remove_from_Message();
	name = f.name;
	messages = f.messages;
	add_to_Message(*this);
	return *this;
}
//class Folder;

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders) {
		f->remMsg(this);
	}
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}



int main()
{
	Message m1("m1");
	Message m2("m2");
	
	Folder f1("f1");
	Folder f2("f2");
	m1.save(f1);
	m2.save(f2);
	Message m3(m2);
	m3 = m1;
	std::cout << "f1:" << std::endl;
	f1.display();
	std::cout << "f2:" << std::endl;
	f2.display();

	m1.remove(f1);
	m1.save(f2);
	std::cout << "f1:" << std::endl;
	f1.display();
	std::cout << "f2:" << std::endl;
	f2.display();
}