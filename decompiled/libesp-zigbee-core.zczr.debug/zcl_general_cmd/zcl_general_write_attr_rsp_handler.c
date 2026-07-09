/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_write_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_write_attr_rsp_handler(int param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  uint unaff_s4;
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x154,
                  "zcl_general_write_attr_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s4 = zcl_packet_to_message(&uStack_34,param_1);
    if (unaff_s4 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uStack_36 = 0;
  iStack_2c = param_1;
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  while (uStack_36 < uVar2) {
    pcVar1 = (char *)calloc(1,8);
    *(char **)(pcVar1 + 4) = pcStack_28;
    pcStack_28 = pcVar1;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1);
    if (uVar2 < uStack_36) {
      uVar2 = 0x80;
      goto _L0;
    }
    if (*pcVar1 == '\0') {
      pcVar1[2] = -1;
      pcVar1[3] = -1;
    }
    else {
      af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,pcVar1 + 2);
    }
  }
  uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
  zcl_core_action_schedule(2,&uStack_34);
  uVar2 = uStack_24 & 0xff;
  if ((uStack_24 & 0xff) == 0xfe) {
    uVar2 = unaff_s4;
  }
_L0:
  if (pcStack_28 != (char *)0x0) {
    while (pcStack_28 != (char *)0x0) {
      pcVar1 = *(char **)(pcStack_28 + 4);
      mm_free();
      pcStack_28 = pcVar1;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

