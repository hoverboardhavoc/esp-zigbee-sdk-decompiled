/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_get_extpanid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_get_extpanid(nwk_panid_ref_t ref,ezb_extpanid_t *ext_panid)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  _Bool _Var6;
  undefined3 in_register_00002029;
  int iVar7;
  undefined3 extraout_var;
  
  iVar7 = core_globals_get();
  _Var6 = check_table_ref((uint16_t)CONCAT31(in_register_00002029,ref),(bitmap_t *)(iVar7 + 0xc48),
                          0x10);
  if (CONCAT31(extraout_var,_Var6) != 0) {
    iVar7 = iVar7 + 0x1000 + CONCAT31(in_register_00002029,ref) * 10;
    puVar1 = (undefined4 *)(iVar7 + -0x458);
    uVar4 = *puVar1;
    puVar2 = (undefined4 *)(iVar7 + -0x454);
    uVar3 = *(undefined2 *)puVar2;
    uVar5 = *puVar2;
    (ext_panid->field_0).u8[0] = (uint8_t)*(undefined2 *)puVar1;
    (ext_panid->field_0).u8[1] = (uint8_t)((uint)uVar4 >> 8);
    (ext_panid->field_0).u8[2] = (uint8_t)((uint)uVar4 >> 0x10);
    (ext_panid->field_0).u8[3] = (uint8_t)((uint)uVar4 >> 0x18);
    (ext_panid->field_0).u8[4] = (uint8_t)uVar3;
    (ext_panid->field_0).u8[5] = (uint8_t)((uint)uVar5 >> 8);
    (ext_panid->field_0).u8[6] = (uint8_t)((uint)uVar5 >> 0x10);
    (ext_panid->field_0).u8[7] = (uint8_t)((uint)uVar5 >> 0x18);
  }
  return;
}

