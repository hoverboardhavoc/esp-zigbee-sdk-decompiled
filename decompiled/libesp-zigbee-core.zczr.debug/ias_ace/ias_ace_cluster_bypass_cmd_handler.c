/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_bypass_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint ias_ace_cluster_bypass_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  size_t unaff_s1;
  uint uVar1;
  int iVar2;
  byte bStack_55;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  uint uStack_48;
  void *pvStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  byte *pbStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  iStack_4c = 0;
  uStack_48 = 0;
  pvStack_44 = (void *)0x0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  pbStack_30 = (byte *)0x0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xf7,
                  "ias_ace_cluster_bypass_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_48);
    unaff_s1 = uStack_48 & 0xff;
    if (unaff_s1 == 0) {
      uVar1 = 0x87;
      goto _L0;
    }
  }
  pvStack_44 = calloc(1,unaff_s1);
  if (pvStack_44 == (void *)0x0) {
    uVar1 = 0x89;
  }
  else {
    af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,unaff_s1,pvStack_44);
    iVar2 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_40,9);
    if (iVar2 == 0) {
      uVar1 = zcl_packet_to_message(&uStack_54,param_1);
      if (uVar1 == 0) {
        uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
        iStack_4c = param_1;
        zcl_core_action_schedule(0x1e,&uStack_54);
        uVar1 = uStack_34 & 0xff;
        if (uVar1 == 0xfe) {
          uVar1 = 1;
        }
        else if (uVar1 == 0) {
          *param_3 = uStack_2c;
          param_3[1] = uStack_28;
          if (pbStack_30 == (byte *)0x0) {
            uVar1 = 1;
          }
          else if ((uint)*pbStack_30 == (uStack_48 & 0xff)) {
            if (*(int *)(pbStack_30 + 4) == 0) {
              uVar1 = 1;
            }
            else {
              bStack_55 = *pbStack_30;
              iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&bStack_55);
              if (iVar2 == 0) {
                iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),*pbStack_30,
                                          *(undefined4 *)(pbStack_30 + 4));
                if (iVar2 == 0) {
                  uVar1 = zcl_packet_setup_response(param_2,param_1,7);
                }
                else {
                  uVar1 = 0x89;
                }
              }
              else {
                uVar1 = 0x89;
              }
            }
          }
          else {
            uVar1 = 1;
          }
        }
      }
    }
    else {
      uVar1 = 0x80;
    }
  }
_L0:
  if (pvStack_44 != (void *)0x0) {
    mm_free();
  }
  if (uVar1 != 0) {
    uVar1 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  }
  return uVar1;
}

