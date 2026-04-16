/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_save_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Variable defined which should be unmapped: common_data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ds_save_common_data(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *__src;
  undefined1 auStack_54 [2];
  undefined2 uStack_52;
  dataset_common_data_t common_data;
  
  memset(auStack_54,0,0x44);
  iVar2 = core_globals_get();
  uStack_52 = (undefined2)*(undefined3 *)(iVar2 + 0xc);
  common_data.version = (uint16_t)((uint)*(undefined4 *)(iVar2 + 0xc) >> 0x10);
  common_data.aps_use_extpanid.field_0.u64._0_2_ = (undefined2)*(undefined3 *)(iVar2 + 0x10);
  common_data.aps_use_extpanid.field_0.u64._2_2_ =
       (undefined2)((uint)*(undefined4 *)(iVar2 + 0x10) >> 0x10);
  iVar2 = core_globals_get();
  common_data.aps_use_extpanid.field_0.u64._4_2_ = (undefined2)*(undefined4 *)(iVar2 + 8);
  common_data.aps_use_extpanid.field_0.u64._6_2_ =
       (undefined2)((uint)*(undefined4 *)(iVar2 + 8) >> 0x10);
  iVar2 = core_globals_get();
  common_data.aps_channel_mask_list._0_1_ =
       (byte)common_data.aps_channel_mask_list & 0xfe | (byte)(*(uint *)(iVar2 + 0x18) >> 4) & 1;
  iVar2 = core_globals_get();
  common_data.aps_channel_mask_list._0_1_ =
       (byte)((*(uint *)(iVar2 + 0x18) >> 5 & 1) << 1) |
       (byte)common_data.aps_channel_mask_list & 0xfd;
  iVar2 = core_globals_get();
  common_data.tc_address.field_0.u8[4] = (uint8_t)*(undefined2 *)(iVar2 + 0x9e4);
  common_data.tc_address.field_0.u8[5] = (uint8_t)((ushort)*(undefined2 *)(iVar2 + 0x9e4) >> 8);
  iVar2 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar2 + 0x9ef);
  uVar1 = *(undefined4 *)(iVar2 + 0x9f3);
  common_data.tc_address.field_0.u8[6] = (uint8_t)*(undefined3 *)(iVar2 + 0x9ef);
  common_data.tc_address.field_0.u8[7] = (uint8_t)((uint)uVar3 >> 8);
  common_data.panid._0_1_ = (undefined1)((uint)uVar3 >> 0x10);
  common_data.panid._1_1_ = (undefined1)((uint)uVar3 >> 0x18);
  common_data.extpanid.field_0.u8[0] = (uint8_t)*(undefined3 *)(iVar2 + 0x9f3);
  common_data.extpanid.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.extpanid.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.extpanid.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  iVar2 = core_globals_get();
  common_data.extpanid.field_0.u8[4] = (uint8_t)*(undefined2 *)(iVar2 + 0x9e2);
  common_data.extpanid.field_0.u8[5] = (uint8_t)((ushort)*(undefined2 *)(iVar2 + 0x9e2) >> 8);
  iVar2 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar2 + 0x9e6);
  uVar1 = *(undefined4 *)(iVar2 + 0x9ea);
  common_data.extpanid.field_0.u8[6] = (uint8_t)*(undefined3 *)(iVar2 + 0x9e6);
  common_data.extpanid.field_0.u8[7] = (uint8_t)((uint)uVar3 >> 8);
  common_data.shortaddr._0_1_ = (undefined1)((uint)uVar3 >> 0x10);
  common_data.shortaddr._1_1_ = (undefined1)((uint)uVar3 >> 0x18);
  common_data.extaddr.field_0.u8[0] = (uint8_t)*(undefined3 *)(iVar2 + 0x9ea);
  common_data.extaddr.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.extaddr.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.extaddr.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  iVar2 = core_globals_get();
  common_data.extaddr.field_0.u8[4] = (uint8_t)*(undefined2 *)(iVar2 + 0x9dc);
  common_data.extaddr.field_0.u8[5] = (uint8_t)((ushort)*(undefined2 *)(iVar2 + 0x9dc) >> 8);
  iVar2 = core_globals_get();
  common_data.extaddr.field_0.u8[6] = *(uint8_t *)(iVar2 + 0x9df);
  common_data.extaddr.field_0.u8[7] = common_data.extaddr.field_0.u8[7] & 0xf0 | 2;
  iVar2 = core_globals_get();
  common_data.extaddr.field_0.u8[7] =
       common_data.extaddr.field_0.u8[7] & 0xcf | (byte)((*(uint *)(iVar2 + 0xa2c) & 3) << 4);
  iVar2 = core_globals_get();
  common_data.extaddr.field_0.u8[7] =
       common_data.extaddr.field_0.u8[7] & 0xbf | (byte)((*(byte *)(iVar2 + 0x9ee) & 1) << 6);
  uVar3 = nwk_get_pan_channel();
  common_data.nwk_manager_addr._0_1_ = (undefined1)uVar3;
  common_data.nwk_manager_addr._1_1_ = (undefined1)((uint)uVar3 >> 8);
  common_data.update_id = (uint8_t)((uint)uVar3 >> 0x10);
  common_data._46_1_ = (undefined1)((uint)uVar3 >> 0x18);
  puVar4 = (undefined4 *)aps_secur_get_tc_address();
  uVar3 = *puVar4;
  uVar1 = puVar4[1];
  common_data.aps_channel_mask_list._1_1_ = (undefined1)*(undefined3 *)puVar4;
  common_data.aps_channel_mask_list._2_1_ = (undefined1)((uint)uVar3 >> 8);
  common_data.aps_channel_mask_list._3_1_ = (undefined1)((uint)uVar3 >> 0x10);
  common_data._14_1_ = (undefined1)((uint)uVar3 >> 0x18);
  common_data.tc_address.field_0.u8[0] = (uint8_t)*(undefined3 *)(puVar4 + 1);
  common_data.tc_address.field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
  common_data.tc_address.field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  common_data.tc_address.field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  common_data.nwk_key[0xc] = nwk_secur_get_current_key_seq();
  __src = (void *)nwk_secur_get_key_by_seq();
  memcpy(&common_data.pan_channel_mask,__src,0x10);
  iVar2 = ezb_plat_datasets_set(1,auStack_54,0x44);
  ds_log('\x01',iVar2,1,(void *)0x0);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/datasets.c",0xee,"ds_save_common_data",
                "(error) == 0");
  tp = 0xffff9000;
                    /* WARNING: Call to offcut address within same function */
  func_0x00010416();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

