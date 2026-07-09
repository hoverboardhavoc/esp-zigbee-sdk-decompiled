/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_network_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
nwk_network_discovery(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined1 auStack_2e [2];
  undefined4 uStack_2c;
  code *pcStack_28;
  
  iVar1 = core_globals_get();
  uVar2 = 3;
  if ((*(char *)(iVar1 + 0xac0) == '\0') && (uVar2 = 2, param_2 != 0)) {
    iVar1 = core_globals_get(2);
    *(undefined1 *)(iVar1 + 0xac0) = 1;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac8) = param_3;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac9) = param_4;
    memset(auStack_2e,0,0xe);
    local_30 = 1;
    uStack_2f = (undefined1)param_2;
    pcStack_28 = nwk_active_scan_callback;
    uStack_2c = param_1;
    uVar2 = nwk_mm_scan_request(0,&local_30);
  }
  return uVar2;
}

