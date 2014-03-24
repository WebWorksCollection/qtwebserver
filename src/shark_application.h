//
// Copyright 2010-2014 Jacob Dawid <jacob.dawid@cybercatalyst.net>
//
// This file is part of Shark.
//
// Shark is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Shark is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Shark.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SHARK_APPLICATION_H
#define SHARK_APPLICATION_H

// Own includes
#include "shark_http_responder.h"
#include "shark_resourcecache.h"
#include "shark_logger.h"

// Qt includes
#include <QString>

namespace Shark {

class Engine;

/**
 * @brief The Application class
 */
class Application : public Logger, public Http::Responder {
public:
    Application(QString rootDirectory);

    /**
     * @brief respond
     * @param request
     * @param response
     */
    void respond(Http::Request& request, Http::Response& response);

private:
    QString _rootDirectory;
    Engine *_engine;
};

} // namespace Shark

#endif // SHARK_APPLICATION_H
