/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#pragma once

/***
  This file is part of systemd.

  Copyright 2010 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include "sd-bus.h"
#include "manager.h"

extern const sd_bus_vtable bus_manager_vtable[];

int bus_manager_foreach_client(Manager *m, int (*send_message)(sd_bus *bus, const char *destination, void *userdata), void *userdata);

void bus_manager_send_finished(Manager *m, usec_t firmware_usec, usec_t loader_usec, usec_t kernel_usec, usec_t initrd_usec, usec_t userspace_usec, usec_t total_usec);
void bus_manager_send_reloading(Manager *m, bool active);
