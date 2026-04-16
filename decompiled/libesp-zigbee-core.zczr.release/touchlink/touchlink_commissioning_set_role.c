/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_set_role
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_set_role
               (touchlink_commissioning_role_t role,touchlink_commissioning_callback_t cb)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(char *)(iVar1 + 0x1401) = (char)role;
  iVar1 = core_globals_get();
  *(touchlink_commissioning_callback_t *)(iVar1 + 0x1438) = cb;
  return;
}

