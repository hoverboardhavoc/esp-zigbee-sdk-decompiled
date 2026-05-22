/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_get_next_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_simple_desc_t * af_get_next_simple_desc(af_simple_desc_t *simple_desc)

{
  uint uVar1;
  uint8_t uVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  
  if (simple_desc == (af_simple_desc_t *)0x0) {
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xc9c) == 0) {
      return (af_simple_desc_t *)0x0;
    }
    uVar1 = 0;
    while( true ) {
      uVar2 = af_dev_get_max_endpoint_num();
      if (CONCAT31(extraout_var_00,uVar2) <= uVar1) {
        return (af_simple_desc_t *)0x0;
      }
      iVar3 = core_globals_get();
      if (*(int *)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4) != 0) break;
      uVar1 = uVar1 + 1 & 0xff;
    }
    iVar3 = core_globals_get();
    return *(af_simple_desc_t **)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4);
  }
  uVar1 = 0;
  while( true ) {
    uVar2 = af_dev_get_max_endpoint_num();
    if (CONCAT31(extraout_var,uVar2) <= uVar1) {
      return (af_simple_desc_t *)0x0;
    }
    iVar3 = core_globals_get();
    if (*(af_simple_desc_t **)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4) == simple_desc) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  do {
    uVar1 = uVar1 + 1 & 0xff;
    uVar2 = af_dev_get_max_endpoint_num();
    if (CONCAT31(extraout_var_01,uVar2) <= uVar1) {
      return (af_simple_desc_t *)0x0;
    }
    iVar3 = core_globals_get();
  } while (*(int *)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4) == 0);
  iVar3 = core_globals_get();
  return *(af_simple_desc_t **)(*(int *)(iVar3 + 0xc9c) + uVar1 * 4);
}

