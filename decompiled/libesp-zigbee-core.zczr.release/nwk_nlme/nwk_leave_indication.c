/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_leave_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_leave_indication(nwk_leave_ind_t *ind)

{
  log_write(3,"nwk_nlme.c","NLME-LEAVE.indication: addr(0x%016llx), rejoin(%d), remove_children(%d)"
            ,*(undefined4 *)&(ind->device_address).field_0,
            *(undefined4 *)((int)&(ind->device_address).field_0 + 4),ind->field_0xa & 1,
            (byte)ind->field_0xa >> 1 & 1);
  return;
}

