/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  if (*(char *)(iVar1 + 0x13ad) == '\x01') {
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x13c0) = 0;
  }
  touchlink_commissioning_set_task('\0');
  touchlink_commissioning_set_role(TL_COMM_ROLE_NONE,(touchlink_commissioning_callback_t)0x0);
  touchlink_disable_timer();
  return 0;
}

