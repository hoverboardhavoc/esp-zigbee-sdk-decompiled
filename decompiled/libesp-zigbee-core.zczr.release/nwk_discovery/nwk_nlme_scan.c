/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_nlme_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_nlme_scan(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = core_globals_get();
  uVar2 = 3;
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    iVar1 = core_globals_get(3);
    *(undefined1 *)(iVar1 + 0xac0) = 1;
    iVar1 = core_globals_get();
    memcpy((void *)(iVar1 + 0xac8),param_1,0x10);
    local_20 = (uint)*(byte *)((int)param_1 + 1) << 8;
    uStack_1c = *(undefined4 *)(param_1 + 2);
    if ((char)*param_1 == '\0') {
      pcStack_18 = nwk_nlme_ed_scan_callback;
    }
    else {
      if ((char)*param_1 != '\x01') {
        return 2;
      }
      local_20 = (uint)*param_1;
      pcStack_18 = nwk_nlme_active_scan_callback;
    }
    uStack_14 = *(undefined4 *)(param_1 + 6);
    uVar2 = nwk_mm_scan_request(0,&local_20);
  }
  return uVar2;
}

