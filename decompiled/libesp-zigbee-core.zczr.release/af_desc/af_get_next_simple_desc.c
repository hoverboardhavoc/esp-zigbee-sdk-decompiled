/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_get_next_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_get_next_simple_desc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    iVar2 = core_globals_get();
    uVar1 = 0;
    if (*(int *)(iVar2 + 0xc9c) != 0) {
      for (; uVar1 < s_ep_num_on_dev; uVar1 = uVar1 + 1 & 0xff) {
        iVar2 = core_globals_get();
        if (*(int *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) != 0) {
          iVar2 = core_globals_get();
          puVar4 = (undefined4 *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4);
          goto _L0;
        }
      }
    }
  }
  else {
    uVar1 = 0;
    do {
      if (s_ep_num_on_dev <= uVar1) {
        return 0;
      }
      iVar2 = core_globals_get();
      iVar3 = uVar1 * 4;
      uVar1 = uVar1 + 1 & 0xff;
    } while (*(int *)(*(int *)(iVar2 + 0xc9c) + iVar3) != param_1);
    for (; uVar1 < s_ep_num_on_dev; uVar1 = uVar1 + 1 & 0xff) {
      iVar2 = core_globals_get();
      if (*(int *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) != 0) {
        iVar2 = core_globals_get();
        puVar4 = (undefined4 *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4);
_L0:
        return *puVar4;
      }
    }
  }
  return 0;
}

