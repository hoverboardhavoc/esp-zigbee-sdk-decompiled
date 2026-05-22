/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_indirect_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t prepare_indirect_frame(mac_device *dev,ezb_radio_frame_t *tx_frame)

{
  undefined1 uVar1;
  zmsg_t *msg;
  ezb_err_t eVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  msg = (zmsg_t *)zmsg_queue_get_head(&(dev->ctx).itx_q);
  if (msg != (zmsg_t *)0x0) {
    eVar2 = txframe_from_zmsg(msg,tx_frame);
    return eVar2;
  }
  pcVar4 = "prepare_indirect_frame";
  uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x1ee,
                        "prepare_indirect_frame","msg != ((void *)0)");
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  puStack_58 = &uStack_3c;
  uVar1 = zmsg_read_bytes(0,0x1a);
  uStack_54 = CONCAT31(uStack_54._1_3_,uVar1);
  eVar2 = mac_frame_parse_header(&puStack_58,uVar3,pcVar4);
  return eVar2;
}

