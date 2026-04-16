/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_force_linkage
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_force_linkage(zdo_comm_linkage_t *linkage)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(zdo_comm_get_param_func_t *)(iVar1 + 0xd38) = linkage->get_param;
  *(zdo_comm_signal_handler_t *)(iVar1 + 0xd3c) = linkage->signal;
  return;
}

