/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_reporting_configuration_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_read_reporting_configuration_rsp_handler(int param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint unaff_s5;
  ushort uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  char *pcStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  pcStack_28 = (char *)0x0;
  uStack_24 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x337,
                  "zcl_general_read_reporting_configuration_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s5 = zcl_packet_to_message(&uStack_34,param_1);
    if (unaff_s5 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uStack_36 = 0;
  iStack_2c = param_1;
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  while (uStack_36 < uVar2) {
    pcVar1 = (char *)calloc(1,0x20);
    *(char **)(pcVar1 + 0x18) = pcStack_28;
    pcStack_28 = pcVar1;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 1);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 2);
    if (uVar2 < uStack_36) {
      uVar2 = 0x80;
      goto _L0;
    }
    if (*pcVar1 == '\0') {
      if (pcVar1[1] == '\0') {
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 8);
        af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 10);
        af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 0xc);
        iVar3 = zcl_attr_type_is_analog(pcVar1[8]);
        if (iVar3 == 0) {
          pcVar1[0x10] = '\0';
          pcVar1[0x11] = '\0';
          pcVar1[0x12] = '\0';
          pcVar1[0x13] = '\0';
          pcVar1[0x14] = '\0';
          pcVar1[0x15] = '\0';
          pcVar1[0x16] = '\0';
          pcVar1[0x17] = '\0';
        }
        else {
          zcl_packet_read_variable_attr_value
                    (*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1[8],pcVar1 + 0x10);
        }
      }
      else {
        af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 8);
      }
    }
    else {
      pcVar1[8] = -1;
      pcVar1[9] = -1;
      memset(pcVar1 + 8,0xff,0x10);
    }
  }
  uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
  zcl_core_action_schedule(4,&uStack_34);
  uVar2 = uStack_24 & 0xff;
  if ((uStack_24 & 0xff) == 0xfe) {
    uVar2 = unaff_s5;
  }
_L0:
  if (pcStack_28 != (char *)0x0) {
    while (pcStack_28 != (char *)0x0) {
      pcVar1 = *(char **)(pcStack_28 + 0x18);
      mm_free();
      pcStack_28 = pcVar1;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

