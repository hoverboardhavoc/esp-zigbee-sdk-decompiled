/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_get_next_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_device_get_next_endpoint_desc(af_ep_desc_t *ep_desc)

{
  bool bVar1;
  af_ep_desc_s **ppaVar2;
  int iVar3;
  af_ep_desc_t *paVar4;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0xca0) != 0) &&
       (iVar3 = core_globals_get(), **(int **)(iVar3 + 0xca0) != 0)) {
      iVar3 = core_globals_get();
      return (af_ep_desc_t *)**(undefined4 **)(iVar3 + 0xca0);
    }
  }
  else {
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0xca0) != 0) &&
       (iVar3 = core_globals_get(), **(int **)(iVar3 + 0xca0) != 0)) {
      iVar3 = core_globals_get();
      paVar4 = (af_ep_desc_t *)**(undefined4 **)(iVar3 + 0xca0);
      while (paVar4 != (af_ep_desc_t *)0x0) {
        ppaVar2 = &paVar4->next;
        bVar1 = paVar4 == ep_desc;
        paVar4 = *ppaVar2;
        if (bVar1) {
          return *ppaVar2;
        }
      }
    }
  }
  return (af_ep_desc_t *)0x0;
}

