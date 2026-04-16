/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_restore_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ds_restore_common_data(void)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_56;
  undefined1 auStack_54 [2];
  uint16_t length;
  dataset_common_data_t common_data;
  
  memset(auStack_54,0,0x44);
  uStack_56 = 0x44;
  iVar1 = ezb_plat_datasets_get(1,0,auStack_54,&uStack_56);
  ds_log('\0',iVar1,1,(void *)0x0);
  if (iVar1 == 0) {
    iVar2 = core_globals_get();
    *(char *)(iVar2 + 0xc) = (char)length;
    *(char *)(iVar2 + 0xd) = (char)(length >> 8);
    *(char *)(iVar2 + 0xe) = (char)common_data._0_4_;
    *(char *)(iVar2 + 0xf) = SUB41(common_data._0_4_,1);
    *(char *)(iVar2 + 0x10) = SUB41(common_data._0_4_,2);
    *(char *)(iVar2 + 0x11) = SUB41(common_data._0_4_,3);
    *(char *)(iVar2 + 0x12) = (char)common_data.aps_use_extpanid.field_0.u64._2_2_;
    *(char *)(iVar2 + 0x13) = (char)((ushort)common_data.aps_use_extpanid.field_0._2_2_ >> 8);
    iVar2 = core_globals_get();
    *(uint *)(iVar2 + 8) =
         CONCAT22(common_data.aps_use_extpanid.field_0.u64._6_2_,
                  common_data.aps_use_extpanid.field_0.u64._4_2_);
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0x18) =
         *(byte *)(iVar2 + 0x18) & 0xef |
         (byte)(((ushort)common_data.aps_channel_mask_list & 1) << 4);
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0x18) =
         (byte)((((uint)(ushort)common_data.aps_channel_mask_list << 0x10) >> 0x11 & 1) << 5) |
         *(byte *)(iVar2 + 0x18) & 0xdf;
    nwk_set_panid(common_data.tc_address.field_0.u64._4_2_);
    nwk_set_extended_panid((undefined1 *)((int)&common_data.tc_address.field_0 + 6));
    nwk_set_short_address((uint)common_data.extpanid.field_0.u64._3_4_ >> 8 & 0xffff);
    nwk_set_extended_address((undefined1 *)((int)&common_data.extpanid.field_0 + 6));
    iVar2 = core_globals_get();
    *(ushort *)(iVar2 + 0x9dc) =
         CONCAT11(common_data.extaddr.field_0.u8[5],common_data.extaddr.field_0.u8[4]);
    iVar2 = core_globals_get();
    *(uint8_t *)(iVar2 + 0x9df) = common_data.extaddr.field_0.u8[6];
    nwk_set_device_type(((CONCAT11((byte)common_data.nwk_manager_addr,
                                   common_data.extaddr.field_0.u8[7]) & 0x30) << 0x10) >> 0x14);
    nwk_set_rx_on_when_idle
              (((CONCAT11((byte)common_data.nwk_manager_addr,common_data.extaddr.field_0.u8[7]) &
                0x40) << 0x10) >> 0x16);
    nwk_set_pan_channel((uint)(byte)common_data.nwk_manager_addr | common_data._44_4_ << 8);
    aps_secur_set_tc_address((undefined1 *)((int)&common_data.aps_channel_mask_list + 1));
    nwk_secur_set_key(&common_data.pan_channel_mask,common_data.nwk_key[0xc]);
    nwk_secur_switch_key(common_data.nwk_key[0xc]);
  }
  if (iVar1 != 6) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/datasets.c",0x116,"ds_restore_common_data",
                0x105f8);
  iVar1 = ezb_plat_datasets_delete(1,0xffffffff);
  ds_log('\x03',iVar1,1,(void *)0x0);
  if (iVar1 != 6) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/datasets.c",0x11d,"ds_delete_common_data",
                0x105f8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

