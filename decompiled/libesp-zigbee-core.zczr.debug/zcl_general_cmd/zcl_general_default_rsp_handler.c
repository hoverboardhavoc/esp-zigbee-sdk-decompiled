/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_default_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_default_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  uint unaff_s2;
  ushort uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_36 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x486,
                  "zcl_general_default_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&uStack_34,param_1);
    if (unaff_s2 != 0) {
      uVar1 = 0xfe;
      goto _L0;
    }
  }
  iStack_2c = param_1;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,&uStack_28);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,(int)&uStack_28 + 1);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_36) {
    uVar1 = 0x80;
  }
  else {
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    zcl_core_action_schedule(8,&uStack_34);
    uVar1 = uStack_24 & 0xff;
    if ((uStack_24 & 0xff) == 0xfe) {
      uVar1 = unaff_s2;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

