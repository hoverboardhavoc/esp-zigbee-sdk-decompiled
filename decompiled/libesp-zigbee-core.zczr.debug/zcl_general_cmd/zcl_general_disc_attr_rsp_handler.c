/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_disc_attr_rsp_handler(int param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  uint unaff_s5;
  ushort uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  uint uStack_24;
  
  uStack_38 = 0;
  uStack_34 = 0;
  iStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uStack_24 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x452,
                  "zcl_general_disc_attr_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s5 = zcl_packet_to_message(&uStack_38,param_1);
    if (unaff_s5 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uStack_3a = 0;
  iStack_30 = param_1;
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_3a,&uStack_2c);
  while (uStack_3a < uVar2) {
    pvVar1 = calloc(1,8);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_3a,pvVar1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_3a,(int)pvVar1 + 2);
    *(void **)((int)pvVar1 + 4) = pvStack_28;
    pvStack_28 = pvVar1;
  }
  uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
  zcl_core_action_schedule(6,&uStack_38);
  uVar2 = uStack_24 & 0xff;
  if ((uStack_24 & 0xff) == 0xfe) {
    uVar2 = unaff_s5;
  }
_L0:
  while (pvStack_28 != (void *)0x0) {
    pvVar1 = *(void **)((int)pvStack_28 + 4);
    mm_free();
    pvStack_28 = pvVar1;
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

