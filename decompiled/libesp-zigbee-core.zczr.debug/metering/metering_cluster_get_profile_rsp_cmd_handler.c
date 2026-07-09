/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_profile_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void metering_cluster_get_profile_rsp_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_18;
  uint uStack_14;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pvStack_18 = (void *)0x0;
  uStack_14 = 0;
  uStack_36 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x1d8,
                  "metering_cluster_get_profile_rsp_cmd_handler","packet && rsp");
  }
  else {
    iVar1 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_36,&uStack_28);
    if (iVar1 == 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,&uStack_24);
  if (iVar1 == 0) {
    uVar2 = 0x80;
  }
  else {
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,&uStack_20);
    if (iVar1 == 0) {
      uVar2 = 0x80;
    }
    else {
      iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_36,&uStack_1c);
      if (iVar1 == 0) {
        uVar2 = 0x80;
      }
      else {
        iVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uVar2 = uStack_1c & 0xff;
        if (iVar1 < (int)((uint)uStack_36 + uVar2 * 3)) {
          uVar2 = 0x80;
        }
        else {
          if (uVar2 != 0) {
            pvStack_18 = calloc(uVar2,4);
            if (pvStack_18 == (void *)0x0) {
              uVar2 = 0x89;
              goto _L0;
            }
            for (uVar2 = 0; uVar2 < (uStack_1c & 0xff); uVar2 = uVar2 + 1 & 0xff) {
              iVar1 = zcl_packet_read_variable_attr_value
                                (*(undefined4 *)(param_1 + 0x24),&uStack_36,0x22,
                                 (void *)(uVar2 * 4 + (int)pvStack_18));
              if (iVar1 == 0) {
                uVar2 = 0x80;
                goto _L0;
              }
            }
          }
          uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar2 < uStack_36) {
            uVar2 = 0x80;
          }
          else {
            uVar2 = zcl_packet_to_message(&uStack_34,param_1);
            if (uVar2 == 0) {
              uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
              iStack_2c = param_1;
              zcl_core_action_schedule(0x44,&uStack_34);
              if ((uStack_14 & 0xff) != 0xfe) {
                uVar2 = uStack_14 & 0xff;
              }
            }
          }
        }
      }
    }
  }
_L0:
  if (pvStack_18 != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

