/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_direct_data_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t prepare_direct_data_frame(mac_device *dev,ezb_radio_frame_t *tx_frame)

{
  undefined1 uVar1;
  zmsg_t *pzVar2;
  ezb_err_t eVar3;
  int iVar4;
  ezb_radio_frame_t *tx_frame_00;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  pzVar2 = (zmsg_t *)zmsg_queue_get_head(&(dev->ctx).tx_q);
  if (pzVar2 != (zmsg_t *)0x0) {
    eVar3 = txframe_from_zmsg(pzVar2,tx_frame);
    return eVar3;
  }
  iVar4 = __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x1c5,"prepare_direct_data_frame",
                        "msg != ((void *)0)");
  pzVar2 = (zmsg_t *)zmsg_queue_get_head(iVar4 + 0x54);
  if (pzVar2 != (zmsg_t *)0x0) {
    eVar3 = txframe_from_zmsg(pzVar2,tx_frame_00);
    return eVar3;
  }
  pcVar6 = "prepare_indirect_frame";
  uVar5 = __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x1ee,"prepare_indirect_frame",
                        "msg != ((void *)0)");
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  puStack_68 = &uStack_4c;
  uVar1 = zmsg_read_bytes(0,0x1a);
  uStack_64 = CONCAT31(uStack_64._1_3_,uVar1);
  eVar3 = mac_frame_parse_header(&puStack_68,uVar5,pcVar6);
  return eVar3;
}

