/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_dev_desc_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void af_dev_desc_deinit(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while (!bVar1) {
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xca0) = 0;
    bVar1 = true;
  }
  af_dev_set_max_endpoint_num('\0');
  return;
}

