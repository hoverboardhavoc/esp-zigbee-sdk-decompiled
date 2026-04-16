/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_get_next_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010ca0) */
/* WARNING: Removing unreachable block (ram,0x00010cb2) */
/* WARNING: Removing unreachable block (ram,0x00010cc6) */
/* WARNING: Removing unreachable block (ram,0x00010c98) */
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
      if ((*(int *)(iVar2 + 0xd04) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xd04) != 0)) {
        iVar2 = core_globals_get();
        return (af_ep_desc_t *)**(undefined4 **)(iVar2 + 0xd04);
      }
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
    while (!bVar1) {
      iVar2 = core_globals_get();
      if ((*(int *)(iVar2 + 0xd04) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xd04) != 0)) {
        iVar2 = core_globals_get();
        for (paVar3 = (af_ep_desc_t *)**(undefined4 **)(iVar2 + 0xd04);
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

