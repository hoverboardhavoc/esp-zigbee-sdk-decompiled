/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_get_ep_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_get_ep_desc(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  int iVar1;
  af_ep_desc_t *paVar2;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xca0) != 0) {
    iVar1 = core_globals_get();
    for (paVar2 = (af_ep_desc_t *)**(int **)(iVar1 + 0xca0); paVar2 != (af_ep_desc_t *)0x0;
        paVar2 = paVar2->next) {
      if ((uint)paVar2->ep_id == CONCAT31(in_register_00002029,ep_id)) {
        return paVar2;
      }
    }
  }
  return (af_ep_desc_t *)0x0;
}

