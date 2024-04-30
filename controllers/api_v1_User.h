#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
  namespace v1
  {
    class User : public drogon::HttpController<User>
    {
    public:
      METHOD_LIST_BEGIN
      // use METHOD_ADD to add your custom processing function here;
      // METHOD_ADD(User::get, "/{2}/{1}", Get); // path is /api/v1/User/{arg2}/{arg1}
      // METHOD_ADD(User::your_method_name, "/{1}/{2}/list", Get); // path is /api/v1/User/{arg1}/{arg2}/list
      // ADD_METHOD_TO(User::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

      METHOD_ADD(User::getAllUsers, "", Get);
      METHOD_ADD(User::getUserById, "/{1}", Get);
      METHOD_ADD(User::handleLogin, "/login", Post, Options);
      METHOD_ADD(User::handleSignin, "/signin", Post, Options);
      METHOD_LIST_END
      // your declaration of processing function maybe like this:
      // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
      // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

      void getAllUsers(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;

      void getUserById(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string id) const;

      void handleLogin(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
      void handleSignin(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
    };
  }
}
