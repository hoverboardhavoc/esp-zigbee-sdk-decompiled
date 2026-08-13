/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_write_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_write_attr_rsp_handler(int param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint unaff_s3;
  undefined4 local_40;
  undefined4 uStack_3c;
  ushort uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined1 *puStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  puStack_28 = (undefined1 *)0x0;
  uStack_24 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x159,
                  "zcl_general_write_attr_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s3 = zcl_packet_to_message(&uStack_34,param_1);
    if (unaff_s3 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uStack_36 = 0;
  iStack_2c = param_1;
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 == 1) {
_L0:
    if (uStack_36 < uVar2) {
      uStack_3c = 0;
      local_40 = 0xffff0000;
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,&local_40);
      if (uVar2 != 1) goto _L0;
      if ((char)local_40 == '\0') goto _L0;
      uVar2 = 0x80;
    }
    else {
      uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
      zcl_core_action_schedule(2,&uStack_34);
      uVar2 = uStack_24 & 0xff;
      if ((uStack_24 & 0xff) == 0xfe) {
        uVar2 = unaff_s3;
      }
    }
    goto _L0;
  }
  if (uVar2 < 3) {
    uVar2 = 0x80;
  }
  else {
    if ((uVar2 - (((uint)((ulonglong)uVar2 * 0xaaaaaaab >> 0x20) & 0xfffffffe) + uVar2 / 3) & 0xffff
        ) == 0) goto _L0;
    uVar2 = 0x80;
  }
_L0:
  if (puStack_28 != (undefined1 *)0x0) {
    while (puStack_28 != (undefined1 *)0x0) {
      puVar1 = *(undefined1 **)(puStack_28 + 4);
      mm_free();
      puStack_28 = puVar1;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
_L0:
  af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_36,(int)&local_40 + 2);
  if ((char)local_40 != '\0') {
_L0:
    puVar1 = (undefined1 *)calloc(1,8);
    if (puVar1 == (undefined1 *)0x0) {
      uVar2 = 0x89;
      goto _L0;
    }
    *puVar1 = (char)local_40;
    puVar1[1] = local_40._1_1_;
    puVar1[2] = local_40._2_1_;
    puVar1[3] = local_40._3_1_;
    puVar1[4] = (undefined1)uStack_3c;
    puVar1[5] = uStack_3c._1_1_;
    puVar1[6] = uStack_3c._2_1_;
    puVar1[7] = uStack_3c._3_1_;
    *(undefined1 **)(puVar1 + 4) = puStack_28;
    puStack_28 = puVar1;
  }
  goto _L0;
}

