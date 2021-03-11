#include<string>
#include<set>
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
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

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
	remove_from_Folders;
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

class Folder {
public:
	Folder(const std::string& s = "") {};
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	void addMsg(Message* m_ptr) { messages.insert(m_ptr); };
	void remMsg(Message* m_ptr) { messages.erase(m_ptr); };
private:
	std::set<Message*> messages;
	
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.messages) {
		m->folders.insert(this);
	}
}

Folder::Folder(const Folder& f):
	messages(f.messages)
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
	messages = f.messages;
	add_to_Message(*this);
	return *this;
}