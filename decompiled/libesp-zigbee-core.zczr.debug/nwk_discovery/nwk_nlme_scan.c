/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_nlme_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_nlme_scan(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 1;
    iVar1 = core_globals_get();
    uVar2 = *(undefined4 *)(param_1 + 4);
    uVar3 = *(undefined4 *)(param_1 + 8);
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(iVar1 + 0xac8) = *(undefined4 *)param_1;
    *(undefined4 *)(iVar1 + 0xacc) = uVar2;
    *(undefined4 *)(iVar1 + 0xad0) = uVar3;
    *(undefined4 *)(iVar1 + 0xad4) = uVar4;
    local_20 = (uint)(byte)param_1[1] << 8;
    uStack_1c = *(undefined4 *)(param_1 + 4);
    if (*param_1 == '\0') {
      pcStack_18 = nwk_nlme_ed_scan_callback;
      uStack_14 = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      if (*param_1 != '\x01') {
        return 2;
      }
      local_20 = CONCAT31((uint3)(byte)param_1[1],1);
      pcStack_18 = nwk_nlme_active_scan_callback;
      uStack_14 = *(undefined4 *)(param_1 + 0xc);
    }
    uVar2 = nwk_mm_scan_request(0,&local_20);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

