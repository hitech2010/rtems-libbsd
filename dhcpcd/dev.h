/*
 * dhcpcd - DHCP client daemon
 * Copyright (c) 2006-2013 Roy Marples <roy@marples.name>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef DEV_H
#define DEV_H

// dev plugin setup
struct dev {
	const char *name;
	int (*initialized)(const char *);
	int (*listening)(void);
	int (*handle_device)(void);
	int (*start)(void);
	void (*stop)(void);
};

struct dev_dhcpcd {
	void (*handle_interface)(int, const char *);
};

int dev_init(struct dev *, const struct dev_dhcpcd *);

// hooks for dhcpcd
#ifdef PLUGIN_DEV
int dev_initialized(const char *);
int dev_listening(void);
int dev_start(const char *);
void dev_stop(void);
#else
#define dev_initialized(a) 1
#define dev_listening() 0
#define dev_start(a) {}
#define dev_stop() {}
#endif

#endif
