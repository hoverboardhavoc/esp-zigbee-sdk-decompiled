/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_asso_rsp_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void prepare_asso_rsp_msg(undefined2 *param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined1 auStack_40 [2];
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  auStack_40[0] = 3;
  uStack_3e = *param_1;
  uStack_3c = param_1[1];
  uStack_3a = param_1[2];
  uStack_38 = param_1[3];
  uStack_36 = 3;
  uStack_34 = *param_3;
  uStack_32 = param_3[1];
  uStack_30 = param_3[2];
  uStack_2e = param_3[3];
  uStack_44 = param_1[5];
  uStack_42 = uStack_44;
  uVar1 = mac_frame_write_hdr(&uStack_2c,auStack_40,&uStack_44,0,2);
  iVar2 = zmsg_append_bytes(param_2,uVar1,&uStack_2c);
  if (iVar2 == 0) {
    uStack_46 = param_3[4];
    iVar2 = zmsg_append_bytes(param_2,2,&uStack_46);
    if (iVar2 == 0) {
      uStack_46 = CONCAT11(uStack_46._1_1_,*(undefined1 *)(param_3 + 5));
      zmsg_append_bytes(param_2,1,&uStack_46);
    }
  }
  return;
}

