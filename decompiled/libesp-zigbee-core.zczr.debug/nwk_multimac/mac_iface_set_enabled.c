/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> mac_iface_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_iface_set_enabled(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = core_globals_get();
  pcVar2 = (code *)**(undefined4 **)(*(int *)(iVar1 + param_1 * 0xc + 0xc84) + 4);
  iVar1 = core_globals_get();
  (*pcVar2)(*(undefined4 *)(iVar1 + param_1 * 0xc + 0xc84),param_2);
  return;
}

