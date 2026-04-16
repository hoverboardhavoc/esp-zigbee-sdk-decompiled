/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_get_ep_desc
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
  paVar2 = *(af_ep_desc_t **)(iVar1 + 0xd04);
  if (paVar2 != (af_ep_desc_t *)0x0) {
    iVar1 = core_globals_get();
    paVar2 = (af_ep_desc_t *)**(undefined4 **)(iVar1 + 0xd04);
  }
  for (; (paVar2 != (af_ep_desc_t *)0x0 &&
         ((uint)paVar2->ep_id != CONCAT31(in_register_00002029,ep_id))); paVar2 = paVar2->next) {
  }
  return paVar2;
}

