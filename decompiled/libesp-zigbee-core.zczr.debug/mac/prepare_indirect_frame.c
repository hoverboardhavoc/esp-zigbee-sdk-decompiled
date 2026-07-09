/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_indirect_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void prepare_indirect_frame(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
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
  
  iVar2 = zmsg_queue_get_head(param_1 + 0x54);
  if (iVar2 != 0) {
    txframe_from_zmsg(param_2);
    return;
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
  mac_frame_parse_header(&puStack_58,uVar3,pcVar4);
  return;
}

