/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_send_confirm(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  *param_1 = 0;
  iVar1 = core_globals_get();
  aps_retrans_ent_delete(iVar1 + 0x38,param_1);
  aps_send_frame_confirm(uVar2,param_2);
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0x38);
  return;
}

