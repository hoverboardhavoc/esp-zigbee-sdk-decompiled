/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_add_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_add_simple_desc(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 2;
  }
  else {
    for (uVar1 = 0; uVar2 = af_dev_get_max_endpoint_num(), uVar1 < uVar2; uVar1 = uVar1 + 1 & 0xff)
    {
      iVar3 = core_globals_get();
      if (*(int *)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4) == 0) {
        iVar3 = core_globals_get();
        *(int *)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4) = param_1;
        return 0;
      }
    }
    uVar4 = 5;
  }
  return uVar4;
}

