#pragma once

#include <map>
#include <string>

class IDService {

public:
    static IDService *getInstance() {
        static IDService *_svc = NULL;
        if (!_svc)
            _svc = new IDService();
        return _svc;
    }

    bool getCtx(const char *id, void *ctx) {
        auto it = _idPool.find(id);
        if (it == _idPool.end())
            return false;
        ctx = it->second;
        return true;
    }

    bool addID(const char *id, void *ctx) {
        if (_idPool.find(id) != _idPool.end())
            return false;
        _idPool[id] = ctx;
        return true;
    }

    void delID(const char *id) {
        _idPool.erase(id);
    }

private:
    std::map<std::string, void*> _idPool;

private:
    IDService() {}
    void operator=(IDService&) = delete;
    IDService(IDService&) = delete;
};

