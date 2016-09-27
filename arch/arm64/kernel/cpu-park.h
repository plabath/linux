/*
 * cpu park routines
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#if !defined(_ARM64_CPU_PARK_H)
#define _ARM64_CPU_PARK_H

#include <asm/virt.h>

void __cpu_park(unsigned long el2_switch, unsigned long park_address);

static inline void __noreturn cpu_park(unsigned long el2_switch,
					unsigned long park_address)
{
	typeof(__cpu_park) *park_fn;

	park_fn = (void *)virt_to_phys(__cpu_park);
	park_fn(el2_switch, park_address);
	unreachable();
}

#ifdef CONFIG_KEXEC
extern bool in_crash_kexec;
#endif
#endif
