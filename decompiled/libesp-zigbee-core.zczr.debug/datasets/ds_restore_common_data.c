/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_restore_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void ds_restore_common_data(void)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_56;
  undefined1 auStack_54 [10];
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined2 uStack_3d;
  undefined1 auStack_3b [7];
  undefined4 uStack_34;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  byte bStack_25;
  undefined4 uStack_24;
  undefined1 uStack_11;
  
  memset(auStack_54,0,0x44);
  uStack_56 = 0x44;
  iVar1 = ezb_plat_datasets_get(1,0,auStack_54,&uStack_56);
  ds_log(0,iVar1,1,0);
  if (iVar1 == 0) {
    iVar2 = core_globals_get();
    *(char *)(iVar2 + 0xc) = (char)auStack_54._2_2_;
    *(char *)(iVar2 + 0xd) = SUB21(auStack_54._2_2_,1);
    *(char *)(iVar2 + 0xe) = (char)auStack_54._4_4_;
    *(char *)(iVar2 + 0xf) = SUB41(auStack_54._4_4_,1);
    *(char *)(iVar2 + 0x10) = SUB41(auStack_54._4_4_,2);
    *(char *)(iVar2 + 0x11) = SUB41(auStack_54._4_4_,3);
    *(char *)(iVar2 + 0x12) = (char)auStack_54._8_2_;
    *(char *)(iVar2 + 0x13) = SUB21(auStack_54._8_2_,1);
    iVar2 = core_globals_get();
    *(uint *)(iVar2 + 8) = CONCAT22(uStack_48,uStack_4a);
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0x18) = *(byte *)(iVar2 + 0x18) & 0xef | (byte)((uStack_46 & 1) << 4);
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0x18) =
         (byte)((((uint)uStack_46 << 0x10) >> 0x11 & 1) << 5) | *(byte *)(iVar2 + 0x18) & 0xdf;
    nwk_set_panid(uStack_3d);
    nwk_set_extended_panid(auStack_3b);
    nwk_set_short_address(uStack_34 >> 8 & 0xffff);
    nwk_set_extended_address((int)&uStack_34 + 3);
    iVar2 = core_globals_get();
    *(ushort *)(iVar2 + 0x9dc) = CONCAT11(uStack_28,uStack_29);
    nwk_set_update_id(uStack_27);
    nwk_set_device_type(((CONCAT11(bStack_25,uStack_26) & 0x30) << 0x10) >> 0x14);
    nwk_set_rx_on_when_idle(((CONCAT11(bStack_25,uStack_26) & 0x40) << 0x10) >> 0x16);
    nwk_set_pan_channel((uint)bStack_25 | uStack_24 << 8);
    aps_secur_set_tc_address((int)&uStack_46 + 1);
    nwk_secur_set_key((int)&uStack_24 + 3,uStack_11);
    nwk_secur_switch_key(uStack_11);
  }
  if (iVar1 != 6) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0x116,
                "ds_restore_common_data",
                "error != ((ezb_err_t)((0x06) == 0 ? 0 : ((((EZB_ERR_CATEGORY_GENERIC) & 0xff) << 8) | ((0x06) & 0xff))))"
               );
  iVar1 = ezb_plat_datasets_delete(1,0xffffffff);
  ds_log(3,iVar1,1,0);
  if (iVar1 != 6) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0x11d,
                "ds_delete_common_data",
                "error != ((ezb_err_t)((0x06) == 0 ? 0 : ((((EZB_ERR_CATEGORY_GENERIC) & 0xff) << 8) | ((0x06) & 0xff))))"
               );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

