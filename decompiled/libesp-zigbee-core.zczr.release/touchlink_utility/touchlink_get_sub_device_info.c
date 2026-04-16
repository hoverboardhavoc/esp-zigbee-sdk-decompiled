/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_sub_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_get_sub_device_info(uint8_t start_index,touchlink_sub_device_info_t *ep_info)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  uint8_t *puVar5;
  undefined3 in_register_00002029;
  undefined4 *puVar6;
  uint uVar7;
  
  if (ep_info == (touchlink_sub_device_info_t *)0x0) {
    return 2;
  }
  puVar5 = (uint8_t *)0x0;
  for (uVar7 = 0;
      (puVar5 = (uint8_t *)af_get_next_simple_desc(puVar5), puVar5 != (uint8_t *)0x0 && (uVar7 != 8)
      ); uVar7 = uVar7 + 1 & 0xff) {
    if (uVar7 == CONCAT31(in_register_00002029,start_index)) {
      puVar6 = (undefined4 *)nwk_get_extended_address();
      uVar2 = *puVar6;
      uVar3 = *(undefined3 *)(puVar6 + 1);
      uVar4 = puVar6[1];
      (ep_info->ieee_addr).field_0.u8[0] = (uint8_t)*(undefined3 *)puVar6;
      (ep_info->ieee_addr).field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
      (ep_info->ieee_addr).field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
      (ep_info->ieee_addr).field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
      (ep_info->ieee_addr).field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
      (ep_info->ieee_addr).field_0.u8[4] = (uint8_t)uVar3;
      (ep_info->ieee_addr).field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
      (ep_info->ieee_addr).field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
      ep_info->ep_id = *puVar5;
      ep_info->profile_id = *(uint16_t *)(puVar5 + 2);
      ep_info->device_id = *(uint16_t *)(puVar5 + 4);
      uVar1 = *(undefined2 *)(puVar5 + 6);
      ep_info->n_group_ids = '\0';
      ep_info->sort = '\0';
      ep_info->version = (byte)uVar1 & 0xf;
      return 0;
    }
  }
  return 5;
}

