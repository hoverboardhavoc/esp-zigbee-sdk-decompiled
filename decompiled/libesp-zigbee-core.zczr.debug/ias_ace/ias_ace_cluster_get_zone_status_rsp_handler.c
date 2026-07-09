/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_status_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_zone_status_rsp_handler(int param_1,int param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  uint uStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  iStack_34 = 0;
  uStack_30 = 0;
  pvStack_2c = (void *)0x0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x2b1,
                  "ias_ace_cluster_get_zone_status_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_30 + 1);
    param_3 = 1;
    if (iVar1 != 1) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  pvStack_2c = calloc(param_3,(uStack_30 >> 8 & 0xff) << 2);
  if (pvStack_2c == (void *)0x0) {
    uVar2 = 0x89;
  }
  else {
    for (iVar1 = 0; iVar1 < (int)(uStack_30 >> 8 & 0xff); iVar1 = iVar1 + 1) {
      uStack_3e = 0;
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(void *)((int)pvStack_2c + iVar1 * 4));
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_3e);
      *(undefined2 *)((int)pvStack_2c + iVar1 * 4 + 2) = uStack_3e;
    }
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar2 < auStack_22[0]) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = zcl_packet_to_message(&uStack_3c,param_1);
      if (uVar2 == 0) {
        uStack_28 = CONCAT31(uStack_28._1_3_,0xfe);
        iStack_34 = param_1;
        zcl_core_action_schedule(0x2c,&uStack_3c);
        if ((uStack_28 & 0xff) != 0xfe) {
          uVar2 = uStack_28 & 0xff;
        }
      }
    }
  }
_L0:
  if (pvStack_2c != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

