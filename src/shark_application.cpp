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

// Own includes
#include "shark_application.h"
#include "shark_engine.h"

// Qt includes
#include <QJSValue>

namespace Shark {

Application::Application(QString rootDirectory)
    : Logger("Shark::Application"), Http::Responder() {
    _rootDirectory = rootDirectory;
    _engine = new Engine(_rootDirectory);
}

void Application::respond(Http::Request& request, Http::Response& response) {
    QString uri = request.uniqueResourceIdentifier();

    // Deliver HTML sites directly from the cache
    if(uri.endsWith("html") || uri.endsWith("htm")) {
        response.setBody(_engine->resourceCache()->read(uri));
    } else if(uri.endsWith(".js")) {
        if(!_engine->evaluate(uri, request, response)) {
            log("Error processing the requested resource", Log::Error);
        }
    } else {
        response.setBody(QString(HTML(
            <!DOCTYPE html>
            <html>
             <head>
              <title>Shark Web Application Server</title>
             </head>
             <body>))
                         + "<p>This resource is not supported.</p>" +
                         QString(HTML(
             </body>
            </html>
        )));
    }
}

} // namespace Shark
