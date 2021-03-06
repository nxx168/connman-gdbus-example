#ifndef CONNMAN_MANAGER_H_
#define CONNMAN_MANAGER_H_

#include <gio/gio.h>
#include <glib-object.h>
#include "connman-service.h"

G_BEGIN_DECLS

typedef struct _ConnmanManager      ConnmanManager;
typedef struct _ConnmanManagerClass ConnmanManagerClass;

struct _ConnmanManagerClass {
  GObjectClass parent_class;
};

gboolean connman_manager_connect_service(ConnmanManager *manager,
                                         ConnmanService *service,
                                         const gchar *secret);
gboolean connman_manager_enable_tethering(ConnmanManager *manager,
                                          const gchar *bssid,
                                          const gchar *secret);
gboolean connman_manager_disable_tethering(ConnmanManager *manager);

gboolean connman_manager_is_online (ConnmanManager *manager);
GSList *connman_manager_get_services(ConnmanManager *manager);
gboolean connman_manager_update_services(ConnmanManager *manager);
ConnmanManager *connman_manager_new(GBusType bus_type);

GType connman_manager_get_type (void);
#define CONNMAN_TYPE_MANAGER             connman_manager_get_type()
#define CONNMAN_MANAGER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONNMAN_TYPE_MANAGER, ConnmanManager))
#define CONNMAN_MANAGER_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), CONNMAN_TYPE_MANAGER, ConnmanManagerClass))
#define CONNMAN_IS_MANAGER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONNMAN_TYPE_MANAGER))
#define CONNMAN_IS_MANAGER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), CONNMAN_TYPE_MANAGER))
#define CONNMAN_MANAGER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), CONNMAN_TYPE_MANAGER, ConnmanManagerClass))

G_END_DECLS


#endif /* CONNMAN_MANAGER_H_ */
