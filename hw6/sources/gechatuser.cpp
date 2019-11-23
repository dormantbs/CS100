#include "gechatuser.h"

GechatUser::GechatUser(std::string _username) {
	this->username = _username;
}

GechatUser::GechatUser(const GechatUser& other) {
	this->username = other.username;
}

int GechatUser::numFriends() const {
	return this->friends.size();
}

void GechatUser::setUsername(const std::string& _username) {
	this->username = _username;
}

bool GechatUser::haveFriend(std::shared_ptr<GechatUser> user) {
	return this->friends.find(user) != nullptr;
}

bool GechatUser::addFriend(std::shared_ptr<GechatUser> user) {
	if (user == nullptr) return false;
	return this->friends.add(user);
}

bool GechatUser::singleDelete(std::shared_ptr<GechatUser> user) {
	if (user == nullptr) return false;
	return this->friends.erase(user);
}

bool GechatUser::singleDelete(std::string username) {
	std::shared_ptr<GechatUser> goal(nullptr);
	for (auto v : friends)
		if (v->username == username) {
			goal = v; break;
		}
	if (goal == nullptr) return false;
	return this->singleDelete(goal);
}

bool GechatUser::doubleDelete(std::shared_ptr<GechatUser> user) {
	if (user == nullptr) return false;
	user->singleDelete(this->username);
	return this->singleDelete(user);
}

bool GechatUser::doubleDelete(std::string username) {
	std::shared_ptr<GechatUser> goal(nullptr);
	for (auto v : friends)
		if (v->username == username) {
			goal = v; break;
		}
	if (goal == nullptr) return false;
	return this->doubleDelete(goal);
}

std::ostream& operator<<(std::ostream& out, const GechatUser& user) {
	return out << user.username << " (friends:" << user.numFriends() << ")";
}