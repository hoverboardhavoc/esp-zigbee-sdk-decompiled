/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_arm_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_ace_cluster_arm_cmd_handler(int param_1,int param_2)

{
  ushort *unaff_s1;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_31;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xd2,
                  "ias_ace_cluster_arm_cmd_handler","packet && rsp");
  }
  else {
    unaff_s1 = &uStack_12;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_24);
    iVar2 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),unaff_s1,(int)&uStack_24 + 1,9);
    if (iVar2 != 0) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,(int)&uStack_1c + 2);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_12) {
    uVar1 = 0x80;
  }
  else if ((byte)uStack_24 < 4) {
    if ((uStack_1c >> 0x10 & 0xff) == 0xff) {
      uVar1 = 0x87;
    }
    else {
      uVar1 = zcl_packet_to_message(&uStack_30,param_1);
      if (uVar1 == 0) {
        uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
        iStack_28 = param_1;
        zcl_core_action_schedule(0x1d,&uStack_30);
        uVar1 = uStack_18 & 0xff;
        if (uVar1 == 0xfe) {
          uVar1 = 1;
        }
        else if (uVar1 == 0) {
          uStack_31 = uStack_18._1_1_;
          iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_31);
          if (iVar2 == 0) {
            uVar1 = zcl_packet_setup_response(param_2,param_1,0);
            if (uVar1 == 0) {
              return 0;
            }
          }
          else {
            uVar1 = 0x89;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0x87;
  }
_L0:
  uVar3 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar3;
}

