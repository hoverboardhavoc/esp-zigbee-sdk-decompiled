/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_append_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_packet_append_variable_attr_value(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 extraout_a1;
  undefined4 *extraout_a1_00;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_90 [2];
  undefined2 uStack_8e;
  undefined2 uStack_8c;
  undefined2 uStack_8a;
  undefined2 uStack_88;
  undefined2 uStack_86;
  undefined2 uStack_84;
  undefined2 uStack_82;
  undefined2 uStack_80;
  undefined1 uStack_7e;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  char *pcStack_6c;
  char *pcStack_68;
  code *pcStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iVar2 = zcl_attr_type_is_composite(param_2);
  if (iVar2 == 0) {
    uVar4 = zcl_get_attr_value_size(param_2,0);
    if (0x10 < uVar4) {
      pcVar8 = "size <= sizeof(buf)";
      pcVar7 = "zcl_packet_append_variable_attr_value";
      uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x249);
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      iVar2 = zcl_attr_type_is_composite(pcVar7);
      if (iVar2 == 0) {
        uVar4 = zcl_get_attr_value_size(pcVar7,0);
        if (0x10 < uVar4) {
          pcVar1 = zcl_packet_intrp_send;
          puVar6 = (undefined1 *)
                   __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x259
                                 ,"zcl_packet_write_variable_attr_value","size <= sizeof(buf)");
          if (puVar6 == (undefined1 *)0x0) {
            uVar3 = 0x87;
          }
          else {
            pcStack_6c = pcVar8;
            pcStack_68 = pcVar7;
            pcStack_64 = pcVar1;
            zcl_frame_fill_header();
            auStack_90[0] = *puVar6;
            uStack_8e = 0xffff;
            uStack_8c = *(undefined2 *)(puVar6 + 10);
            uStack_8a = *(undefined2 *)(puVar6 + 0xc);
            uStack_88 = *(undefined2 *)(puVar6 + 0xe);
            uStack_86 = *(undefined2 *)(puVar6 + 0x10);
            uStack_84 = *(undefined2 *)(puVar6 + 0x12);
            uStack_82 = *(undefined2 *)(puVar6 + 0x18);
            uStack_80 = *(undefined2 *)(puVar6 + 0x16);
            uStack_7e = 0;
            uStack_7c = zcl_packet_transfer_ownership(puVar6);
            if (extraout_a1_00 == (undefined4 *)0x0) {
              uStack_78 = 0;
              uStack_74 = 0;
            }
            else {
              uStack_78 = *extraout_a1_00;
              uStack_74 = extraout_a1_00[1];
            }
            af_intrp_data_request(auStack_90);
            uVar3 = err_to_zcl_status();
          }
          return uVar3;
        }
        zcl_write_attr_value(&uStack_60,pcVar8,pcVar7);
        uVar3 = zmsg_write_bytes(uVar3,extraout_a1,uVar4,&uStack_60);
      }
      else {
        uVar5 = zcl_get_attr_value_size(pcVar7,pcVar8);
        uVar3 = zmsg_write_bytes(uVar3,extraout_a1,uVar5,pcVar8);
      }
      return uVar3;
    }
    zcl_write_attr_value(&local_30,param_3,param_2);
    uVar3 = zmsg_append_bytes(param_1,uVar4,&local_30);
  }
  else {
    uVar3 = zcl_get_attr_value_size(param_2,param_3);
    uVar3 = zmsg_append_bytes(param_1,uVar3,param_3);
  }
  return uVar3;
}

