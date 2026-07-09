/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_set_node_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_set_node_desc(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (void *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    memcpy((void *)(iVar1 + 0xc88),param_1,0x10);
    uVar2 = 0;
  }
  return uVar2;
}

