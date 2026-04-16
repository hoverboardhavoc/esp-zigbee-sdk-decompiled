/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_sub_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_get_sub_device_info(uint8_t start_index,touchlink_sub_device_info_t *ep_info)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint8_t *puVar4;
  uint uVar5;
  undefined3 in_register_00002029;
  undefined4 *puVar6;
  ezb_err_t eVar7;
  
  if (ep_info == (touchlink_sub_device_info_t *)0x0) {
    eVar7 = 2;
  }
  else {
    puVar4 = (uint8_t *)0x0;
    uVar5 = 0;
    while (puVar4 = (uint8_t *)af_get_next_simple_desc(puVar4), puVar4 != (uint8_t *)0x0) {
      if (7 < uVar5) {
        return 5;
      }
      if (uVar5 == CONCAT31(in_register_00002029,start_index)) {
        puVar6 = (undefined4 *)nwk_get_extended_address();
        uVar1 = *puVar6;
        uVar2 = *(undefined3 *)(puVar6 + 1);
        uVar3 = puVar6[1];
        (ep_info->ieee_addr).field_0.u8[0] = (uint8_t)*(undefined3 *)puVar6;
        (ep_info->ieee_addr).field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
        (ep_info->ieee_addr).field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
        (ep_info->ieee_addr).field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
        (ep_info->ieee_addr).field_0.u8[4] = (uint8_t)uVar2;
        (ep_info->ieee_addr).field_0.u8[5] = (uint8_t)((uint)uVar3 >> 8);
        (ep_info->ieee_addr).field_0.u8[6] = (uint8_t)((uint)uVar3 >> 0x10);
        (ep_info->ieee_addr).field_0.u8[7] = (uint8_t)((uint)uVar3 >> 0x18);
        ep_info->ep_id = *puVar4;
        ep_info->profile_id = *(uint16_t *)(puVar4 + 2);
        ep_info->device_id = *(uint16_t *)(puVar4 + 4);
        ep_info->version = (byte)*(undefined2 *)(puVar4 + 6) & 0xf;
        ep_info->n_group_ids = '\0';
        ep_info->sort = '\0';
        return 0;
      }
      uVar5 = uVar5 + 1 & 0xff;
    }
    eVar7 = 5;
  }
  return eVar7;
}

