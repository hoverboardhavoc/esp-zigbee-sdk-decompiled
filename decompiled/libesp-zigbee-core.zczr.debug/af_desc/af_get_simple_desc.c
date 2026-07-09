/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_get_simple_desc(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0;
  while( true ) {
    uVar3 = af_dev_get_max_endpoint_num();
    if (uVar3 <= uVar1) {
      return 0;
    }
    iVar4 = core_globals_get();
    iVar2 = uVar1 * 4;
    if ((*(int *)(*(int *)(iVar4 + 0xc9c) + iVar2) != 0) &&
       (iVar4 = core_globals_get(), **(byte **)(*(int *)(iVar4 + 0xc9c) + iVar2) == param_1)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar4 = core_globals_get();
  return *(undefined4 *)(*(int *)(iVar4 + 0xc9c) + iVar2);
}

