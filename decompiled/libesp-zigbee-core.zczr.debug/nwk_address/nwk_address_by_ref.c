/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_by_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_by_ref(nwk_addr_ref_t ref,ezb_shortaddr_t *shortaddr,ezb_extaddr_t *extaddr)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint uVar4;
  _Bool _Var5;
  undefined2 in_register_0000202a;
  int iVar6;
  undefined3 extraout_var;
  ezb_err_t eVar7;
  int iVar8;
  undefined4 *puVar9;
  
  uVar4 = CONCAT22(in_register_0000202a,ref);
  iVar6 = core_globals_get();
  iVar8 = uVar4 * 0x12 + *(int *)(iVar6 + 0xc50);
  if ((*(byte *)(iVar8 + 0x11) & 4) != 0) {
    uVar4 = (uint)*(ushort *)(iVar8 + 0xe);
  }
  _Var5 = check_table_ref((uint16_t)uVar4,*(bitmap_t **)(iVar6 + 0xc4c),*(uint16_t *)(iVar6 + 0xc54)
                         );
  if (CONCAT31(extraout_var,_Var5) == 0) {
    eVar7 = 5;
  }
  else {
    puVar9 = (undefined4 *)(*(int *)(iVar6 + 0xc50) + uVar4 * 0x12);
    if (shortaddr != (ezb_shortaddr_t *)0x0) {
      *shortaddr = *(ezb_shortaddr_t *)(puVar9 + 2);
    }
    if (extaddr == (ezb_extaddr_t *)0x0) {
      eVar7 = 0;
    }
    else {
      uVar1 = *puVar9;
      uVar2 = *(undefined3 *)(puVar9 + 1);
      uVar3 = puVar9[1];
      (extaddr->field_0).u8[0] = (uint8_t)*(undefined3 *)puVar9;
      (extaddr->field_0).u8[1] = (uint8_t)((uint)uVar1 >> 8);
      (extaddr->field_0).u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
      (extaddr->field_0).u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
      (extaddr->field_0).u8[4] = (uint8_t)uVar2;
      (extaddr->field_0).u8[5] = (uint8_t)((uint)uVar3 >> 8);
      (extaddr->field_0).u8[6] = (uint8_t)((uint)uVar3 >> 0x10);
      (extaddr->field_0).u8[7] = (uint8_t)((uint)uVar3 >> 0x18);
      eVar7 = 0;
    }
  }
  return eVar7;
}

