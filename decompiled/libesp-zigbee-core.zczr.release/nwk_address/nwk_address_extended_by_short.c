/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_extended_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_extended_by_short(ezb_shortaddr_t shortaddr,ezb_extaddr_t *extaddr)

{
  ezb_err_t eVar1;
  nwk_addr_ref_t anStack_12 [2];
  nwk_addr_ref_t ref;
  
  eVar1 = nwk_address_ref_by_short(shortaddr,anStack_12);
  if ((eVar1 == 0) &&
     ((eVar1 = nwk_address_extended_by_ref(anStack_12[0],extaddr), eVar1 != 0 ||
      ((eVar1 = 0,
       *(int *)((int)&extaddr->field_0 + 4) + 1U == (uint)(*(int *)&extaddr->field_0 == 0) &&
       (0xfffffffd < *(int *)&extaddr->field_0 - 1U)))))) {
    eVar1 = 5;
  }
  return eVar1;
}

