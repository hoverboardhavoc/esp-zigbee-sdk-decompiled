/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_dev_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_dev_desc_init(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while (!bVar1) {
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xca0) = 0;
    bVar1 = true;
  }
  af_dev_set_max_endpoint_num(0x40);
  return 0;
}

