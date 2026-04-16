/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> oui_table_set_oui
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_oui_ref_t oui_table_set_oui(uint8_t (*oui) [3])

{
  uint8_t *puVar1;
  nwk_oui_ref_t nVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  
  iVar3 = core_globals_get();
  nVar2 = get_oui_ref((nwk_oui_table_t *)(iVar3 + 0xc4a),oui);
  uVar4 = CONCAT31(extraout_var,nVar2);
  if (uVar4 < 0x20) {
_L0:
    if (0x1f < uVar4) goto _L0;
  }
  else {
    uVar4 = bitmap_find_first_zero_bit(iVar3 + 0xcaa,0x20);
    uVar4 = uVar4 & 0xff;
    if (0x1f < uVar4) {
      oui_table_clear_unused_entries();
      uVar4 = bitmap_find_first_zero_bit(iVar3 + 0xcaa,0x20);
      uVar4 = uVar4 & 0xff;
      goto _L0;
    }
  }
  test_and_set_bitmap(uVar4,(bitmap_t *)(iVar3 + 0xcaa));
  puVar1 = (uint8_t *)(iVar3 + 0xc4a + uVar4 * 3);
  *puVar1 = (*oui)[0];
  puVar1[1] = (*oui)[1];
  puVar1[2] = (*oui)[2];
_L0:
  return (nwk_oui_ref_t)uVar4;
}

