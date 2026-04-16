/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_get_panid_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_panid_ref_t nwk_address_get_panid_ref(ezb_extpanid_t *ext_panid)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(iVar1 + 0xc48,0x10,uVar2);
    uVar2 = uVar2 & 0xff;
    if (0xf < uVar2) break;
    iVar3 = iVar1 + 0x1000 + uVar2 * 10;
    if ((*(int *)(iVar3 + -0x458) == *(int *)&ext_panid->field_0) &&
       (*(int *)(iVar3 + -0x454) == *(int *)((int)&ext_panid->field_0 + 4))) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  if (0xf < uVar2) {
    uVar2 = 0xff;
  }
  return (nwk_panid_ref_t)uVar2;
}

