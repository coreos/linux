/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Compatibility nf_conntrack_ipv4 module that depends on nf_conntrack
 * to keep kube-proxy happy.
 *
 * Copyright (c) 2018 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include <linux/module.h>
#include <linux/printk.h>
#include <net/netfilter/nf_conntrack.h>

unsigned int *pointer_to_nf_conntrack_data = &nf_conntrack_max;

static int __init nf_conntrack_ipv4_init(void) {
	pr_notice("nf_conntrack_ipv4: loaded compatibility alias for nf_conntrack\n");
	return 0;
}

static void __exit nf_conntrack_ipv4_exit(void) {}

module_init(nf_conntrack_ipv4_init);
module_exit(nf_conntrack_ipv4_exit);

MODULE_DESCRIPTION("kube-proxy compatibility wrapper for nf_conntrack.ko");
MODULE_LICENSE("GPL");
