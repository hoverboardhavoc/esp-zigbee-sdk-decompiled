/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_simple_desc_init(void)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  int iVar2;
  void *pvVar3;
  
  uVar1 = af_dev_get_max_endpoint_num();
  iVar2 = core_globals_get();
  pvVar3 = calloc(CONCAT31(extraout_var,uVar1),4);
  *(void **)(iVar2 + 0xc9c) = pvVar3;
  iVar2 = core_globals_get();
  return (uint)(*(int *)(iVar2 + 0xc9c) == 0);
}

