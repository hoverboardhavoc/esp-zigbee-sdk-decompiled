/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_cluster_srv_write_attr_hook(int param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *param_2;
  iVar2 = identify_timer_ctx_get();
  if (param_1 == 0) {
    if (sVar1 == 0) {
      milli_timer_stop(iVar2 + 4);
    }
    else {
      milli_timer_start(iVar2 + 4,1000);
    }
  }
  return;
}

