/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_add_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_filter_add_lqa(ezb_extaddr_t *extaddr,uint8_t lqa)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  mac_filter_entry_t *pmVar5;
  ezb_err_t eVar6;
  undefined3 in_register_0000202d;
  
  if (extaddr == (ezb_extaddr_t *)0x0) {
    eVar6 = 2;
  }
  else if (CONCAT31(in_register_0000202d,lqa) == 0) {
    eVar6 = 2;
  }
  else {
    pmVar5 = mac_filter_find_entry(extaddr);
    if (pmVar5 == (mac_filter_entry_t *)0x0) {
      pmVar5 = mac_filter_new_entry();
      if (pmVar5 == (mac_filter_entry_t *)0x0) {
        return 1;
      }
      uVar2 = *(undefined4 *)&extaddr->field_0;
      puVar1 = (undefined4 *)((int)&extaddr->field_0 + 4);
      uVar3 = *(undefined2 *)puVar1;
      uVar4 = *puVar1;
      (pmVar5->extaddr).field_0.u8[0] = (uint8_t)*(undefined2 *)&extaddr->field_0;
      (pmVar5->extaddr).field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
      (pmVar5->extaddr).field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
      (pmVar5->extaddr).field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
      (pmVar5->extaddr).field_0.u8[4] = (uint8_t)uVar3;
      (pmVar5->extaddr).field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
      (pmVar5->extaddr).field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
      (pmVar5->extaddr).field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
    }
    pmVar5->lqa = lqa;
    eVar6 = 0;
  }
  return eVar6;
}

