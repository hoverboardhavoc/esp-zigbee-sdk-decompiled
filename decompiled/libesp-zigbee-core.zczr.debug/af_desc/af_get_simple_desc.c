/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_simple_desc_t * af_get_simple_desc(uint8_t ep_id)

{
  uint uVar1;
  int iVar2;
  uint8_t uVar3;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar4;
  
  uVar1 = 0;
  while( true ) {
    uVar3 = af_dev_get_max_endpoint_num();
    if (CONCAT31(extraout_var,uVar3) <= uVar1) {
      return (af_simple_desc_t *)0x0;
    }
    iVar4 = core_globals_get();
    iVar2 = uVar1 * 4;
    if ((*(int *)(*(int *)(iVar4 + 0xc9c) + iVar2) != 0) &&
       (iVar4 = core_globals_get(),
       (uint)**(byte **)(*(int *)(iVar4 + 0xc9c) + iVar2) == CONCAT31(in_register_00002029,ep_id)))
    break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar4 = core_globals_get();
  return *(af_simple_desc_t **)(*(int *)(iVar4 + 0xc9c) + iVar2);
}

