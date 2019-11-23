#include <cstdio>
#include <memory>
#include <iostream>
#include <string>
#include "customset.h"

#ifndef H_gechatuser
#define H_gechatuser

class GechatUser
{
public:
	// Assume using namespace std;
	GechatUser() {}
	GechatUser(std::string username);
	GechatUser(const GechatUser& other);
	~GechatUser() {}

	int numFriends() const;
	void setUsername(const std::string& _username);
	bool haveFriend(std::shared_ptr<GechatUser> user); // return true if user is a friend to *this.
	bool addFriend(std::shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
	bool singleDelete(std::shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool singleDelete(std::string username); // return false only if username not found in friends.
	bool doubleDelete(std::shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool doubleDelete(std::string username); // return false only if username not found in friends.

	friend std::ostream& operator<<(std::ostream& out, const GechatUser& user);

	bool operator ==(const GechatUser& user) {
		return this->username == user.username;
	}
	bool operator !=(const GechatUser& user) {
		return this->username != user.username;
	}
private:
	std::string username;
	CustomSet<std::shared_ptr<GechatUser>> friends;

};
#endif // !H_gechatuser

