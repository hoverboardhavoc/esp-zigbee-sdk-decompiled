/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> datasets.o -> ds_save_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ds_save_common_data(void)

{
  undefined4 uVar1;
  uint3 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *__src;
  ezb_err_t error;
  void *value;
  undefined1 auStack_54 [2];
  undefined2 uStack_52;
  dataset_common_data_t common_data;
  
  memset(auStack_54,0,0x44);
  iVar3 = core_globals_get();
  uStack_52 = (undefined2)*(undefined3 *)(iVar3 + 0xc);
  common_data.aps_use_extpanid.field_0.u64._0_2_ = (undefined2)*(undefined3 *)(iVar3 + 0x10);
  common_data.version = (uint16_t)((uint)*(undefined4 *)(iVar3 + 0xc) >> 0x10);
  common_data.aps_use_extpanid.field_0.u64._2_2_ =
       (undefined2)((uint)*(undefined4 *)(iVar3 + 0x10) >> 0x10);
  iVar3 = core_globals_get();
  common_data.aps_use_extpanid.field_0.u64._4_2_ = *(undefined2 *)(iVar3 + 8);
  common_data.aps_use_extpanid.field_0.u64._6_2_ = *(undefined2 *)(iVar3 + 10);
  iVar3 = core_globals_get();
  common_data.aps_channel_mask_list._0_1_ =
       (byte)common_data.aps_channel_mask_list & 0xfe | (byte)(*(uint *)(iVar3 + 0x18) >> 4) & 1;
  iVar3 = core_globals_get();
  common_data.aps_channel_mask_list._0_1_ =
       (byte)common_data.aps_channel_mask_list & 0xfd | (byte)(*(uint *)(iVar3 + 0x18) >> 4) & 2;
  iVar3 = core_globals_get();
  common_data.tc_address.field_0.u8[4] = *(uint8_t *)(iVar3 + 0x9e4);
  common_data.tc_address.field_0.u8[5] = *(uint8_t *)(iVar3 + 0x9e5);
  iVar3 = core_globals_get();
  uVar4 = *(undefined4 *)(iVar3 + 0x9ef);
  uVar1 = *(undefined4 *)(iVar3 + 0x9f3);
  common_data.tc_address.field_0.u8[6] = (uint8_t)*(undefined3 *)(iVar3 + 0x9ef);
  common_data.tc_address.field_0.u8[7] = (uint8_t)((uint)uVar4 >> 8);
  common_data.panid._1_1_ = (undefined1)((uint)uVar4 >> 0x18);
  common_data.extpanid.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.panid._0_1_ = (undefined1)((uint)uVar4 >> 0x10);
  common_data.extpanid.field_0.u8[0] = (uint8_t)*(undefined3 *)(iVar3 + 0x9f3);
  common_data.extpanid.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.extpanid.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  iVar3 = core_globals_get();
  common_data.extpanid.field_0.u8[4] = (uint8_t)*(undefined2 *)(iVar3 + 0x9e2);
  common_data.extpanid.field_0.u8[5] = (uint8_t)((ushort)*(undefined2 *)(iVar3 + 0x9e2) >> 8);
  iVar3 = core_globals_get();
  uVar4 = *(undefined4 *)(iVar3 + 0x9e6);
  uVar1 = *(undefined4 *)(iVar3 + 0x9ea);
  common_data.extpanid.field_0.u8[6] = (uint8_t)*(undefined3 *)(iVar3 + 0x9e6);
  common_data.extpanid.field_0.u8[7] = (uint8_t)((uint)uVar4 >> 8);
  common_data.shortaddr._1_1_ = (undefined1)((uint)uVar4 >> 0x18);
  common_data.extaddr.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.shortaddr._0_1_ = (undefined1)((uint)uVar4 >> 0x10);
  common_data.extaddr.field_0.u8[0] = (uint8_t)*(undefined3 *)(iVar3 + 0x9ea);
  common_data.extaddr.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.extaddr.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  iVar3 = core_globals_get();
  common_data.extaddr.field_0.u8[4] = *(uint8_t *)(iVar3 + 0x9dc);
  common_data.extaddr.field_0.u8[5] = *(uint8_t *)(iVar3 + 0x9dd);
  iVar3 = core_globals_get();
  common_data.extaddr.field_0.u8[6] = *(uint8_t *)(iVar3 + 0x9df);
  common_data.extaddr.field_0.u8[7] = common_data.extaddr.field_0.u8[7] & 0xf0 | 2;
  iVar3 = core_globals_get();
  common_data.extaddr.field_0.u8[7] =
       common_data.extaddr.field_0.u8[7] & 0xcf | (byte)((*(uint *)(iVar3 + 0xa2c) & 3) << 4);
  iVar3 = core_globals_get();
  common_data.extaddr.field_0.u8[7] =
       common_data.extaddr.field_0.u8[7] & 0xbf | (byte)((*(byte *)(iVar3 + 0x9ee) & 1) << 6);
  uVar4 = nwk_get_pan_channel();
  common_data.nwk_manager_addr._0_1_ = (undefined1)uVar4;
  common_data.nwk_manager_addr._1_1_ = (undefined1)((uint)uVar4 >> 8);
  common_data.update_id = (uint8_t)((uint)uVar4 >> 0x10);
  common_data._46_1_ = (undefined1)((uint)uVar4 >> 0x18);
  puVar5 = (undefined4 *)aps_secur_get_tc_address();
  uVar4 = *puVar5;
  uVar2 = *(uint3 *)(puVar5 + 1);
  value = (void *)(uint)uVar2;
  uVar1 = puVar5[1];
  common_data.aps_channel_mask_list._1_1_ = (undefined1)*(undefined3 *)puVar5;
  common_data.aps_channel_mask_list._2_1_ = (undefined1)((uint)uVar4 >> 8);
  common_data._14_1_ = (undefined1)((uint)uVar4 >> 0x18);
  common_data.tc_address.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.tc_address.field_0.u8[0] = (uint8_t)uVar2;
  common_data.tc_address.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.tc_address.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  common_data.aps_channel_mask_list._3_1_ = (undefined1)((uint)uVar4 >> 0x10);
  common_data.nwk_key[0xc] = nwk_secur_get_current_key_seq();
  __src = (void *)nwk_secur_get_key_by_seq();
  memcpy(&common_data.pan_channel_mask,__src,0x10);
  error = ezb_plat_datasets_set(1,auStack_54,0x44);
  ds_log('\x01',error,1,value);
  if (error != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

