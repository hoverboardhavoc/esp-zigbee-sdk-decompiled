/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_add_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_add_simple_desc(af_simple_desc_t *desc)

{
  uint uVar1;
  int iVar2;
  
  if (desc == (af_simple_desc_t *)0x0) {
    return 2;
  }
  uVar1 = 0;
  while( true ) {
    if (s_ep_num_on_dev <= uVar1) {
      return 5;
    }
    iVar2 = core_globals_get();
    if (*(int *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = core_globals_get();
  *(af_simple_desc_t **)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) = desc;
  return 0;
}

