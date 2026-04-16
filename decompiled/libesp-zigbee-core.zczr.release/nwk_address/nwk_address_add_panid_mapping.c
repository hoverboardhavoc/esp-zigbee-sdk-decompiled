/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_add_panid_mapping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_panid_ref_t nwk_address_add_panid_mapping(ezb_panid_t panid,ezb_extpanid_t *ext_panid)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  nwk_panid_ref_t nVar5;
  _Bool _Var6;
  int iVar7;
  undefined3 extraout_var;
  uint uVar8;
  undefined3 extraout_var_00;
  int iVar9;
  
  iVar7 = core_globals_get();
  nVar5 = nwk_address_get_panid_ref(ext_panid);
  uVar8 = CONCAT31(extraout_var,nVar5);
  if (0xf < uVar8) {
    do {
      uVar8 = bitmap_find_first_zero_bit((bitmap_t *)(iVar7 + 0xc48),0x10);
      if (0xf < uVar8) {
        if (0xf < (uVar8 & 0xff)) {
          uVar8 = 0xff;
          goto _L0;
        }
        break;
      }
      _Var6 = test_and_set_bitmap(uVar8,(bitmap_t *)(iVar7 + 0xc48));
    } while (CONCAT31(extraout_var_00,_Var6) != 0);
    uVar8 = uVar8 & 0xff;
    puVar1 = (undefined4 *)((int)&ext_panid->field_0 + 4);
    uVar2 = *(undefined2 *)puVar1;
    uVar3 = *(undefined4 *)&ext_panid->field_0;
    uVar4 = *puVar1;
    iVar9 = iVar7 + 0x1000 + uVar8 * 10;
    *(undefined2 *)(iVar9 + -0x458) = *(undefined2 *)&ext_panid->field_0;
    *(short *)(iVar9 + -0x456) = (short)((uint)uVar3 >> 0x10);
    *(undefined2 *)(iVar9 + -0x454) = uVar2;
    *(short *)(iVar9 + -0x452) = (short)((uint)uVar4 >> 0x10);
  }
  *(ezb_panid_t *)(iVar7 + uVar8 * 10 + 0xbb0) = panid;
_L0:
  return (nwk_panid_ref_t)uVar8;
}

