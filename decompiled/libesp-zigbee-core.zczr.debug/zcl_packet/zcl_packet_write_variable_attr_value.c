/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_write_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_packet_write_variable_attr_value
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 *extraout_a1;
  undefined1 auStack_60 [2];
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined1 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  code *pcStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iVar2 = zcl_attr_type_is_composite(param_3);
  if (iVar2 == 0) {
    uVar4 = zcl_get_attr_value_size(param_3,0);
    if (0x10 < uVar4) {
      pcVar1 = zcl_packet_intrp_send;
      puVar5 = (undefined1 *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x238,
                             "zcl_packet_write_variable_attr_value","size <= sizeof(buf)");
      if (puVar5 == (undefined1 *)0x0) {
        uVar3 = 0x87;
      }
      else {
        uStack_3c = param_4;
        uStack_38 = param_3;
        pcStack_34 = pcVar1;
        zcl_frame_fill_header();
        auStack_60[0] = *puVar5;
        uStack_5e = 0xffff;
        uStack_5c = *(undefined2 *)(puVar5 + 10);
        uStack_5a = *(undefined2 *)(puVar5 + 0xc);
        uStack_58 = *(undefined2 *)(puVar5 + 0xe);
        uStack_56 = *(undefined2 *)(puVar5 + 0x10);
        uStack_54 = *(undefined2 *)(puVar5 + 0x12);
        uStack_52 = *(undefined2 *)(puVar5 + 0x18);
        uStack_50 = *(undefined2 *)(puVar5 + 0x16);
        uStack_4e = 0;
        uStack_4c = zcl_packet_transfer_ownership(puVar5);
        if (extraout_a1 == (undefined4 *)0x0) {
          uStack_48 = 0;
          uStack_44 = 0;
        }
        else {
          uStack_48 = *extraout_a1;
          uStack_44 = extraout_a1[1];
        }
        af_intrp_data_request(auStack_60);
        uVar3 = err_to_zcl_status();
      }
      return uVar3;
    }
    zcl_write_attr_value(&local_30,param_4,param_3);
    uVar3 = zmsg_write_bytes(param_1,param_2,uVar4,&local_30);
  }
  else {
    uVar3 = zcl_get_attr_value_size(param_3,param_4);
    uVar3 = zmsg_write_bytes(param_1,param_2,uVar3,param_4);
  }
  return uVar3;
}

