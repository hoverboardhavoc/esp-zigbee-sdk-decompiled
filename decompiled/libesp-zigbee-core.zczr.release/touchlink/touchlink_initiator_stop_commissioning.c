/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_initiator_stop_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_initiator_stop_commissioning(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0x1401) == '\x01') {
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x1414) = 0;
  }
  touchlink_commissioning_set_task('\0');
  touchlink_commissioning_set_role(TL_COMM_ROLE_NONE,(touchlink_commissioning_callback_t)0x0);
  touchlink_disable_timer();
  return 0;
}

