#include "wget.h"
#include "url.h"
#include <attr/xattr.h>

int set_xattr( struct url *origin, const char *filename ) {
  char *url = url_string(origin, URL_AUTH_HIDE);
  logprintf (LOG_VERBOSE, _("Placing URL '%s' in extended attributes.\n"), url);
  int err = setxattr( filename, "user.wget.origin", url, strlen(url), 0 );
  if (err) {
    logprintf (LOG_NOTQUIET, "setxattr: %s\n", strerror (errno));
  }
  return err;
}
