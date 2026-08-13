/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_frame_fill_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_frame_fill_header(int param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined2 extraout_a1;
  char *pcVar8;
  undefined2 uStack_42;
  uint auStack_40 [5];
  undefined4 uStack_2c;
  int iStack_28;
  code *pcStack_24;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  if ((*(byte *)(param_1 + 0x1a) & 4) == 0) {
    uVar3 = 3;
  }
  else {
    uVar3 = 5;
  }
  if ((*(byte *)(param_1 + 0x1a) & 0x20) == 0) {
    uVar4 = zcl_generate_tsn();
    *(undefined1 *)(param_1 + 0x1e) = uVar4;
  }
  bVar1 = *(byte *)(param_1 + 0x1a);
  *(byte *)(param_1 + 0x1a) = bVar1 & 0xdf;
  if ((bVar1 & 4) == 0) {
    uStack_18 = CONCAT13(uStack_18._3_1_,
                         CONCAT12(*(undefined1 *)(param_1 + 0x20),
                                  CONCAT11(*(undefined1 *)(param_1 + 0x1e),bVar1)));
  }
  else {
    uStack_18 = CONCAT13(*(undefined1 *)(param_1 + 0x1e),
                         CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0x1c) >> 8),
                                  CONCAT11((char)*(undefined2 *)(param_1 + 0x1c),bVar1)));
    uStack_14 = *(undefined1 *)(param_1 + 0x20);
  }
  uStack_18 = uStack_18 & 0xffffffdf;
  iVar5 = zmsg_prepend_bytes(*(undefined4 *)(param_1 + 0x24),uVar3,&uStack_18);
  if (iVar5 == 0) {
    return (uint)*(byte *)(param_1 + 0x1e);
  }
  pcVar8 = "zcl_frame_fill_header";
  pcVar2 = zcl_packet_read_variable_attr_actual_size;
  uVar6 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x17f,
                        "zmsg_prepend_bytes(packet->payload, length, buffer) == 0");
  auStack_40[0] = 0;
  auStack_40[1] = 0;
  auStack_40[2] = 0;
  auStack_40[3] = 0;
  uStack_42 = extraout_a1;
  uStack_2c = uVar3;
  iStack_28 = param_1;
  pcStack_24 = pcVar2;
  iVar5 = zcl_attr_type_is_composite(pcVar8);
  if (iVar5 == 0) {
    uVar7 = zcl_get_attr_value_size(pcVar8,0);
  }
  else if (((uint)(pcVar8 + -0x41) & 0xff) < 2) {
    af_read_bytes(uVar6,&uStack_42,1,auStack_40);
    uVar7 = (auStack_40[0] & 0xff) + 1;
  }
  else if (((uint)(pcVar8 + -0x43) & 0xff) < 2) {
    af_read_bytes(uVar6,&uStack_42,2,auStack_40);
    uVar7 = (auStack_40[0] & 0xffff) + 2 & 0xffff;
  }
  else if (pcVar8 == (char *)0x49) {
    af_read_bytes(uVar6,&uStack_42,2,auStack_40);
    uVar7 = ((auStack_40[0] & 0xffff) + 1) * 0x20000 >> 0x10;
  }
  else if (pcVar8 == (char *)0x4a) {
    af_read_bytes(uVar6,&uStack_42,2,auStack_40);
    uVar7 = ((auStack_40[0] << 0x12) >> 0x10) + 2 & 0xffff;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}

