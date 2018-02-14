#ifndef USERENTRY_H
#define USERENTRY_H

#include "json.hpp"

#include "baseitem.h"

namespace OPVault {

class UserItem : public BaseItem {
    friend class File;

protected:
    UserItem() {
        tx = 0;
    }

    UserItem(long _created,
             std::string _o,
             long _tx,
             long _updated,
             std::string _uuid) :
        created(_created),
        o(_o),
        tx(_tx),
        updated(_updated),
        uuid(_uuid)
    {}

    virtual ~UserItem() {}

    virtual void init();
    void setup_update();
    virtual void to_json(nlohmann::json &j) = 0;

public:
    std::string& get_overview() { return o; }
    std::string& get_uuid() { return uuid; }

    void set_overview(const std::string &_o);

    void decrypt_overview(std::string &overview);

protected:
    long created;
    std::string o;
    long tx;
    long updated;
    std::string uuid;

    bool updateState;
};

}

#endif // USERENTRY_H
