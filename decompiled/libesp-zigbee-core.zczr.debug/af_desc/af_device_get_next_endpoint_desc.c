/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_get_next_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010c66) */
/* WARNING: Removing unreachable block (ram,0x00010c78) */
/* WARNING: Removing unreachable block (ram,0x00010c8c) */
/* WARNING: Removing unreachable block (ram,0x00010c5e) */
/* WARNING: Unknown calling convention */

af_ep_desc_t * af_device_get_next_endpoint_desc(af_ep_desc_t *ep_desc)

{
  bool bVar1;
  int iVar2;
  af_ep_desc_t *paVar3;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    bVar1 = false;
    while (!bVar1) {
      iVar2 = core_globals_get();
      if ((*(int *)(iVar2 + 0xca0) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xca0) != 0)) {
        iVar2 = core_globals_get();
        return (af_ep_desc_t *)**(undefined4 **)(iVar2 + 0xca0);
      }
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
    while (!bVar1) {
      iVar2 = core_globals_get();
      if ((*(int *)(iVar2 + 0xca0) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xca0) != 0)) {
        iVar2 = core_globals_get();
        for (paVar3 = (af_ep_desc_t *)**(undefined4 **)(iVar2 + 0xca0);
            paVar3 != (af_ep_desc_t *)0x0; paVar3 = paVar3->next) {
          if (paVar3 == ep_desc) {
            return paVar3->next;
          }
        }
      }
      bVar1 = true;
    }
  }
  return (af_ep_desc_t *)0x0;
}

