/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_leave_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_leave_indication(int param_1)

{
  log_write(3,"nwk_nlme.c","NLME-LEAVE.indication: addr(0x%016llx), rejoin(%d), remove_children(%d)"
            ,*(undefined4 *)(param_1 + 2),*(undefined4 *)(param_1 + 6),*(byte *)(param_1 + 10) & 1,
            *(byte *)(param_1 + 10) >> 1 & 1);
  return;
}

